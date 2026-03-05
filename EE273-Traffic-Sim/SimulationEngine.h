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

private:
	double timestep;
	double current_time;
	double initial_time;






};