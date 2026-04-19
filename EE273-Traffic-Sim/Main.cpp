

#include <iostream>
#include <utility>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Vehicle.h"

#include "UI.h"

int main()
{
	Grids Grid;
	SimulationEngine* Engine = new SimulationEngine(&Grid);
	std::vector<std::vector<std::string>> GridDesigns;
	SetDesigns(GridDesigns);
	bool GridDisplay=true,DataDisplay=true;
	

	while (true) {
		SimPrint(Grid, *Engine, GridDesigns, GridDisplay, DataDisplay);
		int choice = PrintUI();

		switch (choice) {
		case(0): { // Exit simulation, similar approach as Lab 7 Ex2
			std::cout << "Exited";
			delete Engine;
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
		case(3): {//Run Simulation
			int steps = ui_ask_question("How Many steps would you like the simulation to take?", 100, 1); // 100 steps isn't significant however i feel like that is a fair limit
			for (int i = 1; i <= steps; i = i + 1) {
				Engine->step();
				SimPrint(Grid, *Engine, GridDesigns, GridDisplay, DataDisplay);
			}
			std::cout << "Simulation for " << steps << " steps complete" << std::endl;
			break;
		}
		case(4): {//Step Simulation
			Engine->step();
			std::cout << "Step complete" << std::endl;
			break;
		}
		case(5): {//Reset Simulation
			Engine->reset();
			std::cout << "Reset complete" << std::endl;
			break;
		}
		case(6): {//Delete Vehicle
			ui_delete_Vehicle(Grid);
			break;
		}
		case(7): {//Delete Road
			ui_delete_Road(Grid);
			break;
		}
		case(8): {//Save
			ui_save(*Engine);
			break;
		}
		case(9): {//Load
			ui_load(*Engine);
			break;
		}
		case(10): {//Grid Toggle
			GridDisplay = !GridDisplay;
			std::cout << "Toggle Complete"<<std::endl;
			break;
		}
		case(11): {//Data Toggle
			DataDisplay = !DataDisplay;
			std::cout << "Toggle Complete" << std::endl;
			break;
		}
			/*	case(12);*/
		}
		ui_pause();
	}
}




