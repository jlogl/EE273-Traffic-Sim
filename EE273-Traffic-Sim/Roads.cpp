#include "Roads.h"
#include "SimulationEngine.h"
#include <iostream>

int Roads::getSpeedLimit() {

	return speed_limit;
}

int Roads::getX() {

	return x_coordinate;
}

int Roads::getY() {

	return y_coordinate;
}
int Roads::getNumberOfLanes() {

	return number_of_lanes;
}

direction Roads::getDirection() {

	return direction_of_road;
}


