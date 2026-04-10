

#include <iostream>
#include <vector>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Vehicle.h"
#include "Roads.h"
#include "Junction.h"


int main()
{
	
	
	
	Grids Grid;
	SimulationEngine* engine = new SimulationEngine(&Grid);
	// Square test
	/*Grid.CreateRoad(1, 1, 1, 5, 10);
	Grid.CreateRoad(1, 1, 5, 1, 10);
	Grid.CreateRoad(1, 5, 5, 5, 10);
	Grid.CreateRoad(5, 1, 5, 5, 10);
	
	Grid.CreateVehicle(3, 1, car, 1);
	Grid.CreateVehicle(3, 5, car, 0);*/

	//T-Junction test
	/*Grid.CreateRoad(3, 2, 7, 2, 10);
	Grid.CreateRoad(3, 6, 7, 6, 10);
	Grid.CreateRoad(3, 2, 3, 6, 10);
	Grid.CreateRoad(5, 2, 5, 6, 10);
	Grid.CreateRoad(7, 2, 7, 6, 10);
	
	Grid.CreateVehicle(4, 2, car, 0);
	Grid.CreateVehicle(5, 4, bus, 1);
	Grid.CreateVehicle(5, 4, bus, 0);*/
	
	// Cross test
	/*Grid.CreateRoad(5, 1, 5, 7, 10);
	//Grid.CreateRoad(2, 4, 8, 4, 10);
	//Grid.CreateVehicle(3, 4, car, 1);
	//Grid.CreateVehicle(7, 4, bus, 1);*/
	
	Grid.CreateRoad(2, 3, 2, 7, 5);
	Grid.CreateRoad(2, 7, 2, 9, 5);
	//Grid.CreateRoad(2, 5, 5, 5,5);
	
    
	
	Grid.PrintGrids(*engine);

	//

	//

	//
	std::vector<Junction*>& J = Grid.getJunctions();
	int size = J.size();
	std::cout << size << std::endl;
	for (Junction* i : J) {

		std::cout << i->getX() << " " << i->getY() << " " << i->getJunctionType() << std::endl;
	}
	
	//engine->load("save.txt");
	//Grid.PrintGrids(*engine);


	
	delete engine;
}




