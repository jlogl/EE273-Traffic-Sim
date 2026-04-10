#include "CrossJunction.h"
#include "Grids.h"
#include "Vehicle.h"

CrossJunction::CrossJunction(int x, int y, Grids& grid) :Junction(x, y, grid) {

}
CrossJunction::~CrossJunction() {

};

void CrossJunction::UpdateJunction(Grids& grid) {


	if (UpApproach != nullptr && RightLeave == nullptr && LeftApproach == nullptr) {
		grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0);
		UpApproach->setCurrentSpeed(0);
		UpApproach->setX(x_coordinate + 1);
		UpApproach->setY(y_coordinate);
		UpApproach->setVehicleDirection(grid, 1);
		grid.setVehicleGrid(x_coordinate + 1, y_coordinate, UpApproach, 1);

	}
	if (LeftApproach != nullptr && UpLeave == nullptr && DownApproach == nullptr) {

		grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
		LeftApproach->setCurrentSpeed(0);
		LeftApproach->setX(x_coordinate);
		LeftApproach->setY(y_coordinate + 1);
		LeftApproach->setVehicleDirection(grid, 1);
		grid.setVehicleGrid(x_coordinate, y_coordinate + 1, LeftApproach, 1);
	}
	if (DownApproach != nullptr && LeftLeave == nullptr && RightApproach == nullptr) {
		grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1);
		DownApproach->setCurrentSpeed(0);
		DownApproach->setX(x_coordinate - 1);
		DownApproach->setY(y_coordinate);
		DownApproach->setVehicleDirection(grid, 0);
		grid.setVehicleGrid(x_coordinate - 1, y_coordinate, DownApproach, 0);


	}
	if (RightApproach != nullptr && DownLeave == nullptr && UpApproach == nullptr) {
		grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
		RightApproach->setCurrentSpeed(0);
		RightApproach->setX(x_coordinate);
		RightApproach->setY(y_coordinate - 1);
		RightApproach->setVehicleDirection(grid, 0);
		grid.setVehicleGrid(x_coordinate, y_coordinate - 1, RightApproach, 0);
	}


};