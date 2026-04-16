#pragma once
#include "Junction.h"
class CornerJunction :public Junction
{
public:
	CornerJunction(int x, int y, Grids& grid);
	~CornerJunction();
	void UpdateJunction(Grids& grid) override;


};