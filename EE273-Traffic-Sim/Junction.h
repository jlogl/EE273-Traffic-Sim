#pragma once
#include "Roads.h"
#include "Type_enum.h"
#include <vector>


class Grids;
class Vehicle;
class Junction :public Roads{
public:
	Junction(int x,int y,Grids& grid);
	~Junction();

	/* @ brief - returns the type of a jucntion in the for of a Enum, which is used to make the code easier to read /understand */
	junction getJunctionType();

	/* @ brief - Defines the pointers around a junction, these are the first step in the junction process. The surrounding pointers for every junction 
	* are obtained prior to any junctions updating the surroundings vehicles as we want the pointers for every junction to be taken from the same vehicle layout as
	* an attempt to make the order that the junction update in not matter
	*
	* @ param grid - allows for the data surrounding the junction to be obtained
	*/
	void SetJunctionPointers(Grids& grid);

	/* @ brief - Updates the movement around a junction depending on the type and orientation of the junction. 
	*
	*  @ virtual - this means that the subclasses which inherit this function have the ability to override it, allowing it to determine their junctions procedure 
	*  accordingly whilsit this single junciton being called and using the correct version depending on the type.
	* 
	*  @ param grid - allows for the data surrounding the junction to be obtained
	*/
	virtual void UpdateJunction(Grids& grid); 

	/* @ brief - Defines the type of a junction depending on the amount of roads which are converging at that point on the grid as well as checking if this is actually a 
	* junction or just a road. The assignment is as follows:
	* 1 connection - Turn
	* 2 connections - Either Corner or Road depending on if the roads converging are perpendicular or parallel 
	* 3 connections - T-junction
	* 4 connections - Cross junciton
	* 
	* @ param grid - allows for the data surrounding the junction to be obtained
	*/
	void setType(Grids& grid);

	/* @ brief - Allows objects outside of the class identify the oreintation of the junction which is defined by 4 bool variables which tell us if their is a road in a 
	* direction. Using this data its possible to tell where vehicle pointer should go when they enter the jucntion from a specific road.
	*
	* @ return std::vector<bool> - returns a vector of all of the check variable in the order of the compass starting at North and going clockwise. A example of these 
	* variables in use is if a junctions UpCheck and LeftCheck are True whereas the other two are false, we can tell this junction is a corner connecting a road coming
	* from above and to the left, allowing the correct branch of the update function of corners to be called.
	*/
	std::vector<bool> Checks(); 

	/* @ brief - Returns the amount of times a junction has been used throughout a simulation, this data is not tracked across save files.
	*
	*  @ return int - How many times the junction has been used over the simulation
	*/
	int getUses();

	/* @ breif - Sets the amount of uses for a junction to 0, used inside of the reset feature of the simulation */
	void resetUses();
	
protected:
	bool UpCheck= false; // Identifies if their is a road above the junction
	bool LeftCheck = false;// Identifies if their is a road left of the junction
	bool DownCheck = false;// Identifies if their is a road below the junction
	bool RightCheck = false;// Identifies if their is a road right of the junction
	
	int totalUses=0; // Keeps Track of how many times the jucntion has been used. 
	
	junction Type; // The type of Junction as a Enum
	
	Vehicle* UpApproach =nullptr; // Pointer to Vehicle at point above junction, approaching the junction
	Vehicle* UpLeave = nullptr; // Pointer to Vehicle at point above junction, leaving the junction

	Vehicle* LeftApproach = nullptr; // Pointer to Vehicle at point left of junction, approaching the junction
	Vehicle* LeftLeave = nullptr; // Pointer to Vehicle at point above junction, leaving the junction

	Vehicle* DownApproach = nullptr; // Pointer to Vehicle at point below junction, approaching the junction
	Vehicle* DownLeave = nullptr; // Pointer to Vehicle at point above junction, leaving the junction

	Vehicle* RightApproach = nullptr; // Pointer to Vehicle at point right of junction, approaching the junction
	Vehicle* RightLeave = nullptr; // Pointer to Vehicle at point above junction, leaving the junction
};