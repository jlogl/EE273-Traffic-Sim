#pragma once
#include "Direction_enum.h"
#include "Type_enum.h"

class Grids;
class SimulationEngine;
class Vehicle {
public:
	Vehicle(int x, int y);
	~Vehicle();
	
	void UpdateSpeed(Grids& grid,SimulationEngine& engine);
	void UpdateMovement(Grids& grid);
	void ResetVehicle(Grids& grid);
	type getVehicleType();
	bool isStoppingDistanceSafe(Grids& grid);
	direction getVehicleDirection();
	void setVehicleDirection(Grids& grid, bool A_or_B);// allowed A_or_B since the lane variable is defined using this fucntion
	int getStoppingDistance(); // not virtual since every vehicle will use it unchaneged, however its protected since only used inside class
	int getCurrentSpeed();
	void setCurrentSpeed(int speed);
	int getX();
	int getY();
	int getInitialX();
	int getInitialY();
	void setX(int x);
	void setY(int y);
	

protected:
	int max_speed{}; // will be defined by type 
	int current_speed;
	int x; // position going left to right at current time 
	int y; // position going up and down at current time
	int const x_initial; // position going left to right when created
	int const y_initial; //position going up and down when created
	int const speed_initial; // is always zero
	int acceleration{}; // needed to model the movement of the vehicle
	int deceleration{}; // needed to model the movement of the vehicle
	direction Direction; // tells us what way the car should move, will get from road pointer which vehicle is on
	type Type{ none }; // allows us to know what vehicle type a object is

};