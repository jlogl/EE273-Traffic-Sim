#include "Bike.h"
Bike::Bike(int x, int y) :Vehicle(x, y) {

	max_speed = 2;
	acceleration = 1;
	deceleration = 2; // These values are purely hypothetical, unsure what model we using so just put values as placeeholders
	Type = type::bike;
}
