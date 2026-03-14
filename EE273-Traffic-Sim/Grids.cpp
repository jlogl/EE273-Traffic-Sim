

#include "Grids.h"
#include "SimulationEngine.h"
#include <iostream>

Grids::Grids() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Road_Grid[i][j] = nullptr;
				Vehicle_Grid[i][j] = nullptr; // Initially sets all cells in array to point to NULL when a instance of grids is created
		}
	}



}
Grids::~Grids() {
	

}
Roads* Grids::getRoadsGrid(int x, int y) {
	return Road_Grid[x][y];

};
void Grids::setRoadsGrid(int x, int y, Roads* value) {
	Road_Grid[x][y] = value;

};
Vehicle* Grids::getVehicleGrid(int x, int y) {
	return Vehicle_Grid[x][y];
};
void Grids::setVehicleGrid(int x, int y, Vehicle* value) {
	Vehicle_Grid[x][y] = value;
};

/* these getters and setters are used to interact with a single cell in each grid*/

void Grids::PrintGrids() {

	for (int i=0; i < 10; i = i + 1) {

		for (int j = 0; j < 10; j = j + 1) {
			if (Road_Grid[i][j] == nullptr) {

				std::cout << "0" ;
			}
			else{

				std::cout << "1";
			}


	}
		std::cout << std::endl;
	}

}
void Grids::CreateRoad(int initial_x, int initial_y, int final_x, int final_y, int speed_limit, int number_of_lanes) {
	if (initial_x != final_x && initial_y != final_y) {
		std::cout << "Diagonal road not supported" << std::endl;
		return;
	}
	if (initial_x == final_x && initial_y == final_y) {
		std::cout << "This isn't a road " << std::endl;
		return;
	}
	if (initial_x == final_x) {
		if (initial_y < final_y) {
			for (int i = initial_y; i <= final_y; i = i + 1) {
				Roads* road_object= new Roads(initial_x, i, speed_limit);

				setRoadsGrid(initial_x, i, road_object);
			}
		}
		else {
			for (int i = initial_y; i >= final_y; i = i - 1) {
				Roads* road_object=new Roads(initial_x, i, speed_limit);

				setRoadsGrid(initial_x, i, road_object);
			}
		}

	}
	else {
		if (initial_x < final_x) {

			for (int i = initial_x; i <= final_x; i = i + 1) {

				Roads* road_object= new Roads(i, initial_y, speed_limit);

				setRoadsGrid(i, initial_y, road_object);
			}

		}
		else {
			for (int i = initial_x; i >= final_x; i = i - 1) {

				Roads* road_object= new Roads(i, initial_y, speed_limit);

				setRoadsGrid(i, initial_y, road_object);
			}

		}
	}




}