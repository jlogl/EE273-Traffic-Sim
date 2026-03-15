

#pragma once
#include "Roads.h"
#include "Vehicle.h"

class Roads;
class Vehcile;
class Grids {
public:
    Grids();
    ~Grids();
    Roads* getRoadsGrid(int x, int y);
    void setRoadsGrid(int x, int y, Roads* value);
    Vehicle* getVehicleGrid(int x, int y);
    void setVehicleGrid(int x, int y, Vehicle* value);
    void CreateRoad( int initial_x, int initial_y, int final_x, int final_y, int speed_limit, int number_of_lanes);
    void CreateVehicle();
    void PrintGrids();
private:
   
    Roads* Road_Grid[10][10];
    Vehicle* Vehicle_Grid[10][10];

};