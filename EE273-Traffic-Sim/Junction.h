#pragma once
#include "Roads.h"
#include "Type_enum.h"

class Grids;
class Junction :public Roads{
public:
	Junction(int x,int y,Grids& grid);
	~Junction();
	junction getJunctionType();
	virtual void UpdateJunction(Grids& grid); // made virtual as each junction has its own version
	void setType(Grids& grid);
protected:
	bool UpCheck=false;
	bool DownCheck = false;
	bool RightCheck = false;
	bool LeftCheck = false;
	junction Type;
};