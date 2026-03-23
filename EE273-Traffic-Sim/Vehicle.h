#pragma once
#include "Direction_enum.h"
#include "Type_enum.h"
class Vehicle {
public:
	Vehicle(int x, int y, int start_speed);
	~Vehicle();
	virtual void UpdateVehicle();
	virtual void ResetVehicle();
protected:
	int max_speed{}; // will be defined by type 
	int current_speed;
	int x; // position going left to right at current time 
	int y; // position going up and down at current time
	int const x_initial; // position going left to right when created
	int const y_initial; //position going up and down when created
	int const speed_initial;
	int acceleration{}; // needed to model the movement of the vehicle
	int deceleration{}; // needed to model the movement of the vehicle
	direction Direction{}; // tells us what way the car should move, will get from road pointer which vehicle is on
	type Type{ None }; // allows us to know what vehicle type a object is
	int getStoppingDistance(); // not virtual since every vehicle will use it unchaneged, however its protected since only used inside class
};