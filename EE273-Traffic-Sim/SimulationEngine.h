#pragma once
#include <string>




class Grids;

class SimulationEngine
{
public:
	SimulationEngine(Grids* grid);
	~SimulationEngine();

	void reset();
	void step();
	bool save(std::string filename);
	bool load(std::string filename);
	int getCurrentTime();
	int getInitialTime();
	void setCurrentTime(int time);
	void setInitialTime(int time);

	
private:
	Grids* Grid;
	int timestep;
	int current_time;
	int initial_time;
};