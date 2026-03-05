

#include <iostream>
#include "SimulationEngine.h"

int main()
{
	SimulationEngine engine;
	engine.run(5);
	engine.step();
	engine.reset();
	engine.run(3);
}

