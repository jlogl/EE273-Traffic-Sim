//
// Created by Jamie Graham on 10/03/2026.
//

#pragma once
#include "Roads.h"
#include "Vehicle.h"


class Grids {
public:
    Grids();
    ~Grids();
    
private:
    Roads* Road_Grid[10][10];
    Vehicle* Vehicle_Grid[10][10];

};