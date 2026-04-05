#include "Vehicle.h"
#include "Grids.h"
#include "math.h"
#include <cmath>
#include <iostream>
Vehicle::Vehicle(int row, int col)
	:x(row), y(col), x_initial(row), y_initial(col), current_speed(0), speed_initial(0)
	/* needed to use initialiser list since it involves setting value of constants for initial variables
	The acceleration, deceleration and max speed will be set by the sub-classes as that is specific to the type of vehicle
	The direction is set to None as that is associated with the road which the vehicle is placed onto and as of now the vehicle isnt on a road*/
{
};
Vehicle::~Vehicle() {};

void Vehicle::UpdateSpeed(Grids& grid) {
	bool safety = isStoppingDistanceSafe(grid);
	
	std::cout << "Vehicle pre speed changes " << x << "," << y
		<< " speed=" << current_speed
		<< " SD=" << getStoppingDistance()
		<< " safe=" <<safety << std::endl;
	if (safety) {
		if (current_speed < max_speed) {
			current_speed = current_speed + acceleration;
		}
		if (current_speed > max_speed) {
			current_speed = max_speed;
		}
	}
	else {
		current_speed = current_speed - deceleration;
		if (current_speed < 0) {
			current_speed = 0;
		}
	}
	std::cout << "Vehicle at " << x << "," << y
		<< " speed=" << current_speed
		<< " SD=" << getStoppingDistance()
		<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;

}
void Vehicle::UpdateMovement(Grids& grid) {
		switch (Direction) {// need to use case as each direction of road will act differently


	case(North):
		grid.setVehicleGrid(x, y, nullptr);// sets the previous location of car to null since car is no longer there
		y = y + current_speed; // updates y coordinate
		grid.setVehicleGrid(x, y, this);// updates THIS instance of Vehicles position
		break;
	case (East):
		grid.setVehicleGrid(x, y, nullptr);
		x = x + current_speed;
		grid.setVehicleGrid(x, y, this);
		break;
	case(South):
		grid.setVehicleGrid(x, y, nullptr);
		y = y - current_speed;
		grid.setVehicleGrid(x, y, this);
		break;
	case(West):
		grid.setVehicleGrid(x, y, nullptr);
		x = x - current_speed;
		grid.setVehicleGrid(x, y, this);
		break;
	}

}

void Vehicle::ResetVehicle() {


};
type Vehicle::getVehicleType() {
	return Type;
}
direction Vehicle::getVehicleDirection() {

	return Direction;
}

void Vehicle::setVehicleDirection(Grids& grid) {
	Roads* R = grid.getRoadsGrid(x, y);
	Direction=R->getDirection();
	
};

int Vehicle::getStoppingDistance() {

	double stoppingDistance = 0;

	stoppingDistance = pow(current_speed, 2) / (2 * deceleration);
	int stoppingDistanceInt = ceil(stoppingDistance);
	return stoppingDistanceInt ; 

};
int Vehicle::getCurrentSpeed() {
	return current_speed;
};

int Vehicle::getX() {
	return x;

}
int Vehicle::getY() {
	return y;

}
void Vehicle::setX(int x) {
	x = this->x; // should NEVER be used to in main, only used for load function

}
void Vehicle::setY(int y) {
	y = this->y; // should NEVER be used to in main, only used for load function
}


bool Vehicle::isStoppingDistanceSafe(Grids& grid) {
	int StoppingDistance = getStoppingDistance();
	switch (Direction) {
	case(North): {
		for (int i = y+1; i <= y + StoppingDistance; i = i + 1) {
			std::cout << "Check At " << x << " " << i << std::endl;
			if (i < 0 || i>Grids::grid_size - 1) {
				std::cout << "OOB at " << x << " " << i <<"ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle remains in sim boundray, had idea if the vehicle is going to leave sim range, let it and just delete it
			}

			if (grid.getRoadsGrid(x, i) == nullptr) {
				std::cout << "No Road at " << x << " " << i << "ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if their is road the whole path 
			}

			if (grid.getVehicleGrid(x, i) != nullptr) {
				std::cout << "Vehicle at " << x << " " << i << "ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
			std::cout << "Succesful check at " << x << " " << i << std::endl;
		}
		std::cout << "SAFE at " << x << " " << y << "SAFE SAFE SAFE SAFE SAFE " << std::endl;
		return true;
		break;

	}
	case(East): {
		for (int i = x+1; i <= x + StoppingDistance; i = i + 1) {
			std::cout << "Check At " << i << " " << y << std::endl;
			if (i < 0 || i>Grids::grid_size - 1) {
				

				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y) == nullptr) {
				
				return false; // checks if their is road the whole path 
			}

			if (grid.getVehicleGrid(i, y) != nullptr) {
				
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;
		break;
	}
	case(South): {
		for (int i = y-1; i >= y - StoppingDistance; i = i - 1) {
			std::cout << "Check At " << x << " " << i << std::endl;
			if (i < 0 || i>Grids::grid_size - 1) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(x, i) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid.getVehicleGrid(x, i) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;
		break;
	}
	case(West): {
		for (int i = x-1; i >= x - StoppingDistance; i = i - 1) {
			std::cout << "Check At " << i << " " << y << std::endl;
			if (i < 0 || i>Grids::grid_size - 1) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid.getVehicleGrid(i, y) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;
		break;
	}
	}
}