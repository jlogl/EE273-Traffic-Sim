

#include <iostream>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Roads.h"

int main()
{


	
	
	Grids Grid;
	SimulationEngine* engine = new SimulationEngine(&Grid);
	Grid.CreateRoad(2, 1, 2, 19, 10, 1);

	
	
	
	Grid.CreateVehicle(2, 7, bus);
	Grid.CreateVehicle(2, 1, car);
	//Grid.CreateVehicle(6, 1, bike);
	Grid.PrintGrids();
	std::vector<Vehicle*>& v = Grid.getVehicles();
	

	engine->run(7);
	
	
   





}



