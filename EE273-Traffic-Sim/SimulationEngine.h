#pragma once
#include <string>




class Grids;

class SimulationEngine
{
public:
	SimulationEngine(Grids* grid);
	~SimulationEngine();

	/* @ brief - Restores the simulation to initial state, with this being either time = 0 for a new simulation 
	* or at the time set by a loaded file as a simulation isnt able to back to before a save file. For example if a 
	* load file sets the time to 2, that is now the initial time*/
	void reset();

	/* @ brief - Causes the simualtion to take a single timestep, meaning time = time+1, this also causes changes 
	* throughout the simualtion to be made such as jucntions updating and cars moving, no need for a "run" funciton
	* as you can just loop steps*/
	void step();

	/* @ brief - outputs all necessary data to recreate simulation into a .txt file, this consists of the current time, 
	* each of the input parameters for createVehicle and CreateRoad, so the network may be recreated when the program is ran 
	* again.
	* 
	*  @ param std::string filename - this is the name of the file that will either be created or overridden
	*/
	bool save(std::string filename);

	/* @ brief - converts a save file created using the save feature into the simulation, this is done by breaking each 
	* line up using stringstream which then allows for the create functions to be called. 
	*
	*  @ param std::string filename - this is the name of the save file which be used
	*/
	bool load(std::string filename);

	/* @ return int - returns the current time of the simulation  */
	int getCurrentTime();
	
	/* @ return int - returns the initial time of the simulation, either 0 for a new sim or whatever a save file \
	* sets it as  */
	int getInitialTime();

	/* @ brief - sets the current time of the simulation
	* 
	*  @ param time - what the current time will be set to.
	*/
	void setCurrentTime(int time);

	/* @ brief - sets the initial time of the simulation
	*
	*  @ param time - what the initial time will be set to.
	*/
	void setInitialTime(int time);

	
private:
	Grids* Grid;
	int timestep;
	int current_time;
	int initial_time;
};