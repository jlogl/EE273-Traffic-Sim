#include "UI.h"
#include "Grids.h"
#include "SimulationEngine.h"
#include "Roads.h"
#include "Vehicle.h"
#include "Junction.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
#include <cstdio>
#include <limits>






void Pushback(std::vector<std::vector<std::string>>& v, std::string line1, std::string line2, std::string line3, std::string line4, std::string line5) {
	std::vector<std::string> design;
	design.push_back(line1);
	design.push_back(line2);
	design.push_back(line3);
	design.push_back(line4);
	design.push_back(line5);
	v.push_back(design);

}
void SetDesigns(std::vector<std::vector<std::string>>& v) {
	
	

	// blank lines
	std::string B1 = "     ";
	std::string B2 = "  X  ";
	

	// blank design #0
	Pushback(v, B1, B1, B2, B1, B1);


	// horizontal road lines
	std::string H1 = "-----";
	std::string H2 = " ==> ";
	std::string H3 = " <== ";
	std::string H4 = " Car ";
	std::string H5 = " Bus ";
	std::string H6 = "Bike ";

	//empty road H #1
	Pushback(v, H1, H2, H1, H3, H1);

	// car A road H #2 
	Pushback(v, H1, H4, H1, H3, H1);

	// car B road H #3
	Pushback(v, H1, H2, H1, H4, H1);

	// bus A road H #4
	Pushback(v, H1, H5, H1, H3, H1);

	// bus B road H #5
	Pushback(v, H1, H2, H1, H5, H1);

	// bike A road H #6
	Pushback(v, H1, H6, H1, H3, H1);

	// bike B road H #7
	Pushback(v, H1, H2, H1, H6, H1);

	// car A car B road h #8
	Pushback(v, H1, H4, H1, H4, H1);
	 
	// car A bus B road h #9
	Pushback(v, H1, H4, H1, H5, H1);

	// car A bike B road h #10
	Pushback(v, H1, H4, H1, H6, H1);
	
	// bus A car B road h #11
	Pushback(v, H1, H5, H1, H4, H1);
	
	// bus A bus B road h #12
	Pushback(v, H1, H5, H1, H6, H1);
	
	// Bus A bike B road h #13
	Pushback(v, H1, H5, H1, H6, H1);

	// bike A Car B road h #14
	Pushback(v, H1, H6, H1, H4, H1);

	// Bike A bus B road h #15 
	Pushback(v, H1, H6, H1, H5, H1);
	
	// Bike A bike B roah h #16 
	Pushback(v, H1, H6, H1, H6, H1);
	
	
	// vertical road lines 
	std::string V1 = "| | |";
	std::string V2 = "|^|||";
	std::string V3 = "|||||";
	std::string V4 = "|||v|";

	std::string V5 = "|C|||";
	std::string V6 = "|a|||";
	std::string V7 = "|r|v|";

	std::string V8 = "|B|||";
	std::string V9 = "|u|||";
	std::string V10 ="|s|V|";

	std::string V11 = "|B|||";
	std::string V12 = "|i|||";
	std::string V13 = "|k|v|";
	std::string V14 = "|e| |";
	std::string V15 = "| |e|";

	std::string V16 = "|C|C|";
	std::string V17 = "|a|a|";
	std::string V18 = "|r|r|";

	std::string V19 = "|C|B|";
	std::string V20 = "|a|u|";
	std::string V21 = "|r|s|";

	std::string V22 = "|C|B|";
	std::string V23 = "|a|i|";
	std::string V24 = "|r|k|";

	std::string V25 = "|B|C|";
	std::string V26 = "|u|a|";
	std::string V27 = "|s|r|";

	std::string V28 = "|B|B|";
	std::string V29 = "|u|u|";
	std::string V30 = "|s|s|";

	std::string V31 = "|B|B|";
	std::string V32 = "|u|i|";
	std::string V33 = "|s|k|";

	std::string V34 = "|B|C|";
	std::string V35 = "|i|a|";
	std::string V36 = "|k|r|";

	std::string V37 = "|B|B|";
	std::string V38 = "|i|u|";
	std::string V39 = "|k|s|";

	std::string V40 = "|B|B|";
	std::string V41 = "|i|i|";
	std::string V42 = "|k|k|";
	std::string V43 = "|e|e|";

	std::string V44 = "|^|C|";
	std::string V45 = "|||a|";
	std::string V46 = "|||r|";

	std::string V47 = "|^|B|";
	std::string V48 = "|||u|";
	std::string V49 = "|||s|";

	std::string V50 = "|^|B|";
	std::string V51 = "|||i|";
	std::string V52 = "|||k|";
	// Blank Road V #17
	Pushback(v, V1, V2, V3, V4, V1);

	// car A road v #18
	Pushback(v, V1, V5, V6, V7, V1);

	// car B road v #19
	Pushback(v, V1, V44, V45, V46, V1);

	//Bus A road v #20
	Pushback(v, V1, V8, V9, V10, V1);
	
	//Bus B road v #21 
	Pushback(v, V1, V47, V48, V49, V1);
	
	//Bike A road v #22 
	Pushback(v, V1, V11, V12, V13, V14);
	
	//Bike B road v #23
	Pushback(v, V1, V50, V51, V52, V15);
	
	// car A car B road v #24
	Pushback(v, V1, V16, V17, V18, V1);
	
	// car a bus B road v #25
	Pushback(v, V1, V19, V20, V21, V1);
	
	// car A bike B road v #26
	Pushback(v, V1, V22, V23, V24, V15);
	
	// bus A car A road v #27
	Pushback(v, V1, V25, V26, V27, V1);
	
	// bus A bus B road v #28
	Pushback(v, V1, V28, V29, V30, V1);
	
	// bus A bike B road v #29
	Pushback(v, V1, V31, V32, V33, V15);
	
	//bike A Car B road v #30
	Pushback(v, V1, V34, V35, V36, V14);
	
	//bike A bus road v #31
	Pushback(v, V1, V37, V38, V39, V14);
	
	//Bike A bike B road v #32
	Pushback(v, V1, V40, V41, V42, V43);

	// Turns
	//Up
	std::string Turn1 = " ___ ";
	std::string Turn2 = "/   \\";
	std::string Turn3 = "|^|||";
	std::string Turn4 = "|||||";
	std::string Turn5 = "|||v|";

	//down

	std::string Turn6 = "\\   /";
	std::string Turn7 = " --- ";
	
	//left
	std::string Turn8 =  "/----";
	std::string Turn9 =  "| -->";
	std::string Turn10 = "|  --";
	std::string Turn11=  "| <--";
	std::string Turn12= "\\----";

	//right 
	std::string Turn13 = "----\\";
	std::string Turn14 = "--> |";
	std::string Turn15 = "--  |";
	std::string Turn16 = "<-- |";
	std::string Turn17 = "----/";


	// Turn when upcheck #33
	
	Pushback(v, Turn3, Turn4, Turn5, Turn6, Turn7);
	
	// Turn when downcheck #34
	Pushback(v, Turn1, Turn2, Turn3, Turn4, Turn5);

	// Turn when leftcheck #35
	Pushback(v, Turn13, Turn14, Turn15, Turn16, Turn17);

	// Turn when rightcheck #36
	Pushback(v, Turn8, Turn9, Turn10, Turn11, Turn12);

	// Corners

	// Up and left 
	std::string CR1 = "/ | |";
	std::string CR2 = " /| |";
	std::string CR3 = "==/ |";
	std::string CR4 = "   / ";
	std::string CR5 = "---  ";

	// up and right
	std::string CR6  = "| | \\";
	std::string CR7  = "| |\\ ";
	std::string CR8  = "| \\==";
	std::string CR9  = " \\   ";
	std::string CR10 = "  ---";

	//down and left
	std::string CR11 ="___  ";
	std::string CR12= "   \\ ";
	std::string CR13= "==\\ |";
	std::string CR14= " \\| |";
	std::string CR15 = "\\ | |";

	//down and right
	std::string CR16 = "  ___";
	std::string CR17 = " /   ";
	std::string CR18 = "| /==";
	std::string CR19 = "| |/ ";
	std::string CR20 = "| | /";

	// Upcheck and leftcheck #37
	Pushback(v, CR1, CR2, CR3, CR4, CR5);

	//upcheck and rightcheck #38
	Pushback(v, CR6, CR7, CR8, CR9, CR10);

	//downcheck and leftcheck #39

	Pushback(v, CR5, CR4, CR3, CR2, CR1);

	//downcheck and rightcheck #40

	Pushback(v, CR10, CR9, CR8, CR7, CR6);


	//T-junction

	//up,left,down
	std::string T1 = "/ | |";
	std::string T2 = " /|||";
	std::string T3 = "--|||";
	std::string T4 =" \\|v|";
	std::string T5 ="\\ | |";

	//left,up,right
	std::string T6 = "/ | \\";
	std::string T7 = " /|\\ ";
	std::string T8 = "-----";
	std::string T9 = " <-- ";
	std::string T10= "-----";

	//down,right,up

	std::string T11 = "| | \\";
	std::string T12 = "|^|\\ " ;
	std::string T13 = "|||--";
	std::string T14 = "|||/ ";
	std::string T15 = "||| /";

	//right,down,left

	std::string T16 = "-----";
	std::string T17 = " --> ";
	std::string T18 = "-----";
	std::string T19 = "\\ |/ ";
	std::string T20 = " \\| /";

	//up,left,down #41
	Pushback(v, T1, T2, T3, T4, T5);

	// //left,up,right #42
	Pushback(v, T6, T7, T8, T9, T10);

	//down,right,up #43
	Pushback(v, T11, T12, T13, T14, T15);

	//right,down,left #44
	Pushback(v, T16, T17, T18, T19, T20);

	//cross #45
	std::string Cross1 = "/ | \\";
	std::string Cross2 = " /|\\ ";
	std::string Cross3 = "--+--";
	std::string Cross4 = " \\|/ ";
	std::string Cross5 = "\\ | /";

	Pushback(v, Cross1, Cross2, Cross3, Cross4, Cross5);
}

void PrintGrids(Grids& grid, std::vector<std::vector<std::string>> DesignValues, bool ON) {
	// Need to define what each segment of the grid is, this is done by iterating through the grid 
	// and identifying what it is that is their then assigning a integer value to it, this value will 
	// correspond with the Designs place inside of the Designs vector from 1 to 46.

	// since the Grids are made using arrays and their indexing goes [x][-y] so as the Y number gets bigger,
	// it goes down rather than up we needed to invert the way that loops index through the grid to get the intended
	// display where the bottom left corner is 0,0.
	std::vector<int> gridValues;
	if (ON) {
		for (int i = 0; i < Grids::grid_size; i = i + 1) { // each row in grid.
			for (int j = 0; j < Grids::grid_size; j = j + 1) {//each column in grid
			
				if (grid.getRoadsGrid(j, i).RoadA == nullptr) {
					gridValues.push_back(0); // if no road is on grid, then the slot is empty as all other objects need road
					

				}
				else {
					if (grid.getRoadsGrid(j, i).RoadA->isRoad()) {// Tells us that this slot is a road 
						if (grid.getRoadsGrid(j, i).RoadA->getDirection() == North) { //vertical road
							if (grid.getVehicleGrid(j, i).VehicleA == nullptr && grid.getVehicleGrid(j, i).VehicleB == nullptr) {
								gridValues.push_back(17); // is a vertical road with nothing on it
								
							}
							if (grid.getVehicleGrid(j, i).VehicleA != nullptr && grid.getVehicleGrid(j, i).VehicleB == nullptr) { //Vehicle in North Lane
								type vType = grid.getVehicleGrid(j, i).VehicleA->getVehicleType();
								switch (vType) {
								case(car): {
									gridValues.push_back(18);
									
									break;
								}
								case(bus): {
									gridValues.push_back(20);
									
									break;
								}
								case(bike): {
									gridValues.push_back(22);
									
									break;
								}
								}
							}
							if (grid.getVehicleGrid(j, i).VehicleA == nullptr && grid.getVehicleGrid(j, i).VehicleB != nullptr) {//Vehicle in South Lane
								type vType = grid.getVehicleGrid(j, i).VehicleB->getVehicleType();
								switch (vType) {
								case(car): {
									gridValues.push_back(19);
									
									break;
								}
								case(bus): {
									gridValues.push_back(21);
									
									break;
								}
								case(bike): {
									gridValues.push_back(23);
									
									break;
								}
								}

							}

							if (grid.getVehicleGrid(j, i).VehicleA != nullptr && grid.getVehicleGrid(j, i).VehicleB != nullptr) {
								type vTypeA = grid.getVehicleGrid(j, i).VehicleA->getVehicleType();
								type vTypeB = grid.getVehicleGrid(j, i).VehicleB->getVehicleType();
								switch (vTypeA) {
								case(car): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(24);
										
										break;
									}
									case(bus): {
										gridValues.push_back(25);
										
										break;
									}
									case(bike): {
										gridValues.push_back(26);
										
										break;
									}
									}
									break;
								}
								case(bus): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(27);
										
										break;
									}
									case(bus): {
										gridValues.push_back(28);
										
										break;
									}
									case(bike): {
										gridValues.push_back(29);
										
										break;
									}
									}
									break;
								}
								case(bike): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(30);
										
										break;
									}
									case(bus): {
										gridValues.push_back(31);
										
										break;
									}
									case(bike): {
										gridValues.push_back(32);
										
										break;
									}
									}
									break;
								}
								}
							}
						}
						else {//horizontal road
							if (grid.getVehicleGrid(j, i).VehicleA == nullptr && grid.getVehicleGrid(j, i).VehicleB == nullptr) {
								gridValues.push_back(1); // is a vertical road with nothing on it

							}
							if (grid.getVehicleGrid(j, i).VehicleA != nullptr && grid.getVehicleGrid(j, i).VehicleB == nullptr) { //Vehicle in East Lane
								type vType = grid.getVehicleGrid(j, i).VehicleA->getVehicleType();
								switch (vType) {
								case(car): {
									gridValues.push_back(2);
									
									break;
								}
								case(bus): {
									gridValues.push_back(4);
									
									break;
								}
								case(bike): {
									gridValues.push_back(6);
									
									break;
								}
								}
							}
							if (grid.getVehicleGrid(j, i).VehicleA == nullptr && grid.getVehicleGrid(j, i).VehicleB != nullptr) {//Vehicle in west Lane
								type vType = grid.getVehicleGrid(j, i).VehicleB->getVehicleType();
								switch (vType) {
								case(car): {
									gridValues.push_back(3);
									
									break;
								}
								case(bus): {
									gridValues.push_back(5);
									
									break;
								}
								case(bike): {
									gridValues.push_back(7);
									
									break;
								}
								}

							}

							if (grid.getVehicleGrid(j, i).VehicleA != nullptr && grid.getVehicleGrid(j, i).VehicleB != nullptr) {
								type vTypeA = grid.getVehicleGrid(j, i).VehicleA->getVehicleType();
								type vTypeB = grid.getVehicleGrid(j, i).VehicleB->getVehicleType();
								switch (vTypeA) {
								case(car): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(8);
										
										break;
									}
									case(bus): {
										gridValues.push_back(9);
										
										break;
									}
									case(bike): {
										gridValues.push_back(10);
										
										break;
									}
									}
									break;
								}
								case(bus): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(11);
										
										break;
									}
									case(bus): {
										gridValues.push_back(12);
										
										break;
									}
									case(bike): {
										gridValues.push_back(13);
										
										break;
									}
									}
									break;
								}
								case(bike): {
									switch (vTypeB) {
									case(car): {
										gridValues.push_back(14);
										
										break;
									}
									case(bus): {
										gridValues.push_back(15);
										
										break;
									}
									case(bike): {
										gridValues.push_back(16);
										
										break;
									}
									}
								}
										  break;
								}

							}

						}

					}
					else {// is a Junction
						Junction J(j, i, grid);
						J.setType(grid);
						junction typeJ = J.getJunctionType();
						std::vector<bool> CheckValues = J.Checks();

						switch (typeJ) {

						case(unassigned): {
							gridValues.push_back(0);
							

						}
						case(turn): {
							if (CheckValues[0] && !CheckValues[1] && !CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(33);
								
								break;

							}
							if (!CheckValues[0] && !CheckValues[1] && CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(34);
								
								break;
							}
							if (!CheckValues[0] && CheckValues[1] && !CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(35);
								
								break;
							}
							if (!CheckValues[0] && !CheckValues[1] && !CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(36);
								
								break;
							}
						}
						case(corner): {
							if (CheckValues[0] && CheckValues[1] && !CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(37);
								
								break;
							}
							if (CheckValues[0] && !CheckValues[1] && !CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(38);
								
								break;
							}
							if (!CheckValues[0] && CheckValues[1] && CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(39);
								
								break;
							}
							if (!CheckValues[0] && !CheckValues[1] && CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(40);
								
								break;
							}

						}
						case(t): {
							if (CheckValues[0] && CheckValues[1] && CheckValues[2] && !CheckValues[3] ) {

								gridValues.push_back(41);
								
								break;

							}
							if (CheckValues[0] && CheckValues[1] && !CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(42);
								
								break;
							}
							if (CheckValues[0] && !CheckValues[1] && CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(43);
								
								break;
							}
							if (!CheckValues[0] && CheckValues[1] && CheckValues[2] && CheckValues[3] ) {

								gridValues.push_back(44);
								
								break;
							}
						}

						case(cross): {
							if (CheckValues[0] && CheckValues[1] && CheckValues[2] && CheckValues[3] ) {
								gridValues.push_back(45);
								
								break;

							}
						}
						}



					}



				}



			}


		}



		// At this stage we have the value for every grid point, as well as what design we need to display. The idea is now to iterate over the vector griValues and print out
		//all of the designs, however many loops are needed in order to display the data properly as each slot is five lines

		std::vector<std::string> Design;
		int designSelector;
		for (int i = Grids::grid_size - 1; i >= 0; i = i - 1) { //row number

			for (int j = 0; j < 5; j = j + 1) {

				switch (j) {

				case(0): {
					std::cout << "--|";
					break;
				}
				case(1): {
					std::cout << "  |";
					break;
				}
				case(2): {
					if (i < 10) {
						std::cout << "0" << i << "|";
						break;
					}
					else {
						std::cout << i << "|";
						break;
					}
				}
				case(3): {
					std::cout << "  |";
					break;
				}
				case(4): {
					std::cout << "--|";
					break;
				}
				}


				for (int k = 0; k < Grids::grid_size; k = k + 1) { //column number

					designSelector = gridValues[i * Grids::grid_size + k];
					Design = DesignValues[designSelector];
					std::cout << Design[j];
				}
				std::cout << std::endl;
			}

		}
		for (int i = 0; i < Grids::grid_size; i = i + 1) {

			if (i == 0) {
				std::cout << "  |";

			}
			std::cout << "-----";

		}
		std::cout << std::endl << "   ";

		for (int i = 0; i < Grids::grid_size; i = i + 1) {
			for (int j = 0; j < 5; j = j + 1) {
				switch (j) {
				case(0): {
					std::cout << "|";
					break;
				}
				case(1): {
					std::cout << " ";
					break;
				}
				case(2): {
					std::cout << i;
					break;
				}
				case(3): {
					if (i < 10) {
						std::cout << " ";
						break;
					}
					break;
				}
				case(4): {
					std::cout << "|";
					break;
				}
				}


			}



		}
		std::cout << std::endl << std::endl;
	}
}


	std::string ui_Type(Vehicle* v) {
		type t = v->getVehicleType();
		switch (t) {
		case(car): {
			return "Car";
			break;
		}
		case(bus): {
			return "Bus";
			break;
		}
		case (bike): {
			return "Bike";
			break;
		}
		}
	}
	std::string ui_Junction(Junction* j) {
		junction type = j->getJunctionType();
		switch (type) {

		case(turn): {
			return "Turn";
			break;
		}
		case(corner): {
			return "Corner";
			break;
		}
		case(t): {
			return "T-Junction";
			break;
		}
		case(cross): {
			return "Cross Junction";
			break;
		}
		}

	}
	std::string ui_Direction(Vehicle* v) {
		direction D = v->getVehicleDirection();
		switch (D) {
		case(North): {
			return "North";
			break;
		}
		case(South): {
			return "South";
			break;
		}
		case(East): {
			return "East";
			break;
		}
		case(West): {
			return "West";
			break;
		}
		}

	}
	std::string ui_Direction(Roads* R) {
		direction D = R->getDirection();
		switch (D) {
		case(North): {
			return "North";
			break;
		}
		case(South): {
			return "South";
			break;
		}
		case(East): {
			return "East";
			break;
		}
		case(West): {
			return "West";
			break;
		}
		}

	}




	void PrintData(Grids& grid,SimulationEngine& engine,bool ON) {
		std::vector<Junction*> JunctionPoints=grid.getJunctions();
		std::vector<Vehicle*> VehiclesVector = grid.getVehicles();
		std::vector<std::tuple<int, int, int, int, int>> RoadsPoints = grid.getRoads();
		if (ON) {
			std::cout << "Current Simulation Time: " << engine.getCurrentTime() << std::endl << std::endl
				<< "Vehicles: " << std::endl
				<< "A car has the following set values: Max speed = 6, Aceleration = 2 and deceleration = 3" << std::endl
				<< "A Bus has the following set values: Max speed = 3, Aceleration = 1 and deceleration = 1" << std::endl
				<< "A Bike has the following set values: Max speed = 2, Aceleration = 1 and deceleration = 2" << std::endl << std::endl;

			if (VehiclesVector.size() == 0) {

				std::cout << "No Vehicles currently in Simulation Enviroment, Add one to see its data below!" << std::endl << std::endl;
			}
			else {
				int count = 1;
				for (Vehicle* v : VehiclesVector) {
				
					std::cout << "Vehicle " << count << " data:" << std::endl
						<< "Vehicles Type: " << ui_Type(v) << " Current Position: " << v->getX() << "," << v->getY() << std::endl
						<< "Initial Position: " << v->getInitialX() << "," << v->getInitialY() << std::endl
						<< "Current Speed: " << v->getCurrentSpeed() << std::endl
						<< "Stopping Distance " << v->getStoppingDistance() << std::endl
						<< "Current Direction: " << ui_Direction(v) << std::endl
						<< "Average Speed: " << v->getAverageSpeed(engine) << std::endl
						<< "Total Distance Travelled: " << v->getDistance() << std::endl << std::endl;

					count = count + 1;

				}

			}
			std::cout << "Roads: " << std::endl;
			if (RoadsPoints.size() == 0) {

				std::cout << "No Roads in the Simulation Enviroment, Add one to see its data below!" << std::endl;
			}
			else {
				int count = 1;
				for (std::tuple<int, int, int, int, int> R : RoadsPoints) {
					std::string D1;
					std::string D2;
					if (std::get<0>(R) - std::get<2>(R) == 0) {
						D1 = " North ";
						D2 = " South ";
					}
					else {
						D1 = " East ";
						D2 = " West ";

					}


					std::cout << "Road " << count << " data:" << std::endl
						<< "Road starting point: " << std::get<0>(R) << "," << std::get<1>(R) << std::endl
						<< "Road ending point: " << std::get<2>(R) << "," << std::get<3>(R) << std::endl
						<< "Road Speed limit: " << std::get<4>(R) << std::endl
						<< "Lane one Direction:" << D1 << std::endl << "Lane two Direction:" << D2 << std::endl << std::endl;
					count = count + 1;
				}
			}
			std::cout << "Junctions: " << std::endl;
			int count = 1;
			for (Junction* J : JunctionPoints) {

				std::cout << "Junction " << count << " data:" << std::endl
					<< "Junction Point: " << J->getX() << "," << J->getY() << std::endl
					<< "Type of Junction: " << ui_Junction(J) << std::endl
					<< "Total Uses: " << J->getUses() << std::endl << std::endl;
				count = count + 1;
			}
			std::cout << std::endl;
		}
	}

	int ui_get_int() {
		int number;
		while (true) {
			if (std::cin >> number) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return number;
			}
			std::cout << "Invalid input, Please try again.\n";
			ui_skip_to_number();
		}
	}
	void ui_skip_to_number() {
		if (std::cin.fail()) {
			std::cin.clear();
			for (char ch; std::cin >> ch;) {
				if (('0' <= ch && ch <= '9') || ch == '-') {
					std::cin.unget();
					return;
				}
			}
			std::cout << "The stream is at eof or bad"
				<< "\n";
		}
	}

	int ui_get_int_in_range(int max, int min) {
		while (true) {
			int number = ui_get_int();
			if (min <= number && number <= max) {
				return number;
			}
			std::cout << "Sorry the number is not between " << min << " and "
				<< max << "; Try again...\n";
		}
		
	}
	int PrintUI() {
		std::cout << "Traffic system simulation opertaions:" << std::endl
			<< "1. Create Road..." << std::endl
			<< "2. Create Vehicle..." << std::endl
			<< "3. Create Traffic Signal..." << std::endl
			<< "4. Run Simulation..." << std::endl
			<< "5. Step Simulation..." << std::endl
			<< "6. Reset Simulation to Initial State..." << std::endl
			<< "7. Delete Vehicle ..." << std::endl
			<< "8. Delete Signal..." << std::endl
			<< "9. Delete Road..." << std::endl
			<< "10. Save Current Simulation State..." << std::endl
			<< "11. Load Simulation State..." << std::endl
			<< "12. Hide/Show Grid ..." << std::endl
			<< "13. Hide/Show Data..." << std::endl
			<< "0. Exit..." << std::endl;

		return ui_get_int_in_range(12, 0);

	}
	int ui_ask_question(std::string question, int max, int min) {
		std::cout << question << std::endl;;
		return ui_get_int_in_range(max, min);
	};

	std::pair<int, int> ui_ask_question(std::string question1, std::string question2, int max, int min) {
		std::pair<int, int> i;
		std::cout << question1 << std::endl;
		i.first = ui_get_int_in_range(max, min);
		std::cout << question2 << std::endl;
		i.second = ui_get_int_in_range(max, min);
		return i;
	}
	bool ui_is_road_vertical_or_horizontal(int x, int y, Grids& grid) {
		if (grid.getRoadsGrid(x, y).RoadA == nullptr) {
			return 1;
		}
		if (grid.getRoadsGrid(x, y).RoadA->getDirection() == North) {
			return true;
		}
		else {
			return false;
		}
	}

	std::string ui_get_string(std::string question) {
		std::cout << question <<std::endl;
		std::string answer;
		std::cin >> answer;
		return answer;
	}
	void SimPrint(Grids& Grid,SimulationEngine& Engine, std::vector<std::vector<std::string>> designs,bool enable1, bool enable2) {
		std::cout << "\033[2J\033[1;1H"; // Taken from Lab 7 Ex2 ,Clears screen and moves cursor to Top left Corner
		PrintGrids(Grid, designs, enable1);
		PrintData(Grid, Engine, enable2);

	}

	void ui_delete_Vehicle(Grids& Grid) {
		std::vector<Vehicle*> VofV = Grid.getVehicles();
		std::cout << "Please choose A Vehicle from below to delete :" << std::endl;
		for (int i = 1; i <= VofV.size(); i = i + 1) {
			std::cout << i << ". Vehicle Position: " << VofV[i - 1]->getX() << "," << VofV[i - 1]->getY() << " Vehicle Type: " << ui_Type(VofV[i - 1]) << " Vehicle Direction: " << ui_Direction(VofV[i - 1])<<std::endl;
		}
		std::cout<<"0. Return"<<std::endl;
		
		int choice = ui_get_int_in_range(VofV.size(), 0);
		if (choice==0) {
			return;
		}
		bool AorB = VofV[choice - 1]->getVehicleDirection() == North || VofV[choice - 1]->getVehicleDirection() == East;
		Grid.DeleteVehicle(VofV[choice - 1]->getX(), VofV[choice - 1]->getY(), AorB);
	}
	void ui_delete_Road(Grids& Grid) {
		std::vector<std::tuple<int, int, int, int, int>> VofR = Grid.getRoads();
		std::cout << "Please choose A Road from below to delete :" << std::endl;
		std::tuple<int, int, int, int, int> road;
		for (int i = 1; i <= VofR.size(); i = i + 1) {
			road = VofR[i - 1];
			std::cout << i << ". Road Starting Point: " << std::get<0>(road) << "," << std::get<1>(road) << " End point: " << std::get<2>(road) << "," << std::get<3>(road)<<std::endl;
		}
		std::cout<<"0. Return"<<std::endl;
		int choice = ui_get_int_in_range(VofR.size(), 0);
		if (choice==0) {
			return;
		}
		road = VofR[choice - 1];
		
		Grid.DeleteRoad(std::get<0>(road), std::get<1>(road), std::get<2>(road), std::get<3>(road));
	}
	void ui_delete_Signal(Grids& grid) {
		std::vector<Signal*> VofS = grid.getSignals();
		int x, y, P;
		bool green;

		std::cout << "Please choose a signal from below to delete. Selecting a signal which shares a space with others will delete all signals on that space :" << std::endl;

		for (int i = 0; i < VofS.size(); i++) {
			x = VofS.at(i)->getPos().first;
			y = VofS.at(i)->getPos().second;
			P = VofS.at(i)->getSeqPeriod();
			green = VofS.at(i)->isGreen();

			std::cout << i + 1 << ". Signal at (" << x << ", " << y << ") with a period of " << P << ", currently showing ";

			if (green) {
				std::cout << "Green";
			}
			else {
				std::cout << "Red";
			}
			std::cout << "." << std::endl;
		}

		int choice = ui_get_int_in_range(VofS.size(), 1) - 1;

		x = VofS.at(choice)->getPos().first;
		y = VofS.at(choice)->getPos().second;

		grid.DeleteSignal(x, y);
	}

	void ui_save(SimulationEngine& Engine) {

		std::string filename;
		std::cout << "Please enter filename to save simulation to: " << std::endl;
		std::cin >> filename;
		if (!Engine.save(filename)) {
			std::cout << "Error opening file, save incomplete" << std::endl;
			return;
		}
	}
	void ui_load(SimulationEngine& Engine) {
		std::string filename;
		std::cout << "Please enter filename to load simulation from: " << std::endl;
		std::cin >> filename;
		if (!Engine.load(filename)) {
			std::cout << "Error opening file, load incomplete" << std::endl;
			return;
		}

	}
	
	void ui_pause() {
			std::cout << "Press Enter to continue...";
			std::cin.get();
		}

	void ui_skip_to_number() {
		if (std::cin.fail()) {
			std::cin.clear();
			for (char ch; std::cin >> ch;) {
				if (('0' <= ch && ch <= '9') || ch == '-') {
					std::cin.unget();
					return;
				}
			}
			std::cout << "The stream is at eof or bad"
				<< "\n";
		}
	}
	int ui_get_int() {
		int number;
		while (true) {
			if (std::cin >> number) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears stream of characters, 
				return number;
			}
			std::cout << "Sorry that was not a number\n";
			ui_skip_to_number();
		}
	}
	