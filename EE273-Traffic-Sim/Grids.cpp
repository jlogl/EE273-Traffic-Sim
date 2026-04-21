
#include <iostream>
#include <sstream>
#include <utility>
#include <tuple>
#include "Direction_enum.h"

#include"Grids.h"
#include "Vehicle.h"
#include "SimulationEngine.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"
#include "Roads.h"
#include "Junction.h"
#include "Turn.h"
#include "CornerJunction.h"
#include "TJunction.h"
#include "CrossJunction.h"
Grids::Grids() {
	
	}


/* First approach invloved doing same process for Vehicle_Grid as Road_Grid, iterating over each spot and deleting VehicleA and VehicleB but the heap didnt like this
and gave a erorr window which when asking google informed me that a something was being deleted twice, after troubleshooting the destructor I found that it was the vehicle which
was causing this window to pop up since when only doing it with Road it worked fine.

had to do research into how destructors work and looking at StackOverflow I realised this was caused due to us creating a vector storing pointers to ALL vehicle objects and that
each of these had to be deleted since they were all created using new. Tried iterating over vector rather than grid and it worked. 

The 'if' loop was added after adding junctions, as the same pointer is assigned to each of the Road_Grid slots, and when it iterated to second one ... BAD.
*/

Grids::~Grids() {
						
	for (Vehicle* i : vehicle_on_grid) {
		delete i;
	}
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			if (Road_Grid[i][j].RoadA != nullptr) {
				if (Road_Grid[i][j].RoadA->isRoad()) {
					delete Road_Grid[i][j].RoadA;
					delete Road_Grid[i][j].RoadB;
				}
			}

		}
	}

	for (Junction* i : junction_on_grid) {

		delete i;
	}
	

}

Roads_Grid_Slot Grids::getRoadsGrid(int x, int y) {
	return Road_Grid[x][y];

};
void Grids::setRoadsGrid(int x, int y, Roads* value) {
	if (value == nullptr) {
		Road_Grid[x][y].RoadA = value;
		Road_Grid[x][y].RoadB = value;
		return;
	}
	
	if (value->isRoad()) {
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
	}
	else {
		Road_Grid[x][y].RoadA = value;
		Road_Grid[x][y].RoadB = value;
	}
};
Vehicle_Grid_Slot Grids::getVehicleGrid(int x, int y) {
	return Vehicle_Grid[x][y];
};
void Grids::setVehicleGrid(int x, int y, Vehicle* value,bool AorB) {
	

	if (AorB) {
		Vehicle_Grid[x][y].VehicleA = value;
	}
	else {
		Vehicle_Grid[x][y].VehicleB = value;
	}
};
std::vector<Signal*>& Grids::getSignals() {
	return signal_on_grid;
}
std::vector<Vehicle*>& Grids::getVehicles() {
	return vehicle_on_grid;
}
std::vector<Junction*>& Grids::getJunctions() {
	return junction_on_grid;
}
std::vector<std::tuple<int, int, int, int, int>>& Grids::getRoads() {  
	return RoadsInputs;
};
//the above getters provide refrences as we dont want them to be changed only accsesed



void Grids::CreateRoad(int initial_x, int initial_y, int final_x, int final_y, int speed_limit) {
	if (initial_x != final_x && initial_y != final_y) {
		std::cout << "Diagonal road not supported" << std::endl;
		return;
	}
	if (initial_x == final_x && initial_y == final_y) {
		std::cout << "This isn't a road " << std::endl;
		return;
	}
	
	std::pair<int, int> junctionPoint{-1,-1};
	std::vector<std::pair<int, int>> junctionsVector;
	std::tuple<int, int, int, direction> roadsPoint;
	std::vector<std::tuple<int, int, int, direction>> roadsVector;
	std::tuple<int, int, int, int, int> RoadsParameters;

	if (initial_x == final_x) {
		if (initial_y > final_y) {
			int y = initial_y;
			initial_y = final_y;
			final_y = y;
		}
		if ((final_y - initial_y) < 2) {

			std::cout << "Road must be at least 3 slots long, Road creation terminated" << std::endl;
			return;
		}
		for (int i = initial_y; i <= final_y; i = i + 1) {
			if (getVehicleGrid(initial_x, i).VehicleA != nullptr || getVehicleGrid(initial_x, i).VehicleB != nullptr) {
				std::cout << "cannot create a junction where a vehicle is, road creation terminated" << std::endl;
				return;
			}
		} 
			// in a seperate loop as we dont want part of a road to be built before termination, safety check.
			// due to way that create vehicle works, if a vehicle is on a square we may assume a road is there
		
		
		for (int i = initial_y; i <= final_y; i = i + 1) {
			if (!(getRoadsGrid(i, final_y).RoadA != nullptr && getRoadsGrid(i, final_y).RoadA->isRoad() == 1 && getRoadsGrid(i, final_y).RoadA->getDirection() == North)) {




				if (i == initial_y || i == final_y || getRoadsGrid(initial_x, i).RoadA != nullptr) { // allows us to set the first and last part of the road as a turn
					junctionPoint.first = initial_x; // saves X coord of turn
					junctionPoint.second = i; //saves Y coord of turn
					junctionsVector.push_back(junctionPoint); // adds to a vector to be used later
				}
				else {
					roadsPoint = std::make_tuple(initial_x,i,speed_limit,North); // found on GFG tuples page
					roadsVector.push_back(roadsPoint);
					

				}

			}
		}
	}
	else {
		if (initial_x > final_x) {
			int x = initial_x;
			initial_x = final_x;
			final_x = x;
		}
		if ((final_x - initial_x) < 2) {

			std::cout << "Road must be at least 3 slots long, Road creation terminated" << std::endl;
			return;
		}
		for (int i = initial_x; i <= final_x; i = i + 1) {
			if (getVehicleGrid(i, initial_y).VehicleA != nullptr || getVehicleGrid(i, initial_y).VehicleB != nullptr) {
				std::cout << "cannot create a junction where a vehicle is, road creation terminated" << std::endl;
				return;

			} // in a seperate loop as we dont want part of a road to be built before termination, safety check.
			// due to way that create vehicle works, if a vehicle is on a square we may assume a road is there
		}
		

		
		for (int i = initial_x; i <= final_x; i = i + 1) {
			if (!(getRoadsGrid(i, final_y).RoadA != nullptr && getRoadsGrid(i, final_y).RoadA->isRoad() && getRoadsGrid(i, final_y).RoadA->getDirection() == East)) {

				if (i == initial_x || i == final_x || getRoadsGrid(i, initial_y).RoadA != nullptr) { // allows us to set the first and last part of the road as a turn
					junctionPoint.first = i; // saves X coord of turn
					junctionPoint.second = initial_y; //saves Y coord of turn
					junctionsVector.push_back(junctionPoint); // adds to a vector to be used later

				}
				else {

					roadsPoint = std::make_tuple(i,initial_y, speed_limit, East); // found on GFG tuples page
					roadsVector.push_back(roadsPoint);

				}
			}
		}

	}
	
	for (std::pair<int, int> i : junctionsVector) {
		if (i.first + 1 > 0 && i.first + 1 < Grids::grid_size) {
			if (getRoadsGrid(i.first + 1, i.second).RoadA != nullptr) {
				if (!getRoadsGrid(i.first + 1, i.second).RoadA->isRoad()) {
					std::cout << "Invalid Junction Placement at " << i.first << "," << i.second << " please leave a gap between junctions" << std::endl;
					std::cout << "If your attempting to extend a road please start at the roads endpoint" << std::endl;
					return;

				}
			}
		}
		if (i.first - 1 > 0 && i.first - 1 < Grids::grid_size) {
			if (getRoadsGrid(i.first - 1, i.second).RoadA != nullptr) {
				if (!getRoadsGrid(i.first - 1, i.second).RoadA->isRoad()) {
					std::cout << "Invalid Junction Placement at " << i.first << "," << i.second << " please leave a gap between junctions" << std::endl;
					std::cout << "If your attempting to extend a road please start at the roads endpoint" << std::endl;
					return;

				}
			}
		}
		if (i.second + 1 > 0 && i.second + 1 < Grids::grid_size) {
			if (getRoadsGrid(i.first, i.second + 1).RoadA != nullptr) {
				if (!getRoadsGrid(i.first, i.second + 1).RoadA->isRoad()) {
					std::cout << "Invalid Junction Placement at " << i.first << "," << i.second << " please leave a gap between junctions" << std::endl;
					std::cout << "If your attempting to extend a road please start at the roads endpoint" << std::endl;
					return;

				}
			}
		}
		if (i.second -1  > 0 && i.second - 1 < Grids::grid_size) {
			if (getRoadsGrid(i.first, i.second - 1).RoadA != nullptr) {
				if (!getRoadsGrid(i.first, i.second - 1).RoadA->isRoad()) {
					std::cout << "Invalid Junction Placement at " << i.first << "," << i.second << " please leave a gap between junctions" << std::endl;
					std::cout << "If your attempting to extend a road please start at the roads endpoint" << std::endl;
					return;

				}
			}
		}
	}
	// all checks to validate road have been made meaning its possible to add the inputs to vector to be used for load function
	RoadsParameters = std::make_tuple(initial_x, initial_y, final_x, final_y, speed_limit);
	this->RoadsInputs.push_back(RoadsParameters);
	for (std::tuple<int, int, int, direction> i : roadsVector) {
		
		Roads* R = new Roads(std::get<0>(i), std::get<1>(i), std::get<2>(i), std::get<3>(i));
		this->setRoadsGrid(std::get<0>(i), std::get<1>(i), R);


	}
	for (std::pair<int, int> i : junctionsVector) {
			
			Junction* J = new Junction(i.first, i.second, *this);
			J->setType(*this);
			junction Type = J->getJunctionType();
			delete J;
			this->CreateJunction(i.first, i.second, Type);
			
	}
}

void Grids::DeleteRoad(int initial_x, int initial_y, int final_x, int final_y) {
	std::vector<std::pair<int, int>> RoadPoints, JunctionPoints;
	std::pair<int, int> Point{ -1,-1 };
	

	if (initial_x == final_x) { //vertical road
		for (int i = initial_y; i <= final_y; i = i + 1) {
			if (this->getVehicleGrid(initial_x, i).VehicleA != nullptr || this->getVehicleGrid(initial_x, i).VehicleB != nullptr) {

				std::cout << "cannot delete road with Vehicle on it, please delete Vehicles first" << std::endl;
				return;
			}
			if (this->getRoadsGrid(initial_x, i).RoadA != nullptr) {
				Point.first = initial_x;
				Point.second = i;
				if (!this->getRoadsGrid(initial_x, i).RoadA->isRoad() || i==initial_y ||i==final_y) { // need to add start and end point to check if they are a part of any other roads
					JunctionPoints.push_back(Point);
				}
				else {
					RoadPoints.push_back(Point);
					
				}
			}
		}
	}
	else { //horizontal road
		for (int i = initial_x; i <= final_x; i = i + 1) {
			if (this->getVehicleGrid(i, initial_y).VehicleA != nullptr || this->getVehicleGrid(i, initial_y).VehicleB != nullptr) {

				std::cout << "cannot delete road with Vehicle on it, please delete Vehicles first" << std::endl;
				return;
			}
			if (this->getRoadsGrid(i, initial_y).RoadA != nullptr) {
				Point.first = i;
				Point.second = initial_y;
				if (this->getRoadsGrid(i, initial_y).RoadA->isRoad()) {
					RoadPoints.push_back(Point);
				}
				else {
					JunctionPoints.push_back(Point);
					
				}
			}
		}

	}

	for (std::pair<int, int> i : RoadPoints) {
		
		delete Road_Grid[i.first][i.second].RoadA;
		delete Road_Grid[i.first][i.second].RoadB;
		setRoadsGrid(i.first, i.second, nullptr);
	}
	for (std::pair<int, int> i : JunctionPoints) {
		std::cout << i.first << "," << i.second << std::endl;
		int size = junction_on_grid.size();
		for (int j = size - 1; j >= 0; j = j - 1) { // we begin at end of vector so if something is removed it doesnt mess with future indexing - Class Test 2
			if ( i.first == junction_on_grid[j]->getX() && i.second == junction_on_grid[j]->getY()) {
				junction_on_grid.erase(junction_on_grid.begin() + j);
				// removes all junctions from grid vector to prevent double deletion
			}
		}
		setRoadsGrid(i.first, i.second, nullptr);
		
		delete Road_Grid[i.first][i.second].RoadA; // since we make Junctions with new, need to manually delete
	}
	
	for (std::pair<int, int> i : JunctionPoints) {
	
		Junction* J = new Junction(i.first, i.second, *this);
		J->setType(*this);
		junction Type = J->getJunctionType();
		delete J;
		this->CreateJunction(i.first, i.second, Type);
	}

}

void Grids::CreateSignal(int x, int y, std::vector<bool> sequence) {
	
	Signal* s = new Signal(sequence, std::make_pair(x, y));		// instantiate the signal with the specified sequence

	this->Road_Grid[x][y].signals.push_back(s);		// push back the pointer
	
	this->signal_on_grid.push_back(s);		// push back pointer to the new signal on to the vector
}

void Grids::DeleteSignal(int x, int y) {

	for (int n = 0; n < this->Road_Grid[x][y].signals.size(); n++) {	// deallocate all memory dedicated to signal(s) on the grid space
		delete this->Road_Grid[x][y].signals.at(n);
	}

	this->Road_Grid[x][y].signals.clear();
}

void Grids::CreateVehicle(int x, int y,type type_of_vehicle,bool A_or_B) {
		
	if (this->getRoadsGrid(x, y).RoadA != nullptr && !(this->getRoadsGrid(x, y).RoadA->isRoad())) {
		std::cout << "cannot place car into junction" << std::endl;
		return;
	}
	if (A_or_B) {

		if (Road_Grid[x][y].RoadA == nullptr) {

			std::cout << "No road at coordinate " << x << "," << y << std::endl;
			return;
		}
		if (Vehicle_Grid[x][y].VehicleA != nullptr) {
			std::cout << "Vehicle already exists in this lane at coordinate " << x << "," << y << std::endl;
			return;

		}
		for (Vehicle* v : vehicle_on_grid) {
			if (v->getVehicleDirection() == North || v->getVehicleDirection() == East) {
				if (x == v->getInitialX() and y == v->getInitialY()) {				// This is ensuring that multiple vehicles arent created at the
					std::cout << "Starting position reserved" << std::endl;         //the same point as when the sim is reset, 2 vehicles would be placed 
					return;															//into the same spot which isnt good
				}
			}
			
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
		for (Vehicle* v : vehicle_on_grid) {
			if (v->getVehicleDirection() == South || v->getVehicleDirection() == West) {
				if (x == v->getInitialX() and y == v->getInitialY()) {				
					std::cout << "Starting position reserved" << std::endl;        
					return;
				}

			}
		}

	}

	Vehicle* v;
	
	switch (type_of_vehicle) {

		case car: {
		v = new Car(x, y);
		
		v->setVehicleDirection(*this, A_or_B);
		setVehicleGrid(x, y, v,A_or_B);
		vehicle_on_grid.push_back(v);
		break;
		}
		case bus: {
		v = new Bus(x, y);
		
		v->setVehicleDirection(*this, A_or_B);
		setVehicleGrid(x, y, v,A_or_B);
		vehicle_on_grid.push_back(v);
		break;
		}
		case bike: {
		v = new Bike(x, y);
		
		v->setVehicleDirection(*this, A_or_B);
		setVehicleGrid(x, y, v, A_or_B);
		vehicle_on_grid.push_back(v);
		break;

		}
		

	}
		
		
	

}
void Grids::DeleteVehicle(int x, int y, bool AorB) {
	direction D;
	int size = vehicle_on_grid.size();
	if (AorB) {
		if (this->getVehicleGrid(x, y).VehicleA == nullptr) {
			std::cout << "No Vehicle in Lane A at point " << x << " " << y << std::endl;
			return;
		}
		if (this->getRoadsGrid(x, y).RoadA->getDirection() == North) {
			D = North;
		}
		else {
			D = East;
		}

		for (int i = size - 1; i >= 0; i = i - 1) { // we begin at end of vector so if something is removed it doesnt mess with future indexing - Class Test 2
			if (x == vehicle_on_grid[i]->getX() && y == vehicle_on_grid[i]->getY() && vehicle_on_grid[i]->getVehicleDirection()==D) {
				vehicle_on_grid.erase(vehicle_on_grid.begin() + i);

			}
		}
		this->setVehicleGrid(x, y, nullptr, AorB);
		delete Vehicle_Grid[x][y].VehicleA;

	}
	else {
		if (this->getVehicleGrid(x, y).VehicleB == nullptr) {

			std::cout << "No Vehicle in Lane B at point " << x << " " << y << std::endl;
			return;
		}
		if (this->getRoadsGrid(x, y).RoadB->getDirection() == South) {
			D = South;
		}
		else {
			D = West;
		}

		for (int i = size - 1; i >= 0; i = i - 1) { // we begin at end of vector so if something is removed it doesnt mess with future indexing - Class Test 2
			if (x == vehicle_on_grid[i]->getX() && y == vehicle_on_grid[i]->getY() && vehicle_on_grid[i]->getVehicleDirection() == D) {
				vehicle_on_grid.erase(vehicle_on_grid.begin() + i);

			}
		}
		this->setVehicleGrid(x, y, nullptr, AorB);
		delete Vehicle_Grid[x][y].VehicleB;
	}
}
void Grids::CreateJunction(int x, int y, junction type_of_junction) {
	if (this->getRoadsGrid(x, y).RoadA != nullptr) {
		if (this->getRoadsGrid(x, y).RoadA->isRoad()) {
			delete Road_Grid[x][y].RoadA;
			delete Road_Grid[x][y].RoadB; // deletes road objects if there to be replaced with a junction, dont need to delete Juncitons as their held in vector and would lead to double deletion
			}
	

	}

	switch (type_of_junction) {
	case(unassigned): {

		break;
	}
	
	
	case(roads): { // only happens when extending a road replaces a turn with a road.
		int SL;
		if (this->getRoadsGrid(x - 1, y).RoadA != nullptr ) { // create A new horizontal road slot
		SL = this->getRoadsGrid(x - 1, y).RoadA->getSpeedLimit();	
		Roads* R = new Roads(x, y, SL, East);
		setRoadsGrid(x, y, R);
		}
		else { // means a new vertical road slot
			SL = this->getRoadsGrid(x, y - 1).RoadA->getSpeedLimit();
			Roads* R = new Roads(x, y, SL, North);
			setRoadsGrid(x, y, R);
		}
		//remove coordinate of jucntion from vector, as its now a Road
		int size = junction_on_grid.size();
		for (int i = size-1; i >= 0; i = i - 1) { // we begin at end of vector so if something is removed it doesnt mess with future indexing - Class Test 2
			if (x == junction_on_grid[i]->getX() && y == junction_on_grid[i]->getY()) {
				junction_on_grid.erase(junction_on_grid.begin() + i);
				
			}
		}
		break;
	}
	case(turn): {
		Junction* J = new Turn(x, y, *this);
		J->setType(*this);
		this->setRoadsGrid(x, y, J);
		int size = junction_on_grid.size();
		bool pushed = 0;
		if (size == 0) {
			junction_on_grid.push_back(J);
		}
		else {
			for (int i = 0; i < size; i = i + 1) {
				if (x == junction_on_grid[i]->getX() && y == junction_on_grid[i]->getY()) {
					junction_on_grid[i] = J;
					pushed = 1;
				}
			}
			if (!pushed) {
				junction_on_grid.push_back(J);
			}
		}
		break;
	}
	case(corner): {
		
		Junction* J = new CornerJunction(x, y, *this);
		J->setType(*this);
		this->setRoadsGrid(x, y, J);
		int size = junction_on_grid.size();
		bool pushed = 0;
		if (size == 0) {
			junction_on_grid.push_back(J);
		}
		else {
			for (int i = 0; i < size; i = i + 1) {
				if (x == junction_on_grid[i]->getX() && y == junction_on_grid[i]->getY()) {
					junction_on_grid[i] = J;
					pushed = 1;
				}
			}
			if (!pushed) {
				junction_on_grid.push_back(J);
			}
		}
		break;
	}
	case(t): {
		
		
		Junction* J = new TJunction(x, y, *this);
		J->setType(*this);

		this->setRoadsGrid(x, y, J);
		int size = junction_on_grid.size();
		bool pushed = 0;
		if (size == 0) {
			junction_on_grid.push_back(J);
		}
		else {
			for (int i = 0; i < size; i = i + 1) {
				if (x == junction_on_grid[i]->getX() && y == junction_on_grid[i]->getY()) {
					
					junction_on_grid[i] = J;
					pushed = 1;
				}
			}
			if (!pushed) {
	
				junction_on_grid.push_back(J);
			}
		}
		break;
	}
	case(cross): {

		Junction* J = new CrossJunction(x, y, *this);
		J->setType(*this);

		this->setRoadsGrid(x, y, J);
		int size = junction_on_grid.size();
		bool pushed = 0;
		if (size == 0) {
			junction_on_grid.push_back(J);
		}
		else {
			for (int i = 0; i < size; i = i + 1) {
				if (x == junction_on_grid[i]->getX() && y == junction_on_grid[i]->getY()) {

					junction_on_grid[i] = J;
					pushed = 1;
				}
			}
			if (!pushed) {

				junction_on_grid.push_back(J);
			}
		}
		break;
	}

	}
}
	
;