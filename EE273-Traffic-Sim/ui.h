#pragma once

// INCLUDE LIBS AND HEADERS HERE
#include <string>
#include <sstream>
#include <tuple>
#include "grids.h"
#include "Junction.h"


using namespace std;

/* DISPLAY OPTIONS FOR USER, GET SELECTION */
int top_lvl();				// returns int - the value that the user entered
//pair<int, int> ui_grid();	// setting the dimensions of the grids, returns a pair of integer value
int ui_roads();				// adding roads

int ui_signals();	// adding signals
int ui_vehicles();	// adding vehicles
void ui_junction(Junction& j);	// intersection created

/* specify properties of objects */
// int type_road();
// int type_signal();
type type_vehicle();

pair<int, int> start_road();
pair<int, int> end_road(pair<int, int> startPos);
pair<int, int> ui_get_pos();
int ui_get_speed_lmt();


/* INTERACTING WITH THE USER */
string ui_ask_db_filename();
void ui_print(string message);			// prints a message which stays until the user enters a character
//void ui_notify(string message);		// prints the message, nicely formatted, and stays until the user enters a character
void ui_print(Grids grid);			// override for when a grid is passed in
void ui_print_not_implemented(string message);
string ui_get_line_string(string question);
int get_int();
int ui_get_int_in_range(int low, int high);
char ui_get_char();
bool ui_get_bool();

/* MISCILLANEOUS FUNTIONS */
void ui_skip_to_number();