#pragma once
#include <string>




class Grids;

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
	int getCurrentTime();
	int getInitialTime();
	void setCurrentTime(int time);
	void setInitialTime(int time);

	
private:
	Grids* Grid;
	double timestep;
	double current_time;
	double initial_time;
};