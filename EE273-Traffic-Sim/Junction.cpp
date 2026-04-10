#include"Junction.h"
#include "Grids.h"

Junction::Junction(int x,int y,Grids& grid) {
	x_coordinate = x;
	y_coordinate = y;
	IsRoad = false;
	Type = unassigned;

	
}
Junction::~Junction() {};

junction Junction::getJunctionType() {
	return Type;
}
void Junction::setType(Grids& grid) {
	int count = 0;
	if (grid.getRoadsGrid(x_coordinate, y_coordinate + 1).RoadA != nullptr) {
		if (grid.getRoadsGrid(x_coordinate, y_coordinate + 1).RoadA->isRoad()) {
			if (grid.getRoadsGrid(x_coordinate, y_coordinate + 1).RoadA->getDirection() == North) {
				UpCheck = true;
				count = count + 1;
			}
			
		
		}
	
			
		
	}
	if (grid.getRoadsGrid(x_coordinate, y_coordinate - 1).RoadB != nullptr) {
		if (grid.getRoadsGrid(x_coordinate, y_coordinate - 1).RoadB->isRoad()) {
			if (grid.getRoadsGrid(x_coordinate, y_coordinate - 1).RoadB->getDirection() == South) {
				DownCheck = true;
				count = count + 1;
			}


		}
	
	}
	if (grid.getRoadsGrid(x_coordinate + 1, y_coordinate).RoadA != nullptr) {
		if (grid.getRoadsGrid(x_coordinate+1, y_coordinate).RoadA->isRoad()) {
			if (grid.getRoadsGrid(x_coordinate+1, y_coordinate ).RoadA->getDirection() == East) {
				RightCheck = true;
				count = count + 1;
			}


		}
		

	}

	if (grid.getRoadsGrid(x_coordinate - 1, y_coordinate).RoadB != nullptr) {
		if (grid.getRoadsGrid(x_coordinate - 1, y_coordinate).RoadB->isRoad()) {
			if (grid.getRoadsGrid(x_coordinate-1, y_coordinate).RoadB->getDirection() == West) {
				LeftCheck = true;
				count = count + 1;
			}


		}
		

	}
	switch (count) {
		case(0): {
			Type = unassigned;
			break;
		}
		case(1): {
			Type = turn;
			break;
		}
		case(2): {

			if (UpCheck && DownCheck) {
				Type = roads;
			}
			else if (LeftCheck && RightCheck) {
				Type = roads;
			}
			else {
				Type = corner;
			}
			break;

		}
		case(3): {
			Type = t;
			break;
		}
		case(4): {
			Type = cross;
			break;
		}
	}
	return;
}
void Junction::UpdateJunction(Grids& grid) {};// doesnt need to do anything as is always overridden, but needs defenition
void Junction::SetJunctionPointers(Grids& grid) {

	 UpApproach = grid.getVehicleGrid(x_coordinate, y_coordinate + 1).VehicleB;
	 UpLeave = grid.getVehicleGrid(x_coordinate, y_coordinate + 1).VehicleA;

	 LeftApproach = grid.getVehicleGrid(x_coordinate - 1, y_coordinate).VehicleA;
	 LeftLeave = grid.getVehicleGrid(x_coordinate - 1, y_coordinate).VehicleB;

	 DownApproach = grid.getVehicleGrid(x_coordinate, y_coordinate - 1).VehicleA;
	 DownLeave = grid.getVehicleGrid(x_coordinate, y_coordinate - 1).VehicleB;

	 RightApproach = grid.getVehicleGrid(x_coordinate + 1, y_coordinate).VehicleB;
	 RightLeave = grid.getVehicleGrid(x_coordinate + 1, y_coordinate).VehicleA;


}