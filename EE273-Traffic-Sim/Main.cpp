

#include <iostream>
#include <utility>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Vehicle.h"
#include "Roads.h"
#include "Junction.h"
#include "Signal.h"

#include "UI.h"

int main()
{
	Grids Grid;
	SimulationEngine* Engine = new SimulationEngine(&Grid);
	std::vector<std::vector<std::string>> GridDesigns;
	SetDesigns(GridDesigns);
	bool GridDisplay=true,DataDisplay=true; // ensures when simulation starts, both displays are on
	

	while (true) {
		SimPrint(Grid, *Engine, GridDesigns, GridDisplay, DataDisplay);
		int choice = PrintUI();

		switch (choice) {
		case(0): { // Exit simulation, similar approach as Lab 7 Ex2
			std::cout << "Exited";
			delete Engine; // free up previously allocated memory
			return 0;

		}
		case(1): {//Create Road
			std::pair<int,int> p1, p2;
			p1 = ui_ask_question("What X coordinate would you like the road to begin at?", "What Y coordinate would you like the road to begin at? ", Grids::grid_size-1, 0);
			p2 = ui_ask_question("What X coordinate would you like the road to end at?", "What Y coordinate would you like the road to end at? ", Grids::grid_size-1, 0);
			int SL = ui_ask_question("What would you like the speed limit to be",10, 1);
			Grid.CreateRoad(p1.first, p1.second, p2.first, p2.second, SL);
			break;
		}
		case(2): {//Create Vehicle
			std::pair<int, int> p;
			p = ui_ask_question("What X coordinate would you like to place a Vehicle at? ", "What Y coordinate would you like to place a Vehicle at? ", Grids::grid_size - 1, 0);
			bool HV = ui_is_road_vertical_or_horizontal(p.first, p.second, Grid);
			bool AorB;
			std::string direction;
		
			if (HV) {
				while (true) {
					direction = ui_get_string("Would you like the Vehicle placed in the Lane going North or South? (Case sensitive)");
					if (direction == "North" || direction == "South") {
						break;
					}
					else {
						std::cout << "Invalid input please try again, ";
					}
				
					}
					if (direction == "North") {
						AorB = true;
					}
					else {
						AorB = false;
					}
				
				}
				
			else {
				while (true) {
					direction = ui_get_string("Would you like the Vehicle placed in the Lane going East or West? (Case sensitive)");
					if (direction == "East" || direction == "West") {
						break;
					}
					else {
						std::cout << "Invalid input please try again, ";
					}
				}
				if (direction == "East") {
					AorB = true;
				}
				else {
					AorB = false;
				}
			}
			type t;
		
			std::cout << "Please Select a Car type: " << std::endl
				<< "1. Car" << std::endl
				<< "2. Bus" << std::endl
				<< "3. Bike" << std::endl;
					
				int choice = ui_get_int_in_range(3, 1);
				switch (choice) {

				case(1): {
					t = car;
					break;
				}
				case(2): {
					t = bus;
					break;
				}
				case(3): {
					t = bike;
					break;
				}
				}
				Grid.CreateVehicle(p.first, p.second, t, AorB);
				break;
		}
		case(3): {//Add Traffic Signal

			if (Grid.getRoads().empty()) {

				std::cout << "No roads in this system. Place a road then try again." << std::endl;
				break;		// break out of ui switch, go to main menu

			}

			std::pair<int, int> p;
			std::vector<bool> seqVector;
			int seqLength = 0;
			junction jt = unassigned;
			int qnty = 1;
	
			// x and y input validation
			while (true) {

				p = ui_ask_question("What X coordinate would you like to place a Signal at? Note that it must be on a road or junction which isn't a turn. ", "What Y coordinate would you like to place a Signal at? ", Grids::grid_size - 1, 0);


				// search vector of junctions on grid for coordinates matching the user's selection
				for (int n = 0; n < Grid.getJunctions().size(); n++) {
					if (p.first == Grid.getJunctions().at(n)->getX() && p.second == Grid.getJunctions().at(n)->getY()) {
					
						// executes if there is a junction at the selected grid space
						jt = Grid.getJunctions().at(n)->getJunctionType();
						break;		// break for loop
					}
					else
						jt = roads;
				}
				bool quit = false;
				switch (Grid.getRoadsGrid(p.first, p.second).RoadA->getDirection()) {
				case(North): {
					if (!Grid.getRoadsGrid(p.first, p.second + 1).RoadA->isRoad() || !Grid.getRoadsGrid(p.first, p.second - 1).RoadA->isRoad()) {
						
						std::cout << "Please leave a gap between signals and Juncitons, Signal Not Created" << std::endl;
						goto main_menu;
					

					}
					break;
				}
				case(East): {
					if (!Grid.getRoadsGrid(p.first + 1, p.second).RoadA->isRoad() || !Grid.getRoadsGrid(p.first - 1, p.second).RoadA->isRoad()) {
						std::cout << "Please leave a gap between signals and Juncitons, Signal Not Created" << std::endl;
						goto main_menu;
						

					}
					break;
				}
				}
				
				// show error if there is a turn or no road at all
				if (Grid.getRoadsGrid(p.first, p.second).RoadA == nullptr || jt == turn) {

					std::cout << "No valid road/junction at this location, please try again." << std::endl;
				}
				else {

					if (!Grid.getRoadsGrid(p.first, p.second).signals.empty()) {	// if the grid space already has signals on it

						std::cout << "Signal(s) already present at (" << p.first << ", " << p.second << ")." << std::endl;
						if (ui_ask_question("What would you like to do about this?\n1. Overwrite existing signal(s)\n0. Return to main menu", 1, 0)) {
							Grid.DeleteSignal(p.first, p.second);
						}
						else {
							goto main_menu;
						}
					}

					break;		// break out of input validation loop regardless of the outcome of the above if statement
				}

			}

			switch (jt) {

			case(roads):
			case(corner):
				qnty = 1;
				break;	// break out of junction type switch

			case(t):
				qnty = 3;
				break;

			case(cross):
				qnty = 4;
				break;
			}

			// get the length of the signal sequence; all signals in a junction must have the same sequence length to avoid complications
			seqLength = ui_ask_question("How long will the light sequence be? (min. 2, max. 24) ", 24, 2);

			for (int n = 0; n < qnty; n++) {
				seqVector.clear();		//clears all data in the vector so it doesn't 

				for (int m = 0; m < seqLength; m++) {

					std::cout << "Enter the light at step " << m + 1;
					seqVector.push_back(bool(ui_ask_question(" in the sequence (0 for red, 1 for green): ", 1, 0)));
				}

				Grid.CreateSignal(p.first, p.second, seqVector);
			}

			main_menu: {
			break;		// break out of ui switch, go to main menu
			}

			break;
		}
		case(4): {//Run Simulation
			int steps = ui_ask_question("How Many steps would you like the simulation to take?", 100, 1); // 100 steps isnt significant however i feel like thats a fair limit  
			for (int i = 1; i <= steps; i = i + 1) {
				Engine->step();
				SimPrint(Grid, *Engine, GridDesigns, GridDisplay, DataDisplay);
			}
			std::cout << "Simulation for " << steps << " steps complete" << std::endl;
			break;
		}
		case(5): {//Step Simulation
			Engine->step();
			std::cout << "Step complete" << std::endl;
			break;
		}
		case(6): {//Reset Simulation
			Engine->reset();
			std::cout << "Reset complete" << std::endl;
			break;
		}
		case(7): {//Delete Vehicle
			if (Grid.getVehicles().empty()) {
				std::cout << "There are no vehicles to delete." << std::endl;
			}
			else {
				ui_delete_Vehicle(Grid);
			}

			break;
		}
		case(8): {//Delete Signal
			if (Grid.getSignals().empty()) {
				std::cout << "There are no signals to delete." << std::endl;
			}
			else {
				ui_delete_Signal(Grid);
			}
			
			break;
		}
		case(9): {//Delete Road
			if (Grid.getRoads().empty()) {
				std::cout << "There are no roads to delete." << std::endl;
			}
			else {
				ui_delete_Road(Grid);
			}
			
			break;
		}
		case(10): {//Save
			ui_save(*Engine);
			break;
		}
		case(11): {//Load
			ui_load(*Engine);
			break;
		}
		case(12): {//Grid Toggle
			GridDisplay = !GridDisplay;
			std::cout << "Toggle Complete"<<std::endl;
			break;
		}
		case(13): {//Data Toggle
			DataDisplay = !DataDisplay;
			std::cout << "Toggle Complete" << std::endl;
			break;
		}
			/*	case(12);*/
		}
		ui_pause();
	}
}




