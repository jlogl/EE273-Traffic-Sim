#include "Vehicle.h"
#include "math.h"

Vehicle::Vehicle(int row, int col)
	:x(row), y(col), x_initial(row), y_initial(col), current_speed(0), speed_initial(0)
	/* needed to use initialiser list since it involves setting value of constants for initial variables
	The acceleration, deceleration and max speed will be set by the sub-classes as that is specific to the type of vehicle
	The direction is set to None as that is associated with the road which the vehicle is placed onto and as of now the vehicle isnt on a road*/
{
};
Vehicle::~Vehicle() {};
void Vehicle::UpdateVehicle() {};
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