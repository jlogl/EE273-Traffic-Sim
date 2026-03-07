

#include <iostream>
#include "SimulationEngine.h"

int main()
{
	/*
	SimulationEngine engine;
	engine.run(5);
	engine.step();

	engine.save();
	engine.reset();
	engine.load("save.txt");
	engine.run(3);*/
	int arr[3][5]{ 0 };

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 5; col++) {
			std::cout << arr[row][col] ;
		}
		std::cout << std::endl;

	}
}
