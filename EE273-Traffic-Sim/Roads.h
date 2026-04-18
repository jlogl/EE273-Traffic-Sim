#pragma once

#include "Direction_enum.h"
#include "Signal.h"
#include <vector>

class Roads {

public:
	Roads();
	Roads(int x, int y, int max_speed, direction Direction);
	~Roads();
	
	int getSpeedLimit();
	int getX();
	int getY();

	direction getDirection();
	void setDirection(direction D);// DO NOT CALL THIS FUNCTION IN MAIN 
	bool isRoad();

protected:
	
	int x_coordinate; //holds data on where the road is on the grid in x direction which is defined as left to right
	int y_coordinate; //holds data on where the road is on the grid un y direction which is defined as down to up
	bool IsRoad=1;
	std::vector<Signal*> signals;

private:
	enum direction direction_of_road=None;
	int speed_limit; // Won't be measured in m/s, will be squares/tick so speeds will be low number like 1 or 2
};
