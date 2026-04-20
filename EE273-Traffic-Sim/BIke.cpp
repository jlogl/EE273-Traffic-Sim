#include "Bike.h"
#include "Grids.h"
Bike::Bike(int x, int y,Grids& grid) :Vehicle(x, y,grid) {

	max_speed = 2;
	acceleration = 1;
	deceleration = 2; // These values are purely hypothetical, unsure what model we using so just put values as placeholders
	Type = type::bike;
	
}
Bike::~Bike() {


}
