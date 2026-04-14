
#include <iostream>
#include "Roads.h"
#include "Grids.h"
Roads::Roads() {};
Roads::Roads(int x, int y, int max_speed, direction Direction) {
	x_coordinate = x;
	y_coordinate = y;
	speed_limit = max_speed;
	direction_of_road = Direction;
	IsRoad = true;
}

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
void Roads::setDirection(direction D) {

	direction_of_road = D;
}


direction Roads::getDirection() {

	return direction_of_road;
}
bool Roads::isRoad() {
	return IsRoad;
}