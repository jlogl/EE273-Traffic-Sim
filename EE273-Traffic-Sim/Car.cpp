#include "Car.h"

Car::Car(int x, int y) : Vehicle(x,y) {
	max_speed = 6;
	acceleration = 2;
	deceleration = 3; // These values are purely hypothetical, unsure what model we using so just put values as placeeholders
	Type = type::car;

}
Car::~Car() {


}