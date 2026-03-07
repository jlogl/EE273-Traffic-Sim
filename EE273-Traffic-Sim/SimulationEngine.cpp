#include "SimulationEngine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
SimulationEngine::SimulationEngine()
{
	current_time = 0;
	timestep = 1;
	initial_time = 0;
}
SimulationEngine::~SimulationEngine()
{
}
double SimulationEngine::getCurrenttime() {
	return current_time;

}
void SimulationEngine::setCurrenttime(double time) {
	 current_time = time;
};
void SimulationEngine::setInitialtime(double time) {
	initial_time = time;
};
void SimulationEngine:: run(int number_of_steps)
{
	std::cout << "Simulation running for "  <<number_of_steps<<" steps" << std::endl;
	if (number_of_steps <= 0) {
		std::cout << "Invalid Inputs defined" << std::endl; // The Simulation should always have a Positive number of steps, this prevents their being zero or negative steps
		return;
	}

	int count = 1;
	while (count<=number_of_steps) {
		// update simulation station each timestep, i think this should be a function defined in the classes for each type of object like car or road
		// maybe create a object class at top of hierarchy of all the other classes, this would allow us to iterate over a array of objects which is every entity in simulation
	
		current_time += timestep;
		std::cout << "Current time: " << current_time << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate time delay for each timestep, the chrono library allows for the program to interact with real world time and the this_thread 
		// namespace allows us to interact with this thread of code, found on C++ forum.
		count += 1;

	}
	std::cout << "Simulation complete" << std::endl; // These cout's are just for testing, i am unsure if we need to set the communication outside the engine
	return;
}

void SimulationEngine::step()

{
	
	// update simulation station each timestep, i think this should be a function defined in the classes for each type of object like car or road
	// maybe create a object class at top of hierarchy of all the other classes, this would allow us to iterate over a array of objects which is every entity in simulation

	current_time += timestep;
	std::cout << "Current time: " << current_time << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "step complete" << std::endl;

}

void SimulationEngine::reset()
{
   //same as the update function but revert back to initial conditions, unsure if this means we need to keep a log of initial conditions for each of the objects 

	current_time = initial_time;
	
	std::cout << "reset complete" << std::endl;
	std::cout <<"Current time: " << current_time << std::endl;
}


/*  This is the most work in progress part and will constantly need to be altered and reworked as the complexity of the simulation progresses */
void SimulationEngine::save()
{
	std::string filename;
	std::cout << "Please enter filename to save simulation to: " << std::endl;
	std::cin >> filename;

	
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Error opening file:"
			<< filename << "\n";
		return;
	}

		outFile << getCurrenttime() << std::endl;


	

}
void SimulationEngine::load(std::string filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error opening file:"
			<< filename << "\n";
		return;
	}
	std::string line;
	(getline(inFile, line));
		setCurrenttime(stod(line));
		setInitialtime(stod(line));



	}


