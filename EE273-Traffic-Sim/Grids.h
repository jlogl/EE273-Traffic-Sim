

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
struct Vehicle_Grid_Slot {           // similar appraoch for roads, allowing for multiple vehicles to be in same grid slot, a Road must be in the 
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
    /* @ brief - allows data at point on Roads grid to be accsesed
    *
    * @ param int x, int y - coordinate for data to be checked at
    * 
    * @ return Roads_grid_slot - struct made specifically for Roads Grid which contains two road pointers
    */
    Roads_Grid_Slot getRoadsGrid(int x, int y);

    /* @ brief - allows for the data at a grids point to be updated, used for many purposes such as creating and deleting roads.
    * The specification of a lane isnt needed as the roads create two objects, one for each lane by default
    *
    * @ param int x ,int y - coordinate where the data is being changed on Roads Grid
    * 
    * @ param Roads* - this is the data which will be held inside of the grid slot, may be a road object, junction object or nullptr
    * 
    */
    void setRoadsGrid(int x, int y, Roads* value);

    /* @ brief - allows data at point on Vehicle grid to be accsesed
    *
    * @ param int x, int y - coordinate for data to be checked at
    *
    * @ return Vehicle_grid_slot - struct made specifically for Vehicle Grid which contains two vehicle Pointers
    */
    Vehicle_Grid_Slot getVehicleGrid(int x, int y);

    /* @ brief - allows for the data at a grids point to be updated, used for many purposes such as creating and deleting Vehicles. A 
    * lane must be specified as a vehicle may only be in a single lane at once.
    *
    * @ param int x ,int y - coordinate where the data is being changed on Vehicle Grid
    *
    * @ param Roads* - this is the data which will be held inside of the grid slot, may be a road object, junction object or nullptr
    *
    */
    void setVehicleGrid(int x, int y, Vehicle* value,bool AorB); 
   
    /* @ brief - Allows for a road to be created on a grid, user defines two points on grid and functions populates all grid slots between points with
    *  either Road objects or Junction Objects depending on if the specified path crosses other Roads. function is also responsible for populating the 
    *  RoadsInput vector as well as ensuring that the input parameter are suitable depending on current layout. The following checks are followed in order:
    *  - Ensures road inputs aren't for a diagonal road
    *  - Ensures The initial point isnt the end point
    *  - Ensures road is at least 3 points long
    *  - Checks if road will overlap another road where a vehicle is or starting location is
    *  - Ensures A gap is left between all junctions
    * 
    *  If all criteria met, Road will be made
    * 
    * @ param int initial_x ,intitial_y - coordinate where Road creation begins
    * @ param int final_x ,final_y - coordinate where Road creation ends
    * 
    * @ param int speed_limit - defines how fast a vehicle may travel on road 
    *
    */
    void CreateRoad( int initial_x, int initial_y, int final_x, int final_y, int speed_limit); 

    /* @ brief - Creates a vehicle object of specified type at location and lane specified by user. Carries out the following checks to ensure car placement
    * is safe: 
    * - Ensures a road is at point
    * - Ensures a Vehicle isnt already at point 
    * - Ensures starting position isnt reserved for another vehicle
    * 
    *  If all criteria met, vehicle of specified type will be created
    * 
    *  @ param int x ,int y - coordinate that Vehicle will be placed
    * 
    *  @ param type - Enum defined to make code easier to read, defining the type of vehicle a object is 
    * 
    *  @ param AorB - Defines which lane Vehicle is placed in, either A for North/East or B for South/West
    */
    void CreateVehicle(int x ,int y,type type_of_vehicle,bool AorB ); 

    /* @ brief - Creates a Jucntion Object at defined location,deleting any existing road objects at location to replace them with a junction. Type of
    * Junction is specified however the orientation isnt needed
    *
    *  @ param - int x,int y - coordinate of Jucntion on grid inside Roads Grid
    * 
    *  @ param junction - Enum to specify the type of junction which may be created at point
    */
    void CreateJunction(int x, int y, junction type_of_junction); 
   
    /* @ brief - Deleted road objects between two defined points, road may not be deleted if vehicle is on it or was created on it.
    * The road will be removed from the Vector of road input parameters and the Juncitons will be removed from the junction vector. However incase a Junction 
    * is removed which would still be a junciton, just a different type, the function will check if any of the removed junctions are still needed and recreate 
    * any that are.
    * 
    *  @ param int initial_x, int initial_y - road starting point
    * 
    *  @ param  int final_x, int final_y - road end point
    */
    void DeleteRoad(int initial_x, int initial_y, int final_x, int final_y);

    /* @ brief - Deletes a Vehicle from the position and lane specified, will ensure a vehicle is their to be deleted.
    * 
    *  @ param int x, int y - Vehicle position in grid
    * 
    *  @ param bool AorB - specifies the lane where the vehicle is located , True for North/East and False for South/West
    */
    void DeleteVehicle(int x, int y, bool AorB);
   
    /* @ brief - Returns the vector of all vehicles on the grid, allowing for easy iteration, specifcally for simulationEngine functions
    *
    *  @ return - Reference to a Vector of vehicle pointers, we dont what is accsessing through function to change its contents
    */
    std::vector<Vehicle*>& getVehicles(); 

    /* @ brief - Returns the vector of all junctons on the grid, allowing for easy iteration, specifcally for simulationEngine functions
    *
    *  @ return - Reference to a Vector of Junction pointers, we dont what is accsessing through function to change its contents
    */
    std::vector<Junction*>& getJunctions(); 

    /* @ brief - Returns the vector of all successful CreateRoad input parameters, used to save simulation.
    *
    *  @ return - Reference to a Vector of tuples with 5 integers 5, we dont what is accsessing through function to change its contents
    */
    std::vector<std::tuple<int, int, int, int, int>>& getRoads();
private:
    std::vector<std::tuple<int, int, int, int, int>> RoadsInputs;
    std::vector<Vehicle*> vehicle_on_grid;
    std::vector<Junction*> junction_on_grid;
    Roads_Grid_Slot Road_Grid[grid_size][grid_size];
    Vehicle_Grid_Slot Vehicle_Grid[grid_size][grid_size];
  
};