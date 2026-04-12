#pragma once

// INCLUDE LIBS AND HEADERS HERE
#include <string>
#include <sstream>
#include <tuple>
#include "grids.h"


using namespace std;

/* DISPLAY OPTIONS FOR USER, GET SELECTION */
int top_lvl();		// returns int - the value that the user entered
pair<int, int> ui_grid();	// setting the dimensions of the grids, returns a pair of integer value
int ui_roads();		// adding roads
//  might need a menu for each parameter? specify type of vehicle, then name, speed, so on.
//  or else I was thinking we ask for just one line which has all the answers separated by
//  commas and use stringstream to seperate it into independent variables
int ui_signals();	// adding signals
int ui_vehicles();	// adding vehicles
//void ui_intersections();		//nahhhhhhhhh

/* specify properties of objects */
int type_road();
int type_vehicle();
int type_intersection();


/* INTERACTING WITH THE USER */
string ui_ask_db_filename();
void ui_print(string message);
void ui_print(Grids grid);			// override for when a grid is passed in
void ui_print_not_implemented(string message);
string ui_get_line_string(string question);
int get_int();
int ui_get_int_in_range(int low, int high);

/* MISCILLANEOUS FUNTIONS */
void ui_skip_to_number();