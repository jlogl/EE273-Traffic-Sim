#include "Turn.h"
#include "Vehicle.h"
#include "Grids.h"
#include <iostream>
Turn::Turn(int x, int y,Grids& grid) :Junction(x, y, grid) {
	IsRoad = false;

}
Turn::~Turn() {};

void Turn::UpdateJunction(Grids& grid) {
	if (UpCheck) { // means a vehicle approaches from north, going south as their is a road ABOVE the junction
		
	

		if (UpApproach != nullptr && UpLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, nullptr, 0);
			UpApproach->setVehicleDirection(grid, 1); // manually change vehicle direction as it is tied to road but is only set when created as until now vehicles havent changed direction
			UpApproach->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, UpApproach, 1);
		}

	}

	if (DownCheck) { // means a vehicle approaches from south,going north as their is a road BELOW the Junction
		
		

		if (DownApproach != nullptr && DownLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate-1, nullptr, 1);
			DownApproach->setVehicleDirection(grid, 0);
			DownApproach->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate, y_coordinate-1, DownApproach, 0);
		}

	}
	if (RightCheck) { // means a vehicle approaches from east,going west as their is a road to right of Junction

	

		if (RightApproach != nullptr && RightLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate , nullptr, 0);
			RightApproach->setVehicleDirection(grid, 1);
			RightApproach->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate , RightApproach, 1);
		}

	}
	if (LeftCheck) { // means a vehicle approaches from west,going east as their isa road to left of junction

		

		if (LeftApproach != nullptr and LeftLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate , nullptr, 1);
			LeftApproach->setVehicleDirection(grid, 0);
			LeftApproach->setCurrentSpeed(0);
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate , LeftApproach, 0);
		}

	}
}
