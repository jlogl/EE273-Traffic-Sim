#pragma once
#include <string>


class SimulationEngine
{
public:
	SimulationEngine();
	~SimulationEngine();
	void run(int number_of_steps);
	void reset();
	void step();
	void save();
	void load(std::string filename);
	double getCurrenttime();
	void setCurrenttime(double time);
	void setInitialtime(double time);
	int grid[10][10]{ 0 };
private:
	double timestep;
	double current_time;
	double initial_time;
};