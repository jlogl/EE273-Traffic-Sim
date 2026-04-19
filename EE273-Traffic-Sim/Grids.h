

#pragma once

#include <vector>
#include <tuple>
#include "Direction_enum.h"
#include "Type_enum.h"

//foward decleratons to prevent circular inclusions
class Vehicle;
class Roads;
class Junction;
class SimulationEngine;


struct Roads_Grid_Slot { // object containing two road objects, solution we determined would be suitable to deal with multiple lanes in same grid slot
    Roads* RoadA = nullptr;
    Roads* RoadB = nullptr;

};
struct Vehicle_Grid_Slot {           // similar appraoch for roads, allowing for multiple vehilces to be in same grid slot, a Road must be in the 
    Vehicle* VehicleA = nullptr;     //  corresponding grid slot on the road grids
    Vehicle* VehicleB = nullptr;

};

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
    void setVehicleGrid(int x, int y, Vehicle* value,bool AorB); // a or b is to tell which lane we need to use, true means A and false means B A always 
    // means either North or East depending on if road is vertical or horizontal adn laneB is south or west respectivly
   
    void CreateRoad( int initial_x, int initial_y, int final_x, int final_y, int speed_limit); /* allows user to create a road and creates junctions automatically by
    calling createJunction, automatically creates a two lane road by default with loans  */
    void CreateVehicle(int x ,int y,type type_of_vehicle,bool A_or_B ); // creates a vehicle in specified lane and location, road must be present in slot
    void CreateJunction(int x, int y, junction type_of_junction); // isnt called directly, however is called inside of createRoad when the user defines a road which overlaps
    //another road at a suitable location
   
    void DeleteRoad(int initial_x, int initial_y, int final_x, int final_y); // deletes roads and the junctions created by the road, no vehicles can be on a road if its to be 
    // deleted
    void DeleteVehicle(int x, int y, bool AorB);// specifies 
   
    std::vector<Vehicle*>& getVehicles(); // allows us to provide a refernce of the vector of vehicle pointers to simulation engine
    std::vector<Junction*>& getJunctions(); // same as vehicles but for the junctions
    std::vector<std::tuple<int, int, int, int, int>>& getRoads();
private:
    std::vector<std::tuple<int, int, int, int, int>> RoadsInputs;
    std::vector<Vehicle*> vehicle_on_grid;
    std::vector<Junction*> junction_on_grid;
    Roads_Grid_Slot Road_Grid[grid_size][grid_size];
    Vehicle_Grid_Slot Vehicle_Grid[grid_size][grid_size];
  
};