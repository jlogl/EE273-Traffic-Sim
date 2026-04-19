#pragma once
#include <vector>
#include <string>
#include "Direction_enum.h"

class Grids;
class SimulationEngine;
class Vehicle;
class Junction;
class Roads;

// alot of the UI took inspiration from the Week 7 Ex 2 lab UI, using a terminal based UI where the user specifies the commands they want to carry 
// out using integer inputs, many of the functions used were taken and either used directly or altered to better fit our use, any function taken will be 
// labeled below.



	void PrintGrids(Grids& grid,std::vector<std::vector<std::string>> DesignValues,bool ON); // we want this seperate as when the program is running we dont want the drop down menu to be visible
	void PrintData(Grids& grid, SimulationEngine& engine,bool ON);
	int	 PrintUI(); // similar approach as lab to print out drop down list of functions but altered to our system							
	void SetDesigns(std::vector<std::vector<std::string>>& v);
	std::string ui_Type(Vehicle* v);
	std::string ui_Junction(Junction* j);
	std::string ui_Direction(Vehicle* v);
	std::string ui_Direction(Roads* R);
	int ui_ask_question(std::string question, int max, int min);// Taken from Lab 7 Ex2
	bool ui_is_road_vertical_or_horizontal(int x, int y, Grids& grid); 
	void SimPrint(Grids& Grid, SimulationEngine& Engine, std::vector<std::vector<std::string>> designs, bool enable1, bool enable2);
	std::pair<int, int> ui_ask_question(std::string question1, std::string question2, int max, int min);// returns two data points rather than one, makes more sense for coordinates
	std::string ui_get_string(std::string question);// Taken from Lab 7 Ex2
	void ui_delete_Vehicle(Grids& grid);
	void ui_delete_Road(Grids& grid);
	void ui_save(SimulationEngine& Engine);
	void ui_load(SimulationEngine& Engine);
	void ui_pause(); //taken from Lab 7 Ex2
	void Pushback(std::vector<std::vector<std::string>>& v,std::string line1, std::string line2, std::string line3, std::string line4, std::string line5); 

	//Pushback written to make setting all of the designs a quicker process, input the vector you want to feed 5 strings into and order you want them fed in
	
	int ui_get_int_in_range(int max, int min); // taken from lab 7 ex2
	void ui_skip_to_number();// taken from lab 7 ex2
	int ui_get_int();// taken from lab 7 ex2