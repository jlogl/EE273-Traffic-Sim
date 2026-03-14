

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
		Grid.PrintGrids();
		Roads* test = Grid.getRoadsGrid(2, 2);
		std::cout << test->getSpeedLimit() << std::endl;


}



