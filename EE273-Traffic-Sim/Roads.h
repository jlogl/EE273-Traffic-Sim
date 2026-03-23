#pragma once

#include "Direction_enum.h"

class Roads {

public:
	Roads(int x , int y ,int max_speed,direction Direction ,int lanes = 1 ) {
		x_coordinate = x;
		y_coordinate = y;
		speed_limit = max_speed;
		number_of_lanes = lanes; // to ensure that number of lanes is always either 1 or 2, could use bool expression instead
		direction_of_road = Direction;
	}
	~Roads(){}
	
	int getSpeedLimit();
	int getX();
	int getY();
	int getNumberOfLanes();
	direction getDirection();


private:
	int speed_limit; // Wont be measured in m/s, will be squares/tick so speeds will be low number like 1 or 2
	int x_coordinate; //holds data on where the road is on the grid in x direction which is defined as left to right
	int y_coordinate; //holds data on where the road is on the grid un y direction which is defined as down to up
	int number_of_lanes; // may only be one or 2 to signify a one way or two way road
	direction direction_of_road;// tells us what direction a car will travel on the road, means that direction isnt associated with speed

};
	



	