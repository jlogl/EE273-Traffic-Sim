#pragma once
class Vehicle {
public:
	void UpdateVehicle();
	void ResetVehicle();
private:
	int max_speed; // as said on roads, the speed is in squares/tick
	int current_speed; // we assume a vehicle is going at max speed unless speed limit is less than current speed 
	int x_position_current; // position going left to right at current time 
	int y_position_current; // position going up and down at current time
	int const x_position_initial; // position going left to right when created
	int const y_position_initial; //position going up and down when created
};