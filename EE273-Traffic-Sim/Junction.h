#pragma once
#include "Roads.h"
#include "Type_enum.h"


class Grids;
class Vehicle;
class Junction :public Roads{
public:
	Junction(int x,int y,Grids& grid);
	~Junction();
	junction getJunctionType();
	 void SetJunctionPointers(Grids& grid);
	virtual void UpdateJunction(Grids& grid); // made virtual as each junction has its own version
	void setType(Grids& grid);
protected:
	bool UpCheck= false;
	bool LeftCheck = false;
	bool DownCheck = false;
	bool RightCheck = false;
	
	junction Type;
	
	Vehicle* UpApproach =nullptr;
	Vehicle* UpLeave = nullptr;

	Vehicle* LeftApproach = nullptr;
	Vehicle* LeftLeave = nullptr;

	Vehicle* DownApproach = nullptr;
	Vehicle* DownLeave = nullptr;

	Vehicle* RightApproach = nullptr;
	Vehicle* RightLeave = nullptr;
};