#include "SimulationEngine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "Grids.h"
SimulationEngine::SimulationEngine(Grids* grid)
{
	Grid = grid; // had to add to simulation in order for engine to have acsess to the grid, allowing for the vehicle vector to be used to iterate
	current_time = 0;
	timestep = 1;
	initial_time = 0;

}
SimulationEngine::~SimulationEngine()
{
}
double SimulationEngine::getCurrentTime() {
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
	
	if (number_of_steps <= 0) {
		std::cout << "Invalid Inputs defined" << std::endl; // The Simulation should always have a Positive number of steps, this prevents their being zero or negative steps
		return;
	}
	//std::cout << "Simulation running for " << number_of_steps << " steps" << std::endl;

	int count = 1;
	do {
		// update simulation station each timestep, i think this should be a function defined in the classes for each type of object like car or road
		// maybe create a object class at top of hierarchy of all the other classes, this would allow us to iterate over a array of objects which is every entity in simulation
	
		current_time += timestep;
		std::cout << "Current time: " << current_time << std::endl;
		std::vector<Vehicle*>& v = Grid->getVehicles();

		int size = v.size();
		for (Vehicle* i:v) {
			i->UpdateSpeed(*Grid);
			
		}
		for (Vehicle* i :v) {
			i->UpdateMovement(*Grid);

		}
		
		Grid->PrintGrids(); // WILL NEED TO BE JOB OF UI, JUST TEMPORARY TO SHOW IT WORKS

		
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate time delay for each timestep, the chrono library allows for the program to interact with real world time and the this_thread 
		// namespace allows us to interact with this thread of code, found on C++ forum.
		count=count+1;


	} while (count <= number_of_steps);
	//std::cout << "Simulation complete" << std::endl; // These cout's are just for testing, i am unsure if we need to set the communication outside the engine
	return;
}

void SimulationEngine::step()

{
	
	// update simulation station each timestep, i think this should be a function defined in the classes for each type of object like car or road
	// maybe create a object class at top of hierarchy of all the other classes, this would allow us to iterate over a array of objects which is every entity in simulation

	//current_time += timestep;
	//std::cout << "Current time: " << current_time << std::endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	//std::cout << "step complete" << std::endl;
	SimulationEngine::run(1);

}

void SimulationEngine::reset()
{
   //same as the update function but revert back to initial conditions, unsure if this means we need to keep a log of initial conditions for each of the objects 
	std::vector<Vehicle*>& v = Grid->getVehicles();
	current_time = initial_time;
	
	std::cout << "reset complete" << std::endl;
	std::cout <<"Current time: " << current_time << std::endl;
	for (Vehicle* i : v) {

		i->ResetVehicle();
	}
	
}


/*  This is the most work in progress part and will constantly need to be altered and reworked as the complexity of the simulation progresses */
void SimulationEngine::save()
{
	std::string filename;
	std::cout << "Please enter filename to save simulation to: " << std::endl;
	std::cin >> filename;
	std::vector<Vehicle*>& v = Grid->getVehicles();
	
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Error opening file:"
			<< filename << "\n";
		return;
	}

		outFile << getCurrentTime() << std::endl;
		for (Vehicle* i : v) {
			outFile << i->getX() << "," << i->getY() << "," << i->getVehicleType() << std::endl;
		}
		

		outFile.close();

}
void SimulationEngine::load(std::string filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error opening file:"
			<< filename << "\n";
		return;
	}
	std::string line;
	(getline(inFile, line)); // Is not in a loop as we only want the first line to be used for the purpose of setting the time
		setCurrenttime(stoi(line));
		setInitialtime(stoi(line));

		inFile.close();

	}


