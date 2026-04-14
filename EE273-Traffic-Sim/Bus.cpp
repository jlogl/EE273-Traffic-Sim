#include "Bus.h"

Bus::Bus(int x,int y):Vehicle( x , y){ // ensures that the position is correct

	max_speed = 3;
	acceleration = 1;
	deceleration = 1; // These values are purely hypothetical, unsure what model we using so just put values as placeeholders
	Type = type::bus;

}
Bus::~Bus() {


}