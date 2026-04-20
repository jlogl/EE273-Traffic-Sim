#pragma once

#include "Direction_enum.h"

class Roads {

public:
	Roads(); // default constructor for junctions
	Roads(int x, int y, int max_speed, direction Direction);
	~Roads();

	/* @ return int - the speed limit of a road
	*/
	int getSpeedLimit(); 
	
	/* @ return int - x positon of road
	*/
	int getX();

	/* @ return int - y positon of road
	*/
	int getY();

	/* @ brief - returns the direction of a road's lane
	* 
	* @ return direction - Is a user defined Enum for the Direction a vehicle is travelling or the direciton a road points in
	*/
	direction getDirection();

	/* @ brief - returns the direction of a road's lane
	* 
	* @ return direction - Is a user defined Enum for the Direction a vehicle is travelling or the direciton a road points in
	*/
	void setDirection(direction D);

	/* @ brief - allows for us to identify if a road object is actually a road or a junction
	*
	* @ return bool - True if object is road, False if object is Junction
	*/
	bool isRoad();

protected: //junctions require but may not be accsesed by main/ other classes
	
	int x_coordinate; //holds data on where the road is on the grid in x direction which is defined as left to right
	int y_coordinate; //holds data on where the road is on the grid un y direction which is defined as down to up
	bool IsRoad=1;

private: // junctions do not require
	enum direction direction_of_road=None;
	int speed_limit; // Won't be measured in m/s, will be squares/tick so speeds will be low number like 1 or 10
};
