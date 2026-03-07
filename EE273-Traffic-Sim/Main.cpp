

#include <iostream>
#include "SimulationEngine.h"

int main()
{
	SimulationEngine engine;
	engine.run(5);
	engine.step();
	
	//engine.save();
	engine.reset();
	engine.load("save.txt");
	engine.run(3);
	
}

