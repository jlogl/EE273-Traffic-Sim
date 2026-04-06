

#include <iostream>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Roads.h"

int main()
{


	
	
	Grids Grid;
	SimulationEngine* engine = new SimulationEngine(&Grid);
	Grid.CreateRoad(2, 1, 2, 19, 10);
	Grid.CreateVehicle(2, 7, bus,1);
	//Grid.CreateRoad(4, 3, 8, 3, 10);
	Grid.CreateVehicle(2, 1, car,1);
	Grid.CreateVehicle(2, 15, bike,0);
	Grid.PrintGrids();
	std::vector<Vehicle*>& v = Grid.getVehicles();
	int count = 0;
	while ( count < 2) {
		engine->step();
		for (Vehicle* i : v) {
			std::cout << i->getX() <<" " << i->getY() <<  " " << i->getVehicleDirection() << std::endl;


		}
		

		count = count + 1;

	}

	
	engine->step();



	engine->save();
}




