#include "Roads.h"
#include "SimulationEngine.h"
#include <iostream>


void Roads::CreateRoad(int initial_x, int initial_y, int final_x, int final_y, int speed_limit,int number_of_lanes){

	if (initial_x != final_x || initial_y != final_y) {
		std::cout << "Diagonal road not supported" << std::endl;
		return;
	}
	if (initial_x == final_x || initial_y == final_y) {
		std::cout << "This isn't a road " << std::endl;
		return;
	}
	if (initial_x == final_x) {
		if (initial_y < final_y) {
			for (int i = initial_y; i < final_y; i = i + 1) {
					SimulationEngine
				}


			}


		}
		else {


		}

		
	}







} 