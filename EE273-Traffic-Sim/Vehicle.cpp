#include "Vehicle.h"
#include "Grids.h"
#include "Roads.h"
#include "SimulationEngine.h"
#include "math.h"
#include <cmath>
#include <iostream>
Vehicle::Vehicle(int x, int y,Grids& grid)
	:x(x), y(y),grid(grid), x_initial(x), y_initial(y), current_speed(0), speed_initial(0)
	/* needed to use initialiser list since it involves setting value of constants for initial variables
	The acceleration, deceleration and max speed will be set by the sub-classes as that is specific to the type of vehicle
	The direction is set to None as that is associated with the road which the vehicle is placed onto and since a vehicle must be created on a road, it will always have a direction*/
{
};
Vehicle::~Vehicle() {};

/* The function below were implemented to deal with a niche case that when the simualtion began for the first time and a vehicles distance from a junction is the same
	 as the vehicles types accelration as the car would enter a jucntion which with the way we created them isnt inteneded. The solution involves creating a way to check if a
	 simulation is on its first step, and if so then sort the vehicle by direction and then if the distance and current speed are the same, take 1 away from the speed.
	 This worked because of the order of updates in the engine, as the speed updates before the movement, up to the integration of junctions, this is the most difficult issue to
	 solve so far as we looked to keep as much realism as possible - 08/04/2026*/

	 /* Turns out this is just a issue if the distance to the junction is equal to current speed, meaning we always have to check if a vehicles's current speed is equal to the distance to jucntion and if so we intervene otherwise the charactersitcs of the vehicle
	are used, but we then have to check again after the speed has been updated because if we only check after the speed may get set to zero then one which doesnt seem realistic. not ideal for sim realism but its either this or rework junctions and this is alot simpler -  09/04/26*/


bool Vehicle::SafetyOverride() {
	bool called = false;
	switch (Direction) {
	case(North): {
		if(y+current_speed < Grids::grid_size-1 && y+current_speed >= 0){
			if (grid.getRoadsGrid(x, y + current_speed).RoadA != nullptr) {
				if (!grid.getRoadsGrid(x, y + current_speed).RoadA->isRoad()) {

					current_speed = current_speed - 1;
					called = true;
				}
					
				}
			}
		bool check = true;
		while (check) {
			if (grid.getVehicleGrid(x, y + current_speed).VehicleA != nullptr && grid.getVehicleGrid(x, y + current_speed).VehicleA->getCurrentSpeed() == 0 && grid.getVehicleGrid(x, y + current_speed).VehicleA != this) {

				current_speed = current_speed - 1;
				called = true;
			}
			else {
				break;
			}
		}

	
		break;
	}
	case(East): {
		if (x + current_speed < Grids::grid_size && x + current_speed >= 0) {
			if (grid.getRoadsGrid(x + current_speed, y).RoadA != nullptr) {
				if (!grid.getRoadsGrid(x + current_speed, y).RoadA->isRoad()) {

					current_speed = current_speed - 1;
					called = true;
				}
			}
		}
		bool check = true;
		while (check) {
				if (grid.getVehicleGrid( x+ current_speed,y).VehicleA != nullptr && grid.getVehicleGrid( x + current_speed,y).VehicleA->getCurrentSpeed() == 0 && grid.getVehicleGrid( x + current_speed,y).VehicleA != this) {

						current_speed = current_speed - 1;
						called = true;
					}
				else {
					break;
				}
		}
		break;
	}
	case(South): {
		if (y - current_speed < Grids::grid_size  && y - current_speed >= 0) {
			if (grid.getRoadsGrid(x, y - current_speed).RoadA != nullptr) {
				if (!grid.getRoadsGrid(x, y - current_speed).RoadA->isRoad()) {

					current_speed = current_speed - 1;
					called = true;
				}
			}
					bool check = true;
					while (check) {
						if (grid.getVehicleGrid(x, y - current_speed).VehicleB != nullptr && grid.getVehicleGrid(x, y - current_speed).VehicleB->getCurrentSpeed() == 0 && grid.getVehicleGrid(x, y - current_speed).VehicleB != this) {

							current_speed = current_speed - 1;
							called = true;
						}
						else {
							break;
						}
					}
					
				}

			
		
		break;
	}
	case(West): {
		if (x - current_speed < Grids::grid_size  && x - current_speed >= 0) {
			if (grid.getRoadsGrid(x - current_speed, y).RoadA != nullptr) {
				if (!grid.getRoadsGrid(x - current_speed, y).RoadA->isRoad()) {
					current_speed = current_speed - 1;
					called = true;
				}

			}
		}
		bool check = true;
		while (check) {
			if (grid.getVehicleGrid(x- current_speed,y).VehicleB != nullptr && grid.getVehicleGrid(x- current_speed,y).VehicleB->getCurrentSpeed() == 0 && grid.getVehicleGrid(x - current_speed ,y).VehicleB != this) {

				current_speed = current_speed - 1;
				called = true;
			}
			else {
				break;
			}
		}
		break;
	}
		case(None): {
        break;

	}

	}
	return called;
};
void Vehicle::UpdateSpeed() {
	bool safety = isStoppingDistanceSafe();
	int SL = grid.getRoadsGrid(x, y).RoadA->getSpeedLimit();// doesnt matter what lane used since the speed limit of RoadA equals speed limit of RoadB
	
	if (SafetyOverride()) {
		return;
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

	SafetyOverride();

	}
	

	





	


void Vehicle::UpdateMovement() {
		switch (this->Direction) {// need to use case as each direction of road will act differently


	case(North):
		if (grid.getVehicleGrid(x, y).VehicleA == this) {
			grid.setVehicleGrid(x, y, nullptr, 1);
		}// sets the previous location of car to null since car is no longer there
		y = y + current_speed; // updates y coordinate
		grid.setVehicleGrid(x, y, this,1);// updates THIS instance of Vehicles position
		break;
	case (East):
		if (grid.getVehicleGrid(x, y).VehicleA == this) {
			grid.setVehicleGrid(x, y, nullptr, 1);
		}
		x = x + current_speed;
		grid.setVehicleGrid(x, y, this,1);
		break;
	case(South):
		if (grid.getVehicleGrid(x, y).VehicleB == this) {
			grid.setVehicleGrid(x, y, nullptr, 0);
		}
		y = y - current_speed;
		grid.setVehicleGrid(x, y, this,0);
		break;
	case(West):
		if (grid.getVehicleGrid(x, y).VehicleB == this) {
			grid.setVehicleGrid(x, y, nullptr, 0);
		}
		x = x - current_speed;
		grid.setVehicleGrid(x, y, this,0);
		break;
	}
		distance = distance + current_speed;
	

}

void Vehicle::ResetVehicle() {
	this->resetDistance();
	bool InitialLane = (getInitialVehicleDirection() == North || getInitialVehicleDirection() == East);
	bool CurrentLane = (getVehicleDirection() == North || getVehicleDirection() == East);
	if (CurrentLane) {
		if (grid.getVehicleGrid(x, y).VehicleA == this) {
			grid.setVehicleGrid(x, y, nullptr, CurrentLane);
		}
	}
	else {
		if(grid.getVehicleGrid(x,y).VehicleB == this){
			grid.setVehicleGrid(x, y, nullptr, CurrentLane);

		}
	}
	this->setX(x_initial);
	this->setY(y_initial);
	this->setCurrentSpeed(speed_initial);
	this->setVehicleDirection(InitialLane);
	grid.setVehicleGrid(x, y,this, InitialLane);

};

type Vehicle::getVehicleType() {
	return Type;
}
direction Vehicle::getVehicleDirection() {

	return Direction;
}
direction Vehicle::getInitialVehicleDirection() {
	
	return InitialDirection;
}



void Vehicle::setVehicleDirection( bool AorB) {
	
	if (AorB) {
		Roads* R = grid.getRoadsGrid(x, y).RoadA;
		Direction = R->getDirection();
	}
	else {
		Roads* R = grid.getRoadsGrid(x, y).RoadB;
		Direction = R->getDirection();
	}
};
void Vehicle::setInitialVehicleDirection(bool AorB) {

	if (AorB) {
		Roads* R = grid.getRoadsGrid(x, y).RoadA;
		InitialDirection = R->getDirection();
	}
	else {
		Roads* R = grid.getRoadsGrid(x, y).RoadB;
		InitialDirection = R->getDirection();
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
	x = X;

}
void Vehicle::setY(int Y) {
	y = Y; 
}
int Vehicle::getDistance() {
	return distance;
}
void Vehicle::addDistance() {
	distance = distance + 1;
}
void Vehicle::resetDistance() {

	distance = initialDistance;
}
double Vehicle::getAverageSpeed(SimulationEngine& engine) {
	if (engine.getCurrentTime()== 0) {
		return 0;
	}
	double result = double(distance) / (engine.getCurrentTime());
	return result;
}
void Vehicle::setInitialDistance(int i) {

	initialDistance = i; // used inside of load function to retain data oof vehicle 
}


bool Vehicle::isStoppingDistanceSafe() {
	int StoppingDistance = getStoppingDistance();
	switch (Direction) {
	case(North): { // due to always having 2 lanes, and the way they are assigned, we know if a car is going north or east it is A and if its south or west its B
		for (int i = y+1; i <= y + StoppingDistance; i = i + 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
			
				return false; // checks if vehicle remains in sim boundray, had idea if the vehicle is going to leave sim range, let it and just delete it
			}
			
			
			if (grid.getRoadsGrid(x, i).RoadA == nullptr) {
				
				return false; // checks if their is road the whole path 
			}

			if (!grid.getRoadsGrid(x, i).RoadA->isRoad()) {
				
				return false;// checks if vehicle is approaching junction
			}
			if (grid.getVehicleGrid(x, i).VehicleA  != nullptr) {
				
				return false; // checks if vehicle is already on path
			}

		
			
		}
		
		return true;
		break;

	}
	case(East): {
		for (int i = x+1; i <= x + StoppingDistance; i = i + 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
			

				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y).RoadA == nullptr) {
			
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(i, y).RoadA->isRoad()) {
			
				return false;// checks if vehicle is approaching junction
			}

			if (grid.getVehicleGrid(i, y).VehicleA != nullptr) {
				
				return false; // checks if vehicle is already on path
			}
			
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		
		return true;
		break;
	}
	case(South): {
		for (int i = y-1; i >= y - StoppingDistance; i = i - 1) {
		
			if (i < 0 || i>Grids::grid_size - 1) {
		
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(x, i).RoadB == nullptr) {
		
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(x, i).RoadA->isRoad()) {
			
				return false;// checks if vehicle is approaching junction
			}

			if (grid.getVehicleGrid(x, i).VehicleB != nullptr) {
				
				return false; // checks if vehicle is already on path
			}
			
			// will need to add signals but cant at moment cuz we havent done that yet
		}
	
		return true;
		break;
	}
	case(West): {
		for (int i = x-1; i >= x - StoppingDistance; i = i - 1) {
			
			if (i < 0 || i>Grids::grid_size - 1) {
			
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid.getRoadsGrid(i, y).RoadB == nullptr) {
				
				return false; // checks if their is road the whole path 
			}
			if (!grid.getRoadsGrid(i, y).RoadA->isRoad()) {
			
				return false;// checks if vehicle is approaching junction
			}


			if (grid.getVehicleGrid(i, y).VehicleB != nullptr) {
				
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
	
		return true;
		break;
	}
	}
}