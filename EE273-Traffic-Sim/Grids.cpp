

#include"Grids.h"
#include "Direction_enum.h"

#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"

Grids::Grids() {
	
	}


/* First approach invloved doing same process for Vehicle_Grid as Road_Grid, iterating over each spot and deleting VehicleA and VehicleB but the heap didnt like this
and gave a erorr window which when asking google informed me that a pointer was being deleted twice, after troubleshooting the destructor I found that it was the vehicle which
was causing this window to pop up since when only doing it with Road it worked fine.

had to do research into how destructors work and looking at StackOverflow I realised this was caused due to us creating a vector storing pointers to ALL vehicle objects and that
each of these had to be deleted since they were all created using new. Tried iterating over vector rather than grid and it worked. */

Grids::~Grids() {
						
	for (Vehicle* i : vehicle_on_grid) {
		delete i;
	}
	

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			delete Road_Grid[i][j].RoadA;
			delete Road_Grid[i][j].RoadB;
		}
	}
}

Roads_Grid_Slot Grids::getRoadsGrid(int x, int y) {
	return Road_Grid[x][y];

};
void Grids::setRoadsGrid(int x, int y, Roads* value) {

	direction D = value->getDirection();
	int SL = value->getSpeedLimit();
	direction D2;
	switch (D) {
	case(North): {
		D2 = South;
		break;
	}
	case(East): {
		D2 = West;
		break;
	}
	case(South): {
		D2 = North;
		break;
	}
	case(West): {
		D2 = East;
		break;
	}
	}
	Roads* R2 = new Roads(x, y, SL, D2);
	
	Road_Grid[x][y].RoadA = value;
	Road_Grid[x][y].RoadB = R2;
};
Vehicle_Grid_Slot Grids::getVehicleGrid(int x, int y) {
	return Vehicle_Grid[x][y];
};
void Grids::setVehicleGrid(int x, int y, Vehicle* value,bool A_or_B) {
	if (A_or_B) {
		Vehicle_Grid[x][y].VehicleA = value;
	}
	else {
		Vehicle_Grid[x][y].VehicleB = value;
	}
};
std::vector<Vehicle*>& Grids::getVehicles() {
	return vehicle_on_grid;
}

/* these getters and setters are used to interact with a single cell in each grid*/

void Grids::PrintGrids() {
	for (int i = Grids::grid_size - 1; i >= 0; i = i - 1) { // overall layout may not make sense but layout inverts y axis and makes x actually equal x in terms of x,y order 
		 
			std::stringstream ss;
			if (i < 10)
				ss << "0" << i << "|";
			else
				ss << i << "|";
			for (int j = 0; j <= Grids::grid_size - 1; j = j + 1) {


				if (Road_Grid[j][i].RoadA == nullptr) {
					ss << " 0";
				}
				else {
					ss << " R";
				}
				if (Road_Grid[j][i].RoadB == nullptr) {
					ss << "0 ";
				}
				else {
					ss << "R ";
				}
			}

			std::string result = ss.str();
			std::cout << result << std::endl;
		
		


	}

	
	for (int i = 0; i < Grids::grid_size; i = i + 1) {
		if (i == 0) {

			std::cout << "   ";
		}
		
		std::cout << "----";

	}
	std::cout << std::endl;


	for (int i = 0; i < Grids::grid_size; i = i + 1) {
		if (i == 0) {

			std::cout << "   ";
		}
		
		if (i < 10) {

			std::cout << " 0" << i <<  " ";
		}
		else {

			std::cout << " " << i << " ";

		}

	}
	std::cout << std::endl<<std::endl;
	
	for (int i = Grids::grid_size - 1; i >= 0; i = i - 1) {
		std::stringstream ss; 
		if (i < 10) // allows for label of y-axis, would need to scale if we ever set the grid size above 100x100 but i cant see that being needed
			ss << "0" << i << "|";
		else
			ss << i << "|";
		for (int j = 0; j <= Grids::grid_size - 1; j = j + 1) {
			

				if (Vehicle_Grid[j][i].VehicleA == nullptr) {

					ss << " 0";
				}
				else {
					if (Vehicle_Grid[j][i].VehicleA->getVehicleType() == car) {

						ss << " C";
					}

					if (Vehicle_Grid[j][i].VehicleA->getVehicleType() == bus) {

						ss << " B";
					}
					if (Vehicle_Grid[j][i].VehicleA->getVehicleType() == bike) {

						ss << " A";
					}
				}
			
			

			if (Vehicle_Grid[j][i].VehicleB == nullptr) {
				ss << "0 ";
			}
			else {
				if (Vehicle_Grid[j][i].VehicleB->getVehicleType() == car) {

					ss << "C ";
				}

				if (Vehicle_Grid[j][i].VehicleB->getVehicleType() == bus) {

					ss << "B ";
				}
				if (Vehicle_Grid[j][i].VehicleB->getVehicleType() == bike) {

					ss << "A ";
				}


			}
			
		}
		
		std::string result = ss.str();
		std::cout << result << std::endl;
		
	}
	for (int i = 0; i < Grids::grid_size; i = i + 1) {
		if (i == 0) {

			std::cout << "   ";
		}

		std::cout << "----";

	}
	std::cout << std::endl;


	for (int i = 0; i < Grids::grid_size; i = i + 1) { // loop to label x-axis so that it scales when grid size changes
		if (i == 0) {

			std::cout << "   ";
		}

		if (i < 10) {

			std::cout << " 0" << i << " ";
		}
		else {

			std::cout << " " << i << " ";

		}

	}
	std::cout << std::endl;
	
}
void Grids::CreateRoad(int initial_x, int initial_y, int final_x, int final_y, int speed_limit) {
	if (initial_x != final_x && initial_y != final_y) {
		std::cout << "Diagonal road not supported" << std::endl;
		return;
	}
	if (initial_x == final_x && initial_y == final_y) {
		std::cout << "This isn't a road " << std::endl;
		return;
	}




	if (initial_x == final_x) {

		for (int i = initial_y; i <= final_y; i = i + 1) {
			Roads* road_object = new Roads(initial_x, i, speed_limit, North);

			setRoadsGrid(initial_x, i, road_object);
		}




	}
	else {
		if (initial_x < final_x) {

			for (int i = initial_x; i <= final_x; i = i + 1) {

				Roads* road_object = new Roads(i, initial_y, speed_limit, East);

				setRoadsGrid(i, initial_y, road_object);
			}

		}




	}
}


void Grids::CreateVehicle(int x, int y,type type_of_vehicle,bool A_or_B) {
		
	if (A_or_B) {

		if (Road_Grid[x][y].RoadA == nullptr) {

			std::cout << "No road at coordinate " << x << "," << y << std::endl;
			return;
		}
		if (Vehicle_Grid[x][y].VehicleA != nullptr) {
			std::cout << "Vehicle already exists in this lane at coordinate " << x << "," << y << std::endl;
			return;

		}
	}
	else {
		if (Road_Grid[x][y].RoadB == nullptr) {

			std::cout << "No lane at coordinate " << x << "," << y << std::endl;
			return;
		}
		if (Vehicle_Grid[x][y].VehicleB != nullptr) {
			std::cout << "Vehicle already exists in this lane at coordinate " << x << "," << y << std::endl;
			return;

		}
	}



	

	Vehicle* v;
	
	switch (type_of_vehicle) {

		case car: {
			v = new Car(x,y);
			setVehicleGrid(x,y,v,A_or_B);
			v->setVehicleDirection(*this,A_or_B);
			vehicle_on_grid.push_back(v);
			
			break;
		}
		case bus: {
			v = new Bus(x,y);
			setVehicleGrid(x,y,v, A_or_B);
			v->setVehicleDirection(*this, A_or_B);
			vehicle_on_grid.push_back(v);
			break;
		}
		case bike: {
			v = new Bike(x,y);
			setVehicleGrid(x,y,v, A_or_B);
			v->setVehicleDirection(*this, A_or_B);
			vehicle_on_grid.push_back(v);
			break;

		}
		
	}

}