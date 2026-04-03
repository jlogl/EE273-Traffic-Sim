

#pragma once
#include "Roads.h"
#include "Vehicle.h"
#include <vector>


class Vehicle;
class Roads;
class Grids {
public:
    Grids();
    ~Grids();
    Roads* getRoadsGrid(int x, int y);
    void setRoadsGrid(int x, int y, Roads* value);
    Vehicle* getVehicleGrid(int x, int y);
    void setVehicleGrid(int x, int y, Vehicle* value);
    void CreateRoad( int initial_x, int initial_y, int final_x, int final_y, int speed_limit, int number_of_lanes);
    void CreateVehicle(int x ,int y,type type_of_vehicle );
    void PrintGrids();
private:
    std::vector<Vehicle*> vehicle_on_grid;
    Roads* Road_Grid[10][10];
    Vehicle* Vehicle_Grid[10][10];

};