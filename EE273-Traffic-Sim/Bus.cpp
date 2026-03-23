#include "Bus.h"

Bus::Bus(int x,int y,int start_speed):Vehicle( x , y, start_speed){
	max_speed = 4;
	acceleration = 1;
	deceleration = 2; // These values are purely hypothetical, unsure what model we using so just put values as placeeholders
	Type = type::Bus;

}
Bus::~Bus() {


}