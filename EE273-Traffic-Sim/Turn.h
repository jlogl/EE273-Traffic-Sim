#pragma once
#include "Junction.h"
class Turn :public Junction
{public:
	Turn(int x,int y,Grids& grid);
	~Turn();
	void UpdateJunction(Grids& grid) override;
};






