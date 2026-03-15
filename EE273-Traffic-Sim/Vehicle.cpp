#include "Vehicle.h"
#include "math.h"
#include "Grids.h"
Vehicle::Vehicle(int row, int col, int start_speed)
	:x(row), y(col), x_initial(row), y_initial(col), current_speed(start_speed), speed_initial(start_speed) // needed to use initialiser list since it involves setting value of constants
{};
Vehicle::~Vehicle() {};
void Vehicle::UpdateVehicle() {};
void Vehicle::ResetVehicle() {};

int Vehicle::getStoppingDistance() {

	int stoppingDistance = 0;

	stoppingDistance = pow(current_speed, 2) / (2 * deceleration);

	return stoppingDistance;

}