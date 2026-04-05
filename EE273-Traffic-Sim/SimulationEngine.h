#pragma once
#include <string>
#include "Grids.h"





class SimulationEngine
{
public:
	SimulationEngine(Grids* grid);
	~SimulationEngine();
	void run(int number_of_steps);
	void reset();
	void step();
	void save();
	void load(std::string filename);
	double getCurrentTime();
	
	void setCurrenttime(double time);
	void setInitialtime(double time);

	
private:
	Grids* Grid;
	double timestep;
	double current_time;
	double initial_time;
};