

#include <iostream>
#include "SimulationEngine.h"
#include "Grids.h"
#include "Roads.h"

int main()
{

	SimulationEngine engine;
	
	/*engine.run(5);
	engine.step();

	engine.reset();
	engine.load("save.txt");
	engine.run(3);*/
	Grids Grid;
	Grid.CreateRoad(2,2,2,4,10,1);
	Grid.CreateRoad(6, 4, 7, 4, 20, 1);
	Grid.CreateVehicle(2,3,car);
		Roads* test = Grid.getRoadsGrid(2, 2);
		std::cout << test->getSpeedLimit() << std::endl;
	Grid.CreateVehicle(1,2,car);
Grid.PrintGrids();

	Vehicle * test_v=Grid.getVehicleGrid(2,3);
	std::cout<<test_v->getVehicleType();


}



