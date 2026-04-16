

#include <iostream>
#include <vector>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Vehicle.h"
#include "Roads.h"
#include "Junction.h"
#include "ui.h"


int main()
{

	// object declarations
	Grids Grid;
	SimulationEngine* engine = new SimulationEngine(&Grid);

	// global variable declarations
	pair<int, int> ui_coord1, ui_coord2;		// start and end points for a new road, entered by user
	int ui_speedLmt;					// speed limit of a new road, entered by user
	type ui_type;						// type of vehicle
	bool ui_lane;						// A or B, used for creating a vehicle


	// Square test
	/*Grid.CreateRoad(1, 1, 1, 5, 10);
	Grid.CreateRoad(1, 1, 5, 1, 10);
	Grid.CreateRoad(1, 5, 5, 5, 10);
	Grid.CreateRoad(5, 1, 5, 5, 10);
	
	Grid.CreateVehicle(3, 1, car, 1);
	Grid.CreateVehicle(3, 5, car, 0);*/

	//T-Junction test
	/*Grid.CreateRoad(3, 2, 7, 2, 10);
	Grid.CreateRoad(3, 6, 7, 6, 10);
	Grid.CreateRoad(3, 2, 3, 6, 10);
	Grid.CreateRoad(5, 2, 5, 6, 10);
	Grid.CreateRoad(7, 2, 7, 6, 10);
	
	Grid.CreateVehicle(4, 2, car, 0);
	Grid.CreateVehicle(5, 4, bus, 1);
	Grid.CreateVehicle(5, 4, bus, 0);*/
	
	// Cross test
	/*
	Grid.CreateRoad(5, 1, 5, 7, 10);
	Grid.CreateRoad(2, 4, 8, 4, 10);
	Grid.CreateVehicle(3, 4, car, 1);
	Grid.CreateVehicle(7, 4, bus, 1);
	Grid.PrintGrids(*engine);
	*/

	//engine->save();
	//

	//

	//
	//std::vector<Junction*>& J = Grid.getJunctions();
	//int size = J.size();
	//std::cout << size << std::endl;
	//for (Junction* i : J) {

	//	std::cout << i->getX() << " " << i->getY() << " " << i->getJunctionType() << std::endl;
	//}
	
	engine->load("save.txt");
	Grid.PrintGrids(*engine);



	/* PROGRAM LOOP */
	do {
		switch (top_lvl()) {

		case 0:						// EXIT PROGRAM
			return 0;

		case 1:						// ROADS
			switch (ui_roads()) {
			case 1:						// CREATE
				ui_coord1 = start_road();
				ui_coord2 = end_road(ui_coord1);
				ui_speedLmt = ui_get_speed_lmt();

				Grid.CreateRoad(ui_coord1.first, ui_coord1.second, ui_coord2.first, ui_coord2.second, ui_speedLmt);

				ui_print("Road successfully created");

				break;

			case 2:						// DELETE
				// show options of roads
				// which road to delete? (1 to n, 0 to cancel)
				// are you sure? (y or n)

				// delete road
			case 3:						// edit road (NOT IMPLEMENTED YET)
				ui_print("unfinished\n");
			}
			break;

		case 2:						// SIGNALS
			switch (ui_signals()) {
			case 1:						// CREATE
				ui_print("unfinished\n");
			case 2:						// DELETE
				ui_print("unfinished\n");
			case 3:						// edit signal (NOT IMPLEMENTED YET)
				ui_print("unfinished\n");
			}
			break;

		case 3:						// VEHICLES
			switch (ui_vehicles()) {
			case 1:						// CREATE
				ui_type = type_vehicle();
				ui_coord1 = ui_get_pos();

				cout << "Will the vehicle use lane A?" << endl;
				ui_lane = ui_get_bool();

				Grid.CreateVehicle(ui_coord1.first, ui_coord1.second, ui_type, ui_lane);

				break;
			case 2:						// DELETE
				
			case 3:						// edit vehicle (NOT IMPLEMENTED YET)
				ui_print("unfinished\n");
			}
			break;
		case 4:						// LOAD
			break;
		case 5:						// SAVE
			break;
		}
	} while (true);
	
	delete engine;

	return 0;
}




