#include "Vehicle.h"
#include "Grids.h"
#include "math.h"

Vehicle::Vehicle(int row, int col)
	:x(row), y(col), x_initial(row), y_initial(col), current_speed(0), speed_initial(0)
	/* needed to use initialiser list since it involves setting value of constants for initial variables
	The acceleration, deceleration and max speed will be set by the sub-classes as that is specific to the type of vehicle
	The direction is set to None as that is associated with the road which the vehicle is placed onto and as of now the vehicle isnt on a road*/
{
};
Vehicle::~Vehicle() {};
void Vehicle::UpdateVehicle(Grids* grid) {
	 
	if (isStoppingDistanceSafe(grid)) { //how vehicle should react if path is safe
		if (current_speed < max_speed) {
			current_speed = current_speed + acceleration;
		}
		if (current_speed > max_speed){
			current_speed = max_speed;
	}

	}
	else {// when path isnt valid
		current_speed = current_speed - deceleration;
		if (current_speed < 0) {
			current_speed = 0;
		}


	}
	switch (Direction) {// need to use case as each direction of road will act differently


	case(North):
		grid->setVehicleGrid(x, y, nullptr);// sets the previous location of car to null since car is no longer there
		y = y + current_speed; // updates y coordinate
		grid->setVehicleGrid(x, y, this);// updates THIS instance of Vehicles position
		break;
	case (East):
		grid->setVehicleGrid(x, y, nullptr);
			x = x + current_speed;
		grid->setVehicleGrid(x, y, this);
		break;
	case(South):
		grid->setVehicleGrid(x, y, nullptr);
		y = y - current_speed;
		grid->setVehicleGrid(x, y, this);
		break;
	case(West):
		grid->setVehicleGrid(x, y, nullptr);
		x = x - current_speed;
		grid->setVehicleGrid(x, y, this);
		break;
	}
	



};
void Vehicle::ResetVehicle() {


};
type Vehicle::getVehicleType() {
	return Type;
}


int Vehicle::getStoppingDistance() {

	int stoppingDistance = 0;

	stoppingDistance = pow(current_speed, 2) / (2 * deceleration);

	return stoppingDistance;

};
bool Vehicle::isStoppingDistanceSafe(Grids* grid) {
	int StoppingDistance = getStoppingDistance();
	switch (Direction) {
	case(North): {
		for (int i = y; i <= y + StoppingDistance; i = i + 1) {
			if (i < 0 || i>10) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid->getRoadsGrid(x, i) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid->getVehicleGrid(x, i) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;


	}
	case(East): {
		for (int i = x; i <= x + StoppingDistance; i = i + 1) {
			if (i < 0 || i>10) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid->getRoadsGrid(i, y) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid->getVehicleGrid(i, y) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;

	}
	case(South): {
		for (int i = y; i >= y - StoppingDistance; i = i - 1) {
			if (i < 0 || i>10) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid->getRoadsGrid(x, i) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid->getVehicleGrid(x, i) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;

	}
	case(West): {
		for (int i = x; i <= x - StoppingDistance; i = i - 1) {
			if (i < 0 || i>10) {
				return false; // checks if vehicle remains in sim boundray
			}

			if (grid->getRoadsGrid(i, y) == nullptr) {
				return false; // checks if their is road the whole path 
			}

			if (grid->getVehicleGrid(i, y) != nullptr) {
				return false; // checks if vehicle is already on path
			}
			// will need to add signals but cant at moment cuz we havent done that yet
		}
		return true;

	}
	}
}