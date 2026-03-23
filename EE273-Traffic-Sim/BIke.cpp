#include "Bike.h"
Bike::Bike(int x, int y, int start_speed) :Vehicle(x, y, start_speed) {

	max_speed = 2;
	acceleration = 1;
	deceleration = 2; // These values are purely hypothetical, unsure what model we using so just put values as placeeholders
	Type = type::Bike;
}
