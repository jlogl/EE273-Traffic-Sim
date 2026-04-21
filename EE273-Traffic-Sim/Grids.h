

#pragma once

#include <vector>
#include <tuple>
#include "Direction_enum.h"
#include "Type_enum.h"
#include "Signal.h"
class Vehicle;
class Roads;
class Junction;
class SimulationEngine;
struct Roads_Grid_Slot {
    Roads* RoadA = nullptr;         // lane going either up or right
    Roads* RoadB = nullptr;         // lane going either down or left; opposite to A
    std::vector<Signal*> signals;   // pointer to signal on this slot

};
struct Vehicle_Grid_Slot {
    Vehicle* VehicleA = nullptr;
    Vehicle* VehicleB = nullptr;

};

class Grids {
public:
    static const int grid_size = 10; /*this is used to change the size of the grid by editing a single number, static means that no matter how many grid object's there are,
     they will all share the same variable, is in public so that it may be used in other header files to change the range of loops for example. To use in other files we use
     Grids namespace. Found due to error when implementing constant idea and found info on GFG*/
    Grids();
    ~Grids();
    Roads_Grid_Slot getRoadsGrid(int x, int y);
    void setRoadsGrid(int x, int y, Roads* value);
    Vehicle_Grid_Slot getVehicleGrid(int x, int y);
    void setVehicleGrid(int x, int y, Vehicle* value,bool AorB); // a or b is to tell which lane we need to use, true means A and false means B
    void CreateRoad ( int initial_x, int initial_y, int final_x, int final_y, int speed_limit);
    void CreateSignal(int x, int y, std::vector<bool> sequence);
    void CreateVehicle(int x ,int y,type type_of_vehicle,bool A_or_B );
    void CreateJunction(int x, int y, junction type_of_junction);
    //void PrintGrids(SimulationEngine& engine);
    void DeleteRoad(int initial_x, int initial_y, int final_x, int final_y);
    void DeleteSignal(int x, int y);
    void DeleteVehicle(int x, int y, bool AorB);
    std::vector<Signal*>& getSignals();     // allows us to provide a refernce of the vector of signal pointers to simulation engine
    std::vector<Vehicle*>& getVehicles();   // same as getSignals but for vehicles
    std::vector<Junction*>& getJunctions(); // same again for the junctions
    std::vector<std::tuple<int, int, int, int, int>>& getRoads();
private:
    std::vector<std::tuple<int, int, int, int, int>> RoadsInputs;
    std::vector<Signal*> signal_on_grid;
    std::vector<Vehicle*> vehicle_on_grid;
    std::vector<Junction*> junction_on_grid;
    Roads_Grid_Slot Road_Grid[grid_size][grid_size];
    Vehicle_Grid_Slot Vehicle_Grid[grid_size][grid_size];
};