#include "Turn.h"
#include "Vehicle.h"
#include "Grids.h"
#include <iostream>
Turn::Turn(int x, int y,Grids& grid) :Junction(x, y, grid) {
	IsRoad = false;

}
Turn::~Turn() {};

void Turn::UpdateJunction(Grids& grid) {
	if (UpCheck) { // means a vehicle approaches from north, going south
		
		Vehicle* v = grid.getVehicleGrid(x_coordinate, y_coordinate+1).VehicleB;
		Vehicle* vMoved = grid.getVehicleGrid(x_coordinate, y_coordinate+1).VehicleA;

		if (v != nullptr and vMoved == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, nullptr, 0);
			v->setVehicleDirection(grid, 1); // manually change vehicle direction as it is tied to road but is only set when created as until now vehicles havent changed direction
			v->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, v, 1);
		}

	}

	if (DownCheck) { // means a vehicle approaches from south,going north
		
		Vehicle* v = grid.getVehicleGrid(x_coordinate, y_coordinate-1).VehicleA;
		Vehicle* vcheck = grid.getVehicleGrid(x_coordinate, y_coordinate-1).VehicleB;

		if (v != nullptr and vcheck == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate-1, nullptr, 1);
			v->setVehicleDirection(grid, 0);
			v->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate, y_coordinate-1, v, 0);
		}

	}
	if (RightCheck) { // means a vehicle approaches from east,going west

		Vehicle* v = grid.getVehicleGrid(x_coordinate + 1, y_coordinate ).VehicleB;
		Vehicle* vcheck = grid.getVehicleGrid(x_coordinate + 1, y_coordinate ).VehicleA;

		if (v != nullptr and vcheck == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate , nullptr, 0);
			v->setVehicleDirection(grid, 1);
			v->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate , v, 1);
		}

	}
	if (LeftCheck) { // means a vehicle approaches from west,going east

		Vehicle* v = grid.getVehicleGrid(x_coordinate - 1, y_coordinate).VehicleA;
		Vehicle* vcheck = grid.getVehicleGrid(x_coordinate - 1, y_coordinate ).VehicleB;

		if (v != nullptr and vcheck == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate , nullptr, 1);
			v->setVehicleDirection(grid, 0);
			v->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate , v, 0);
		}

	}
}