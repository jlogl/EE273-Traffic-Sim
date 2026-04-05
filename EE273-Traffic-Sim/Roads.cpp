
#include <iostream>
#include "Roads.h"



Roads::~Roads() {

}
int Roads::getSpeedLimit() {

	return speed_limit;
}

int Roads::getX() {

	return x_coordinate;
}

int Roads::getY() {

	return y_coordinate;
}



direction Roads::getDirection() {

	return direction_of_road;
}


