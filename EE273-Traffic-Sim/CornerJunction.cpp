#include "CornerJunction.h"
#include "Grids.h"
#include "Vehicle.h"

CornerJunction::CornerJunction(int x,int y,Grids& grid):Junction(x,y,grid){

}
CornerJunction::~CornerJunction() {};

void CornerJunction::UpdateJunction(Grids& grid) {
	if (UpCheck && LeftCheck) {
	


		if (LeftApproach != nullptr && UpLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate); // need this as unlike a turn, the coordinates of the vehicle is changing during this process, not just the lane
			LeftApproach->setY(y_coordinate+1);
			LeftApproach->setVehicleDirection(1); // without this the vehicles direction doesnt update from going <-> to /\ and \/ and it gets stuck looking right
			LeftApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate+1, Junction::LeftApproach, 1);
			totalUses = totalUses + 1;
		}

		if (UpApproach != nullptr && LeftLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate,y_coordinate +1, nullptr, 0);
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate - 1);
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection( 0);
			UpApproach->addDistance();
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, UpApproach, 0);
			totalUses = totalUses + 1;
		}
	}
	if (UpCheck && RightCheck) {

		if (RightApproach != nullptr && UpLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate);
			RightApproach->setY(y_coordinate + 1);
			RightApproach->setVehicleDirection( 1);
			RightApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, RightApproach, 1);
			totalUses = totalUses + 1;
		}
		if(UpApproach != nullptr && RightLeave == nullptr){
			grid.setVehicleGrid(x_coordinate, y_coordinate + 1, nullptr, 0);
			UpApproach->setCurrentSpeed(0);
			UpApproach->setX(x_coordinate + 1);
			UpApproach->setY(y_coordinate);
			UpApproach->setVehicleDirection( 1);
			UpApproach->addDistance();
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, UpApproach, 1);
			totalUses = totalUses + 1;
		}
	}
	if (DownCheck && LeftCheck) {

		if (LeftApproach != nullptr && DownLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, nullptr, 1);
			LeftApproach->setCurrentSpeed(0);
			LeftApproach->setX(x_coordinate);
			LeftApproach->setY(y_coordinate - 1);
			LeftApproach->setVehicleDirection( 0);
			LeftApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, LeftApproach, 0);
			totalUses = totalUses + 1;
		}

		if (DownApproach != nullptr && LeftLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, nullptr, 1);
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate - 1);
			DownApproach->setY(y_coordinate);
			DownApproach->setVehicleDirection( 0);
			DownApproach->addDistance();
			grid.setVehicleGrid(x_coordinate - 1, y_coordinate, DownApproach, 0);
			totalUses = totalUses + 1;
		}
	}
	if (DownCheck && RightCheck) {

		if (RightApproach != nullptr && DownLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, nullptr, 0);
			RightApproach->setCurrentSpeed(0);
			RightApproach->setX(x_coordinate);
			RightApproach->setY(y_coordinate - 1);
			RightApproach->setVehicleDirection( 0);
			RightApproach->addDistance();
			grid.setVehicleGrid(x_coordinate, y_coordinate - 1, RightApproach, 0);
			totalUses = totalUses + 1;
		}

		if (DownApproach != nullptr && RightLeave == nullptr) {
			grid.setVehicleGrid(x_coordinate, y_coordinate -1, nullptr, 1);
			DownApproach->setCurrentSpeed(0);
			DownApproach->setX(x_coordinate + 1);
			DownApproach->setY(y_coordinate);
			DownApproach->setVehicleDirection( 1);
			DownApproach->addDistance();
			grid.setVehicleGrid(x_coordinate + 1, y_coordinate, DownApproach, 1);
			totalUses = totalUses + 1;
		}


	}
}