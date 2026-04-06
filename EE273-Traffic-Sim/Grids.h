

#pragma once
#include "Roads.h"
#include "Vehicle.h"
#include <vector>

struct Roads_Grid_Slot {
    Roads* RoadA = nullptr;
    Roads* RoadB = nullptr;

};
struct Vehicle_Grid_Slot {
    Vehicle* VehicleA = nullptr;
    Vehicle* VehicleB = nullptr;

};
class Vehicle;
class Roads;
class Grids {
public:
    static const int grid_size = 20; /*this is used to change the size of the grid by editing a single number, static means that no matter how many grid object's there are,
     they will all share the same variable, is in public so that it may be used in other header files to change the range of loops for example. To use in other files we use
     Grids namespace. Found due to error when implementing constant idea and found info on GFG*/
    Grids();
    ~Grids();
    Roads_Grid_Slot getRoadsGrid(int x, int y);
    void setRoadsGrid(int x, int y, Roads* value);
    Vehicle_Grid_Slot getVehicleGrid(int x, int y);
    void setVehicleGrid(int x, int y, Vehicle* value,bool A_or_B); // a or b is to tell which lane we need to use, true means A and false means B
    void CreateRoad( int initial_x, int initial_y, int final_x, int final_y, int speed_limit);
    void CreateVehicle(int x ,int y,type type_of_vehicle,bool A_or_B );
    void PrintGrids();
    std::vector<Vehicle*>& getVehicles(); // allows us to provide a refernce of the vector of vehicle pointers to simulation engine
private:
  
    std::vector<Vehicle*> vehicle_on_grid;
    Roads_Grid_Slot Road_Grid[grid_size][grid_size];
    Vehicle_Grid_Slot Vehicle_Grid[grid_size][grid_size];
    
};