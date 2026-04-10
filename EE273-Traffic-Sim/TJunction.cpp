#include "TJunction.h"
#include "Grids.h"
#include "Vehicle.h"
TJunction::TJunction(int x, int y, Grids& grid) : Junction(x, y, grid) {


}
TJunction::~TJunction() {

}

void TJunction::UpdateJunction(Grids& grid) {
	if (UpCheck && LeftCheck && DownCheck) {

		if (UpApproach != nullptr && DownLeave == nullptr && LeftApproach == nullptr) { // additonal constraint to simulate cars giving way to car to "right"
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0);
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate);
			UpApproach->setY(y_coordinate - 1);
			UpApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, UpApproach, 0);

		}
		if (LeftApproach != nullptr && UpLeave == nullptr && DownApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate);
			LeftApproach->setY(y_coordinate + 1);
			LeftApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, LeftApproach, 1);

		}

		if (DownApproach != nullptr && LeftLeave == nullptr && UpApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1);
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate - 1);
			DownApproach->setY(y_coordinate);
			DownApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, DownApproach, 0);

		}
	}


	if (RightCheck && UpCheck && LeftCheck) {




		if (RightApproach != nullptr && LeftLeave == nullptr && UpApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate - 1);
			RightApproach->setY(y_coordinate);
			RightApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, RightApproach, 0);
		}
		if (UpApproach != nullptr && RightLeave == nullptr && LeftApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0);
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate + 1);
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, UpApproach, 1);

		}
		if (LeftApproach != nullptr && UpLeave == nullptr && RightApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate);
			LeftApproach->setY(y_coordinate + 1);
			LeftApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, LeftApproach, 1);

		}
	}
	if (DownCheck && RightCheck && UpCheck) {
	

		if (DownApproach != nullptr && UpLeave == nullptr && RightApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1);
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate);
			DownApproach->setY(y_coordinate + 1);
			DownApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, DownApproach, 1);
		}
		if (RightApproach != nullptr && DownLeave == nullptr && UpApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate);
			RightApproach->setY(y_coordinate - 1);
			RightApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, RightApproach, 0);
		}
		if (UpApproach != nullptr && RightLeave == nullptr && DownApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0);
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate + 1);
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, UpApproach, 1);

		}
	}
	if (LeftCheck && DownCheck && RightCheck) {
	

		if (LeftApproach != nullptr && RightLeave == nullptr && DownApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate + 1);
			LeftApproach->setY(y_coordinate);
			LeftApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, LeftApproach, 1);
		}
		if (DownApproach != nullptr && LeftLeave == nullptr && RightApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1);
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate - 1);
			DownApproach->setY(y_coordinate);
			DownApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, DownApproach, 0);

		}
		if (RightApproach != nullptr && DownLeave == nullptr && LeftApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate);
			RightApproach->setY(y_coordinate - 1);
			RightApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, RightApproach, 0);

		}
	}


}


