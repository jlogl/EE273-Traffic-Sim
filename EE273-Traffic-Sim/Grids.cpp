

#include"Grids.h"
#include "Direction_enum.h"

#include <iostream>

#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"

Grids::Grids() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Road_Grid[i][j] = nullptr;
				Vehicle_Grid[i][j] = nullptr; // Initially sets all cells in array to point to NULL when a instance of grids is created
		}
	}



}
Grids::~Grids() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			delete Road_Grid[i][j];
			delete Vehicle_Grid[i][j];
		}
	}
	

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
		std::cout<<std::endl;


		}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i = i + 1) {

		for (int j = 0; j < 10; j = j + 1) {
			if (Vehicle_Grid[i][j] == nullptr) {

				std::cout << "0";
			}
			else {

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

	if (number_of_lanes != 1 && number_of_lanes != 2) {
		std::cout << "Invalid number of lanes" << std::endl;
		return;

	}
	if (number_of_lanes == 1) { // creates a single lane road

		if (initial_x == final_x) { // vertical road 
			if (initial_y < final_y) { 
				for (int i = initial_y; i <= final_y; i = i + 1) {
					Roads* road_object = new Roads(initial_x, i, speed_limit,North);

					setRoadsGrid(initial_x, i, road_object);
				}
			}
			else {
				for (int i = initial_y; i >= final_y; i = i - 1) {
					Roads* road_object = new Roads(initial_x, i, speed_limit,South);

					setRoadsGrid(initial_x, i, road_object);
				}
			}

		}
		else {// horizontal road
			if (initial_x < final_x) {

				for (int i = initial_x; i <= final_x; i = i + 1) {

					Roads* road_object = new Roads(i, initial_y, speed_limit,East);

					setRoadsGrid(i, initial_y, road_object);
				}

			}
			else {
				for (int i = initial_x; i >= final_x; i = i - 1) {

					Roads* road_object = new Roads(i, initial_y, speed_limit,West);

					setRoadsGrid(i, initial_y, road_object);
				}

			}
		}
	}
	



	}


void Grids::CreateVehicle(int x, int y,type type_of_vehicle) {

	if (Road_Grid[x][y] == nullptr) {

		std::cout << "No road at coordinate " << x << "," << y << std::endl;
		return;
	}
	if (Vehicle_Grid[x][y] != nullptr) {
		std::cout<<"Vehicle already exists at coordinate " << x << "," << y << std::endl;
		return;

	}

	//Vehicle* v = new Vehicle(x,y);

	switch (type_of_vehicle) {

		case car: {
			Vehicle* car_object = new Car(x,y);
			setVehicleGrid(x,y,car_object);
			break;
		}
		case bus: {
			Vehicle*bus_object = new Bus(x,y);
			setVehicleGrid(x,y,bus_object);
			break;
		}
		case bike: {
				Vehicle* bike_object = new Bike(x,y);
			setVehicleGrid(x,y,bike_object);
			break;

		}
	}

}