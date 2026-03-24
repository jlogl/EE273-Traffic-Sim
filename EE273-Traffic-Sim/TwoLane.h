#pragma once

#pragma once
#include "Roads.h"
#include "Grids.h"
#include "Direction_enum.h"

class TwoLane : public Roads {

public:
	TwoLane(int x, int y, int max_speed, direction Direction) {
		x_coordinate = x;
		y_coordinate = y;
		speed_limit = max_speed;
		direction_a = Direction;
		switch (direction_a) {		// set direction_b to opposite of direction_a
		case North:
			direction_b = South;
		case East:
			direction_b = West;
		case South:
			direction_b = North;
		case West:
			direction_b = East;
		}
	}
	~TwoLane() {}

	int getSpeedLimit();
	int getX();
	int getY();
	int getNumberOfLanes();
	direction getDirection();


private:
	int speed_limit; // Wont be measured in m/s, will be squares/tick so speeds will be low number like 1 or 2
	int x_coordinate; //holds data on where the road is on the grid in x direction which is defined as left to right
	int y_coordinate; //holds data on where the road is on the grid un y direction which is defined as down to up
	const int number_of_lanes = 2; // may only be one or 2 to signify a one way or two way road
	enum direction direction_a;		// direction that traffic is permitted to flow
	enum direction direction_b;		// parallel and opposite to direction a
};