#pragma once
#include "Grids.h"

class Roads {

public:
	Roads(int x , int y ,int max_speed,int lanes = 1 ) {
		x_coordinate = x;
		y_coordinate = y;
		speed_limit = max_speed;
		number_of_lanes = lanes; // to ensure that number of lanes is always either 1 or 2, could use bool expression instead

	}
	~Roads(){}
	/*void CreateRoad(Grids Grid,int initial_x, int initial_y, int final_x, int final_y,int speed_limit,int number_of_lanes);*/
	int getSpeedLimit();


private:
	int speed_limit; // Wont be measured in m/s, will be squares/tick so speeds will be low number like 1 or 2
	int x_coordinate; //holds data on where the road is on the grid in x direction which is defined as left to right
	int y_coordinate; //holds data on where the road is on the grid un y direction which is defined as down to up
	int number_of_lanes; // may only be one or 2 to signify a one way or two way road
	

};
	



	