#include "Vehicle.h"
#include "Grids.h"
#include "Roads.h"
#include "SimulationEngine.h"
#include "math.h"
#include <cmath>
#include <iostream>
Vehicle::Vehicle(int x, int y)
	:x(x), y(y), x_initial(x), y_initial(y), current_speed(0), speed_initial(0)
	/* needed to use initialiser list since it involves setting value of constants for initial variables
	The acceleration, deceleration and max speed will be set by the sub-classes as that is specific to the type of vehicle
	The direction is set to None as that is associated with the road which the vehicle is placed onto and as of now the vehicle isnt on a road*/
{
};
Vehicle::~Vehicle() {};

void Vehicle::UpdateSpeed(Grids& grid,SimulationEngine& engine) {
	bool safety = isStoppingDistanceSafe(grid);
	int SL = grid.getRoadsGrid(x, y).RoadA->getSpeedLimit();// doesnt matter what lane used since the speed limit of RoadA equals speed limit of RoadB
	
	std::cout << "Vehicle before changes at " << x << "," << y
		<< " speed=" << current_speed
		<< " SD=" << getStoppingDistance()
		<< " safe=" << safety << std::endl;
	
	
	switch (Direction) {
	case(North): {
		if (!grid.getRoadsGrid(x, y + current_speed).RoadA->isRoad()) {
			std::cout << "North used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;

	}
	case(East): {
		if (!grid.getRoadsGrid(x + current_speed, y).RoadA->isRoad()) {
			std::cout << "East used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;

	}
	case(South): {
		if (!grid.getRoadsGrid(x, y - current_speed).RoadA->isRoad()) {
			std::cout << "South used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;
	}
	case(West): {
		if (!grid.getRoadsGrid(x - current_speed, y).RoadA->isRoad()) {
			std::cout << "West used" << std::endl;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			current_speed = current_speed - 1;
			return;
		}
		break;
	}

	}
	
	if (safety) {
		if (current_speed < max_speed) {
			current_speed = current_speed + acceleration;
		}
		if (current_speed > SL) {
			current_speed = SL;
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

	switch (Direction) {
	case(North): {
		if (!grid.getRoadsGrid(x, y + current_speed).RoadA->isRoad()) {
			std::cout << "North used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;

	}
	case(East): {
		if (!grid.getRoadsGrid(x + current_speed, y).RoadA->isRoad()) {
			std::cout << "East used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;

	}
	case(South): {
		if (!grid.getRoadsGrid(x, y - current_speed).RoadA->isRoad()) {
			std::cout << "South used" << std::endl;
			current_speed = current_speed - 1;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			return;
		}
		break;
	}
	case(West): {
		if (!grid.getRoadsGrid(x - current_speed, y).RoadA->isRoad()) {
			std::cout << "West used" << std::endl;
			std::cout << "Vehicle after changes at " << x << "," << y
				<< " speed=" << current_speed
				<< " SD=" << getStoppingDistance()
				<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;
			current_speed = current_speed - 1;
			return;
		}
		break;
	}

	}
	 /* The if statement below was implemented to deal with a niche case that when the simualtion began for the first time and a vehicles distance from a junction is the same
	 as the vehicles types accelration as the car would enter a jucntion which with the way we created them isnt inteneded. The solution involves creating a way to check if a
	 simulation is on its first step, and if so then sort the vehicle by direction and then if the distance and current speed are the same, take 1 away from the speed.
	 This worked because of the order of updates in the engine, as the speed updates before the movement, up to the integrration of junctions, this is the most difficult issue to 
	 solve so far - 08/04/2026*/

	/* Turns out this is just a issue if the distance to the junction is equal to current speed, meaning we always have to check if a vehicles's current speed is equal to the distance to jucntion and if so we intervene otherwise the charactersitcs of the vehicle 
	are used, but we then have to check again after the speed has been updated because if we only check after the speed may get set to zero then one which doesnt seem realistic. not ideal for sim realism but its either this or rework junctions and this is alot simpler -  09/04/26*/

		
		
	std::cout << "Vehicle after changes at " << x << "," << y
		<< " speed=" << current_speed
		<< " SD=" << getStoppingDistance()
		<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;





	

}
void Vehicle::UpdateMovement(Grids& grid) {
		switch (this->Direction) {// need to use case as each direction of road will act differently


	case(North):
		grid.setVehicleGrid(x, y, nullptr,1);// sets the previous location of car to null since car is no longer there
		y = y + current_speed; // updates y coordinate
		grid.setVehicleGrid(x, y, this,1);// updates THIS instance of Vehicles position
		break;
	case (East):
		grid.setVehicleGrid(x, y, nullptr,1);
		x = x + current_speed;
		grid.setVehicleGrid(x, y, this,1);
		break;
	case(South):
		grid.setVehicleGrid(x, y, nullptr,0);
		y = y - current_speed;
		grid.setVehicleGrid(x, y, this,0);
		break;
	case(West):
		grid.setVehicleGrid(x, y, nullptr,0);
		x = x - current_speed;
		grid.setVehicleGrid(x, y, this,0);
		break;
	}

		std::cout << "Vehicle after movement changes at " << x << "," << y
			<< " speed=" << current_speed
			<< " SD=" << getStoppingDistance()
			<< " safe=" << isStoppingDistanceSafe(grid) << std::endl;

}

void Vehicle::ResetVehicle(Grids& grid) {
	bool lane = (this->getVehicleDirection() == North || this->getVehicleDirection() == East);
	grid.setVehicleGrid(x, y, nullptr,lane);
	this->setX(x_initial);
	this->setY(y_initial);
	this->setCurrentSpeed(speed_initial);
	grid.setVehicleGrid(x, y,this,lane);
};

type Vehicle::getVehicleType() {
	return Type;
}
direction Vehicle::getVehicleDirection() {

	return Direction;
}

void Vehicle::setVehicleDirection(Grids& grid, bool A_or_B) {
	if (A_or_B) {
		Roads* R = grid.getRoadsGrid(x, y).RoadA;
		Direction = R->getDirection();
	}
	else {
		Roads* R = grid.getRoadsGrid(x, y).RoadB;
		Direction = R->getDirection();
	}
};

int Vehicle::getStoppingDistance() {

	double stoppingDistance = 0;

	stoppingDistance = pow(current_speed, 2) / (2 * deceleration);
	int stoppingDistanceInt = ceil(stoppingDistance);
	return stoppingDistanceInt+1 ; 

};
int Vehicle::getCurrentSpeed() {
	return current_speed;
};
void Vehicle::setCurrentSpeed(int speed) {
	current_speed = speed;

}

int Vehicle::getX() {
	return x;

}
int Vehicle::getY() {
	return y;

}
int Vehicle::getInitialX() {
	return x_initial;
}
int Vehicle::getInitialY() {
	return y_initial;
}
void Vehicle::setX(int X) {
	x = X; // should NEVER be used to in main, only used for load function

}
void Vehicle::setY(int Y) {
	y = Y; // should NEVER be used to in main, only used for load function
}



bool Vehicle::isStoppingDistanceSafe(Grids& grid) {
	int StoppingDistance = getStoppingDistance();
	switch (Direction) {
	case(North): { // due to always having 2 lanes, and the way they are assigned, we know if a car is going north or east it is A and if its south or west its B
		for (int i = y+1; i <= y + StoppingDistance; i = i + 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
				std::cout << "OOB at " << x << " " << i <<" ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle remains in sim boundray, had idea if the vehicle is going to leave sim range, let it and just delete it
			}
			
			
			if (grid.getRoadsGrid(x, i).RoadA == nullptr) {
				std::cout << "No Road at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if their is road the whole path 
			}

			if (!grid.getRoadsGrid(x, i).RoadA->isRoad()) {
				std::cout << "Approaching Junction at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false;// checks if vehicle is approaching junction
			}
			if (grid.getVehicleGrid(x, i).VehicleA  != nullptr) {
				std::cout << "Vehicle at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle is already on path
			}

		
			
		}
		std::cout << "SAFE at " << x << " " << y << " SAFE SAFE SAFE SAFE SAFE " << std::endl;
		return true;
		break;

	}
	case(East): {
		for (int i = x+1; i <= x + StoppingDistance; i = i + 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
				std::cout << "OOB at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;

				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y).RoadA == nullptr) {
				std::cout << "No Road at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(i, y).RoadA->isRoad()) {
				std::cout << "Approaching Junction at " << i << " " << y<< " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false;// checks if vehicle is approaching junction
			}

			if (grid.getVehicleGrid(i, y).VehicleA != nullptr) {
				std::cout << "Vehicle at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle is already on path
			}
			
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		std::cout << "SAFE at " << x << " " << y << " SAFE SAFE SAFE SAFE SAFE " << std::endl;
		return true;
		break;
	}
	case(South): {
		for (int i = y-1; i >= y - StoppingDistance; i = i - 1) {
		
			if (i < 0 || i>Grids::grid_size - 1) {
				std::cout << "OOB at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(x, i).RoadB == nullptr) {
				std::cout << "No Road at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(x, i).RoadA->isRoad()) {
				std::cout << "Approaching Junction at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false;// checks if vehicle is approaching junction
			}

			if (grid.getVehicleGrid(x, i).VehicleB != nullptr) {
				std::cout << "Vehicle at " << x << " " << i << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle is already on path
			}
			
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		std::cout << "SAFE at " << x << " " << y << " SAFE SAFE SAFE SAFE SAFE " << std::endl;
		return true;
		break;
	}
	case(West): {
		for (int i = x-1; i >= x - StoppingDistance; i = i - 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
				std::cout << "OOB at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y).RoadB == nullptr) {
				std::cout << "No Road at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(i, y).RoadA->isRoad()) {
				std::cout << "Approaching Junction at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false;// checks if vehicle is approaching junction
			}


			if (grid.getVehicleGrid(i, y).VehicleB != nullptr) {
				std::cout << "Vehicle at " << i << " " << y << " ERROR ERROR ERROR ERROR ERROR " << std::endl;
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		std::cout << "SAFE at " << x << " " << y << " SAFE SAFE SAFE SAFE SAFE " << std::endl;
		return true;
		break;
	}
	}
}