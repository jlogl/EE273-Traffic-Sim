#include "SimulationEngine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include "Grids.h"
#include "Vehicle.h"
#include "Junction.h"
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
int SimulationEngine::getCurrentTime() {
	return current_time;

}
int SimulationEngine::getInitialTime() {
	return initial_time;

}

void SimulationEngine::setCurrentTime(int time) {
	 current_time = time;
};
void SimulationEngine::setInitialTime(int time) {
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
		std::vector<Vehicle*>& v = Grid->getVehicles();
		std::vector<Junction*>& j = Grid->getJunctions();
		for (Junction* i : j) {

			i->UpdateJunction(*Grid);

		}
	
	
		for (Vehicle* i:v) {
			i->UpdateSpeed(*Grid,*this);
			
		}
		for (Vehicle* i :v) {
			i->UpdateMovement(*Grid);

		}
		
		std::cout << "After movement" << std::endl;
		Grid->PrintGrids(*this); // WILL NEED TO BE JOB OF UI, JUST TEMPORARY TO SHOW IT WORKS
		
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

	for (Vehicle* i : v) {

		i->ResetVehicle(*Grid);
	}
	Grid->PrintGrids(*this );
	
}


/*  This is the most work in progress part and will constantly need to be altered and reworked as the complexity of the simulation progresses */
void SimulationEngine::save()
{
	std::string filename;
	std::cout << "Please enter filename to save simulation to: " << std::endl;
	std::cin >> filename;
	std::vector<Vehicle*>& v = Grid->getVehicles();
	std::vector<std::tuple<int, int, int, int, int>>& R=Grid->getRoads();
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Error opening file:" 
			<< filename << "\n";
		return;
	}

	
	
	
	
	outFile << "T," << getCurrentTime() << std::endl;

	for (std::tuple<int, int, int, int, int> i : R) {
		outFile << "R," << std::get<0>(i) << "," << std::get<1>(i) << "," << std::get<2>(i) << ","
			<< std::get<3>(i) << "," << std::get<4>(i) << "," << std::endl;


	}
	for (Vehicle* i : v) {
			
			direction D = i->getVehicleDirection();
			bool AorB;
		switch (D) {

			case(North): {
				AorB = true;
				break;
			}
			case(East): {
				AorB = true;
				break;
			}
			case(South): {
				AorB = false;
			}
			case(West): {
				AorB = false;
				break;
			}
		}
		outFile << "V," << i->getX() << "," << i->getY() << "," << i->getVehicleType() <<"," << AorB << std::endl;
			
			
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
	std::string identifier;
	std::stringstream ss;
	std::string num;
	while ((getline(inFile, identifier))) {
		

		char id = identifier[0];
		std::stringstream ss(identifier);

		switch (id) {
		case('T'): {
			
			int count = 0;
			int number = 0;
			while (getline(ss, num, ',')) {
				
				if (count > 0) {// we use the count as a way to get around the first increment in the line
					number = stoi(num);
				}
				count++;
			}
			// since the layout of the set and create functions are set, they can be hard wired from the elements of the data vector
			this->setCurrentTime(number);
			break;
		
		}
		case('R'): {
			int count = 0;
			std::vector<int> data;
			int number = 0;
			while (getline(ss, num, ',')) {
			
				if (count > 0) {// we use the count as a way to get around the first increment in the line
					number = stoi(num);
					data.push_back(number); // could use array since number of elements is known but this is more convienent
				}
				count++;
	
			}
			Grid->CreateRoad(data[0], data[1], data[2], data[3], data[4]);
			break;
		}
		case('V'): { // needs to be last as road network should be made prior to vehicles
			
			int count = 0;
			std::vector<int> data;
			int number = 0;




			while (getline(ss, num, ',')) {

				if (count > 0) {// we use the count as a way to get around the first increment in the line
					number = stoi(num);
					data.push_back(number); // could use array since number of elements is known but this is more convienent
				}
				count++;
			}

			type t;
			switch (data[2]) { // since we know the layout of the save file, we can always assume this wont be a number above 3

	
				case(0): {
						t = car;
						break;
				}
				case(1): {
						t = bus;
						break;
				}
				case(2): {
						t = bike;
						break;
				}
				case(3): {
						t = none;
						break;
				}
			}
				Grid->CreateVehicle(data[0], data[1], t, data[3]);
				break;
		}


		}
		

	}
	inFile.close();
}


