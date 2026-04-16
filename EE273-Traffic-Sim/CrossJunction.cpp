#include "CrossJunction.h"
#include "Grids.h"
#include "Vehicle.h"
#include <stdlib.h> 
#include <time.h>


CrossJunction::CrossJunction(int x, int y, Grids& grid) :Junction(x, y, grid) {

}
CrossJunction::~CrossJunction() {

};

void CrossJunction::UpdateJunction(Grids& grid) {
	int random = rand() % 2; // is either 0 or 1, used at the begining of Update Junction to randomly decide behaviour

	
	if (random == 0) {
		if (UpApproach != nullptr && RightLeave == nullptr && LeftApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0); //up to right
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate + 1);
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection(grid, 1);
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, UpApproach, 1);
			UpApproach->addDistance();
			totalUses = totalUses + 1;
		}
		if (LeftApproach != nullptr && UpLeave == nullptr && DownApproach == nullptr) {

			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1); //left to up 
			LeftApproach->setCurrentSpeed(0);			
			LeftApproach->setX(x_coordinate);
			LeftApproach->setY(y_coordinate + 1);
			LeftApproach->setVehicleDirection(grid, 1);
			LeftApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, LeftApproach, 1);
			totalUses = totalUses + 1;
		}
		if (DownApproach != nullptr && LeftLeave == nullptr && RightApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1); //down to left
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate - 1);
			DownApproach->setY(y_coordinate);
			DownApproach->setVehicleDirection(grid, 0);
			DownApproach->addDistance();
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, DownApproach, 0);
			totalUses = totalUses + 1;

		}
		if (RightApproach != nullptr && DownLeave == nullptr && UpApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0); //right to down
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate);
			RightApproach->setY(y_coordinate - 1);
			RightApproach->setVehicleDirection(grid, 0);
			RightApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, RightApproach, 0);
			totalUses = totalUses + 1;
		}

	}
	else {
		if (UpApproach != nullptr && DownLeave == nullptr && LeftApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0); //up to down
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate );
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection(grid, 0);
			grid.setVehicleGrid(x_coordinate, y_coordinate-1, UpApproach, 0);
			UpApproach->addDistance();
			totalUses = totalUses + 1;
		}
		if (LeftApproach != nullptr && RightLeave == nullptr && DownApproach == nullptr) {

			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1); //left to right
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate+1);
			LeftApproach->setY(y_coordinate);
			LeftApproach->setVehicleDirection(grid, 1);
			LeftApproach->addDistance();
			grid.setVehicleGrid(x_coordinate+1, y_coordinate, LeftApproach, 1);
			totalUses = totalUses + 1;
		}
		if (DownApproach != nullptr && UpLeave == nullptr && RightApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1); //down to up
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate);
			DownApproach->setY(y_coordinate+1);
			DownApproach->setVehicleDirection(grid, 1);
			DownApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, DownApproach, 1);
			totalUses = totalUses + 1;

		}
		if (RightApproach != nullptr && LeftLeave == nullptr && UpApproach == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0); //right to left
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate-1);
			RightApproach->setY(y_coordinate);
			RightApproach->setVehicleDirection(grid, 0);
			RightApproach->addDistance();
			grid.setVehicleGrid(x_coordinate-1, y_coordinate, RightApproach, 0);
			totalUses = totalUses + 1;
		}



	}
};