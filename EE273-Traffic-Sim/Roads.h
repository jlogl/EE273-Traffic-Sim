#pragma once

class Roads {

public:
	void CreateRoad(int initial_x, int initial_y, int final_x, int final_y,int speed_limit,int number_of_lanes);



private:
	int speed_limit; // Wont be measured in m/s, will be squares/tick so speeds will be low number like 1 or 2;
	int length; // not sure yet maybe do start x, start y , end x, end y so tha path is known
	// Vector of vehicles to store data on the cars on the road

};
	



	