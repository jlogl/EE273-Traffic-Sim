#pragma once
#include "Direction_enum.h"
#include "Type_enum.h"

class Grids;
class SimulationEngine;
class Vehicle {
public:



	Vehicle(int x, int y,Grids& grid);
	~Vehicle();

	/*
	 * @ brief - Function checks if vehicle is in a unsafe slot depending on
	 * current speed and distance to stationary objects and corrects their behaviour
	 * is so to allow them to function properly
	 *
	 *
	 * @ return bool - True if it has been used, False if vehicles speed remains unaltered
	 */
	bool SafetyOverride();

	/*
	* @ brief - using Safety Override, corrects any unsafe behaviour and alters vehicles speed, using
	* vehicle type base values
	*/
	void UpdateSpeed();

	/*
	* @ brief - Used to carry out the changes made in UpdateSpeed, adding the current speed to the direction of
	* travel for the vehicle
	*/
	void UpdateMovement();

	/*
	* @ brief - Returns Vehicle to initial position and initial speed of 0 on grid from start of simulation which is either t=0 or 
	* when a simulation has been loaded what the saved time was. 
	*/
	
	void ResetVehicle();

	/*
	* @ return type - Is a user defined Enum for the type of vehicle a object is, allows for more readable code
	*/
	type getVehicleType();

	/*
	* @ brief - Determines is the stopping distance of a vehicle is safe, by carry out the following checks in this order
	* - Will car go off grid?
	* - Is path ahead a road?
	* - Is their a Junction Ahead on path 
	* - Is their a red light ahead // MAY NEED TO CHANGE MAKING THIS LONG AND CAPITAL SO IT STANDS OUT AND REMEMBER TO CHANGE!!!!!
	* - Is their a vehicle ahead
	* 
	* @ return bool - True is the stopping distance of vehicle is safe, False is stopping distance isnt safe
	*/
	bool isStoppingDistanceSafe();

	/*
	* @ return direction - Is a user defined Enum for the Direction a vehicle is travelling or the direciton a road points in 
	*/
	direction getInitialVehicleDirection();

	/*
	* @ brief - Determines when a vehicle is placed which direction it will travel, depends on the road its placed on. 
	* 
	* @ param AorB - terminoligy of A or B is used throughout code, refering to the lane which a vehicle is in 
	* A always means either the lane going North or East dependent on if a road is vertical or horizontal and B 
	* means South or West respectivly. True Means Lane A and False means Lane B.
	*/
	void setInitialVehicleDirection( bool AorB);

	/*
	* @ return direction - Is a user defined Enum for the Direction a vehicle is travelling or the direciton a road points in
	*/
	direction getVehicleDirection();

	/*
	* @ brief - Determines depending on the current road a car is on what way it travels 
	*
	* @ param AorB - terminoligy of A or B is used throughout code, refering to the lane which a vehicle is in
	* A always means either the lane going North or East dependent on if a road is vertical or horizontal and B
	* means South or West respectivly. True Means Lane A and False means Lane B.
	*/
	void setVehicleDirection( bool AorB);// allowed AorB since the road variable is defined using this fucntion


	/*
	* @ brief - calculates the stopping distance of a vehicle, to be 'safe' always rounds up making use of ceil()
	* function so that value is always at least the real stoppping distance
	* 
	* @ return int - stoppping distance of vehicle
	*/
	int getStoppingDistance(); 
	
	/* @ return int - current speed of a vehicle 
	*/
	int getCurrentSpeed();

	/* @ Brief - sets the speed of vehicle
	*
	* @ param speed - value which speed will be set to 
	*/
	void setCurrentSpeed(int speed);

	/* @ return int - current x position of vehicle
	*/
	int getX();

	/* @ return int - current y position of vehicle
	*/
	int getY();

	/* @ return int - initial x position of vehicle
	*/
	int getInitialX();

	/* @ return int - initial y position of vehicle
	*/
	int getInitialY();
	
	/* @ return int - distance vehicle travels over course of simulation
	*/
	int getDistance();

	/* @ brief - adds one to the distance travelled for a vehicle, used 
	* for junctions as the car is moving but due to the junction, not its speed
	*/
	void addDistance();

	/* @ brief - Resets the distance to either 0 or the initial distance traveled
	from a saved simulation*/
	void resetDistance();

	/* @ brief - Sets the initial distance travelled by a vehicle, used when loading a previous simulation
	*
	*  @ param int - what the initial distance is set at
	*/
	void setInitialDistance(int i);

	/* @ brief - determines what the average speed of the vehicle throughout the simulation is using v=d/t
	*
	*  @ param SimulationEngine - provides a reference to the simulation engine so that the current time may be accsesed
	*/
	double getAverageSpeed(SimulationEngine& engine);

	/* @ brief - sets the x coordinate of vehicle
	*
	*  @ param int - what the x coordinate will be set as
	*/
	void setX(int x);

	/* @ brief - sets the y coordinate of vehicle
	*
	*  @ param int - what the y coordinate will be set as
	*/
	void setY(int y);


protected: // means inherited classes gain variables but still arent available to main/ other classes - encapsulation
	
	int max_speed{}; // will be defined by type 
	int current_speed;
	int x; // x coordinate at current time 
	int y; // y coordinate at current time
	int const x_initial; // x coordinate when created
	int const y_initial; // y coordinate when created
	int const speed_initial; // is always zero as most realistic vehicles start at 0
	int acceleration{}; // needed to model the movement of the vehicle
	int deceleration{}; // needed to model the movement of the vehicle
	direction InitialDirection; // tells us which way car was moving when initilalised
	direction Direction; // tells us what way the car should move, will get from road pointer which vehicle is on
	type Type{ none }; // allows us to know what vehicle type a object is
	int distance = 0; // keeps track of total distance travelled in real time and therefore allows us to calculate a vehicles average speed
	int initialDistance = 0; // used so that when reset is called from a load of a simulation, the vehicles distance isnt set to 0
	Grids& grid; // reference to grid since most functions needed it

};