#pragma once
#include "Junction.h"
class TJunction:public Junction
{
public:
	TJunction(int x ,int y ,Grids& grid);
	~TJunction();
	void UpdateJunction(Grids& grid) override;
	
};

