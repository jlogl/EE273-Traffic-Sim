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

	/* @ brief - Outputs the Grid and Data sections of UI depending if the user has them enabled, this is used 
	* for the run step as we dont want the menu showing options to be present whilst the simulation runs
	* 
	*  @ param Grids& Grid - reference to the grid being printed 
	* 
	*  @ param SimulationEngine& Engine - reference to the engine, used to accses time of simulation
	* 
	*  @ param designs - this is how the grid is displayed, with them being defined by the set designs function
	* 
	*  @ param bool enable1,bool enable2 - used to toggle the grid and data sections of display respectivly, True
	*  meaning the section prints and False meaning it doesn't
	*/
    void SimPrint(Grids& Grid, SimulationEngine& Engine, std::vector<std::vector<std::string>> designs, bool enable1, bool enable2);

	/* @ brief - Prints the Grid in a way which is simple to understand, showing roads,vehicles and junctions. Works by 
	* iterating over whole grid and assigning a integer value to the grid point depending on the data held at the point. This integer corolates to 
	* the correct display depending on the data held at the point which will then be outputted.
	* 
	*  @ param  Grids& grid - This allows for the data in the grids to be accsesed and converted into a integer which corolates to a design  
	* 
	*  @ param  DesignValues - The Vector containing the Designs which are used.
	* 
	*  @ param ON - determines if Grid is displayed, True meaning yes and False meaning NO
	*/
	void PrintGrids(Grids& grid,std::vector<std::vector<std::string>> DesignValues,bool ON); 

	/* @ brief - Outputs the drop down list that shows the user the options available as well as takes their input to select which function they would 
	look to carry out. The options are chosen by the integer value which labels each function.
	*  
	*  @ return int - this is the chosen function which is then fed into a switch statement  
	*/
	int	 PrintUI(); 	

	/* @ brief - This defines all of the needed designs to present the simulation. The designs are each 5x5, so the vector of designs is 
	* a vector where each element is a vector of 5 strings, each string is 5 characters long, this allowed us to provide enough detail to make 
	* it claear what is going on
	* 
	*  @ param v - this is a vector defined outside of the scope of the function which each design gets added to 
	*/
	void SetDesigns(std::vector<std::vector<std::string>>& v);

	/* @ brief - Used inside of SetDesigns to make process alot easier, function takes five strings as well as the vector you want the 5x5 design
	* pushed into and pushes the strings into a single element of the vector of all of the designs in order that they should be displayed, 
	* meaning line1 prints then line2 etc. The lines given to the function are each pushed into a vector which is then pushed
	* into the vector which is given to the function.
	*/

	void Pushback(std::vector<std::vector<std::string>>& v, std::string line1, std::string line2, std::string line3, std::string line4, std::string line5);
	/* @ brief - This function allows for the type of a vehicle to be converted from enum to text, as a enum is 
	* just a number with a name which makes code easier to understand.
	* 
	*  @ param v - This is the vehicle pointer that the text for the type will be returned
	* 
	*  @ return std::string - this is the  type enum value in text form
	* 
	*/
	std::string ui_Type(Vehicle* v);

	/* @ brief - This function allows for the type of a junciton to be converted from enum to text, as a enum is
	* just a number with a name which makes code easier to understand.
	*
	*  @ param j - This is the junciton pointer that the text for the type will be returned
	*
	*  @ return std::string - this is the type enum value in text form
	*
	*/
	std::string ui_Junction(Junction* j);


	/* @ brief - This function allows for the direction of a vehicles travel to be converted from 
	* enum to text to be displayed.
	*
	*  @ param j - This is the vehicle pointer that the text for the direction of travel will be returned
	*
	*  @ return std::string - this is the direction enum value in text form
	*
	*/
	std::string ui_Direction(Vehicle* v);


	/* @ brief - This function allows for the direction of a roads traffic to be converted from
	* enum to text to be displayed.
	*
	*  @ param j - This is the road pointer that the text for the direction traffic will go on road
	*
	*  @ return std::string - this is the direction enum value in text form
	*
	*/
	std::string ui_Direction(Roads* R);

	/* @ brief - Checks whether a road at a point is vertical or horizontal. Makes it easier to do if statements when
	* asking which lane a vehicle will be placed into.
	* 
	*  @ param int x,int y - point on grid which is being checked
	* 
	*  @return bool- will be True if a road is vertical and False if road is horizontal
	* 
	*/
	bool ui_is_road_vertical_or_horizontal(int x, int y, Grids& grid); 

	/* @ brief - function asks two questions to user where the input must be in a range of values and stores answer to both questions in a pair. Felt 
	this funciton was better suited when asking for coordinates. 
	*
	*  @ param std::string question1, question2 - These are the questions which will be preseneted to user, answer to question1 is first in pair and 
	*  and to question2 is second in pair.
	*
	*  @ param int max - the maximum value accepted as a input 
	* 
	*  @ param int min - the minimun value accepted as a input
	* 
	* Idea adapted from the version which returns a single int from Lab 7 ex2
	*/
	std::pair<int, int> ui_ask_question(std::string question1, std::string question2, int max, int min);

	/* @ brief - prints a drop down list of all vehicles inside of simulation, allowing user to select with a integer which vehicle they would like to delete. 
	* Somewhat messy process so defined as function to make the main file as short as possible, similar theme for the following 3 funcitons.
	*/
	void ui_delete_Vehicle(Grids& grid);

	/* @ brief - Provides a list of every road that has been created inside of the simulation and asks user to choose a number to signify which one they would like to 
	*delete. Asking user to pick from list rather than choosing where they would like to delete road as this prevents users deleting half of a road which may cause plenty 
	*of issues and by defining the users choices prevents these issues.*/
	void ui_delete_Road(Grids& grid);

	void ui_delete_Signal(Grids& grid);
	/* @ brief - Prompts user to enter a filename which they would like the simulation to be saved under, prompting them if their is any issues with the creation of the 
	file. */
	void ui_save(SimulationEngine& Engine);

	/* @ brief - Prompts user to enter the filename of a save file for a simulation, if their is any issue with opening file the user is notified and the process stops */
	void ui_load(SimulationEngine& Engine);

	// Taken from Lab 7 Ex2
	
	/* @brief - gets input using the ui_get_int function and verifys if that value is within the range of max and min
	*  
	*  @ param int max - the maximum value accepted as a input 
	* 
	*  @ param int min - the minimun value accepted as a input
	*/
	int ui_get_int_in_range(int max, int min); 
	
	/* @ brief - used to prevent the program from terminating when a user inputs a value we expect to be a int but is actually letters as this leads to a value 
	of 0 which is the exit number. If a integer is expected and a string is inputed, this causes a cin error, if this happens the function clears the error
	and then filters through the input stream to check for a integer in the characters, it it finds any it puts the number back into the stream */
	void ui_skip_to_number();

	/* @ brief - waits for a user to enter a integer, if a integer is recieved, the function returns the input however if a integer isnt recieved, ui_skip_to_int is called
	to check if their is a number in the message at all. Line 5 is used to clear the input of all characters up until it reaches a new line character, this is needed as 
	if a number is read, the cin will take the number however everthing else on the line will remain in the stream, this line clears this to ensure bugs dont occur*/
	int ui_get_int();

	/* @ brief - waits until the user hits enter to allow for a pause if you want the user to see a message before the screen clears. Needs to clear input stream incase 
	user has typed a message prior to hitting enter unexpectedly*/
	void ui_pause(); 
	std::string ui_get_string(std::string question);


	int ui_ask_question(std::string question, int max, int min);