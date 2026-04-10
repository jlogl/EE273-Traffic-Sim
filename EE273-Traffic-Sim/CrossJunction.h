#pragma once
#include "Junction.h"
class CrossJunction:public Junction
{
public:
	CrossJunction(int x, int y, Grids& grid);
	~CrossJunction();
	void UpdateJunction(Grids& grid) override;

};

