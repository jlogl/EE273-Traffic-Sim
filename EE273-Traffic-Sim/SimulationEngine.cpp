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

void SimulationEngine::step()


{
	current_time =current_time+timestep;
	std::vector<Vehicle*>& v = Grid->getVehicles();
	std::vector<Junction*>& j = Grid->getJunctions();

	for (Junction* i : j) {
		i->SetJunctionPointers(*Grid);


	}
	for (Junction* i : j) {

		i->UpdateJunction(*Grid);

	}


	for (Vehicle* i : v) {
		i->UpdateSpeed();

	}
	for (Vehicle* i : v) {
		i->UpdateMovement();

	}

	

	//std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // simulate time delay for each timestep, the chrono library allows for the program to interact with real world time and the this_thread 
	// namespace allows us to interact with this thread of code, found on C++ forum.
	



}

void SimulationEngine::reset()
{
   //same as the update function but revert back to initial conditions, unsure if this means we need to keep a log of initial conditions for each of the objects 
	std::vector<Vehicle*>& v = Grid->getVehicles();
	std::vector<Junction*>& j = Grid->getJunctions();
	current_time = initial_time;
	

	for (Vehicle* i : v) {

		i->ResetVehicle();
		
	}
	for (Junction* i : j) {

		i->resetUses();
	}
	
	
	
}



bool SimulationEngine::save(std::string filename)
{

	std::vector<Vehicle*>& v = Grid->getVehicles();
	std::vector<std::tuple<int, int, int, int, int>>& R=Grid->getRoads();
	
	std::ofstream outFile(filename);
	if (!outFile) {
		
		return false;
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
		outFile << "V," << i->getX() << "," << i->getY() << "," << i->getVehicleType() << "," << AorB << ',' << i->getDistance() << ',' << std::endl;
			
			
	}
		

		outFile.close();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears stream of characters

		return true;
}
bool SimulationEngine::load(std::string filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		return false;
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
			this->setInitialTime(number);
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
			
				if (data[3] == 1) {
					Grid->getVehicleGrid(data[0], data[1]).VehicleA->setInitialDistance(data[4]);
					Grid->getVehicleGrid(data[0], data[1]).VehicleA->resetDistance();
				}
				else {
					Grid->getVehicleGrid(data[0], data[1]).VehicleB->setInitialDistance(data[4]);
					Grid->getVehicleGrid(data[0], data[1]).VehicleB->resetDistance();
				}
				break;
		}


		}
		

	}
	inFile.close();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears stream of characters, 
	return true;
}


