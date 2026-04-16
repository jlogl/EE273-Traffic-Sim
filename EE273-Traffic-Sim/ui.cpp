#include <iostream>;
#include <string>
#include <tuple>
#include "ui.h"


using namespace std;

int top_lvl() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tConfigure road layout" << endl	// opens only if the grid has been set;
												// intersection menu opens automatically if 2 or more roads share the same grid space
		<< "2\tManage signals" << endl	// opens only if at least one road has been created
		<< "3\tManage vehicles"	<< endl	// opens only if at least one road has been created
		<< "4\tLoad simulation..." << endl
		<< "5\tSave simulation..." << endl
		<< "0\tExit program" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 5));
}
/*
pair<int, int> ui_grid() {
	int r, c;
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please enter the number of rows in the grid:\n";
	r = get_int();
	cout << "Please enter the number of columns in the grid:\n";
	c = get_int();

	return{ r,c };
}
*/
int ui_roads() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tPlace new road..." << endl
		<< "2\tRemove road..." << endl
		<< "3\tModify road..." << endl		// not sure if possible with current implementation
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
int ui_signals() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tPlace new signal..." << endl
		<< "2\tRemove signal..." << endl
		<< "3\tModify signal..." << endl		// not sure if possible with current implementation
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
int ui_vehicles() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tCreate new vehicle..." << endl
		<< "2\tRemove vehicle..." << endl
		<< "3\tModify vehicle..." << endl		// not sure if possible with current implementation
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
/*
int type_road() {	// (possibly redundant)
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please specify the type of road from the options below (enter the number):" << endl
		<< "1\tOne lane (one way)" << endl		// traffic in one direction only, no more than one vehicle present at any time
		<< "2\tTwo lanes" << endl				// traffic flows in two opposing directions, up to two vehicles
		<< "0\tGo back" << endl					// return to road options
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 2));
*/
void ui_junction(Junction& j) {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "A ";

	switch (j.getJunctionType()) {
	case turn:
		cout << "turn ";
		break;
	case corner:
		cout << "corner ";
		break;
	case t:
		cout << "t-";
		break;
	case cross:
		cout << "crossroad ";
		break;
	}

	cout << "junction has been created with another road!" << endl;
	return;
}
type type_vehicle() {
	cout << "\033[2J\033[1;1H"; // clear the screen

	cout << "Please specify the type of vehicle from the options below (enter the number):" << endl
		<< "1\tCar" << endl
		<< "2\tBus" << endl
		<< "3\tBike" << endl
		<< "0\tGo back" << endl
		<< "\nEnter Action: ";

	return type(ui_get_int_in_range(0, 3));
}

pair<int, int> start_road() {
	int x = 0, y = 0;

	cout << "The end position must lie on either the same row or the same column as the start position so that the road is horizontal or vertical.\n\n";

	cout << "\033[2J\033[1;1H"; // clear the screen

	cout << "Enter the starting x position: ";
	x = ui_get_int_in_range(0, Grids::grid_size);

	cout << "Enter the starting y position: ";
	y = ui_get_int_in_range(0, Grids::grid_size);

	return make_pair(x, y);
}
pair<int, int> end_road(pair<int, int> startPos) {
	int x = 0, y = 0;

	do {
		cout << "Enter the ending x position: ";
		x = ui_get_int_in_range(0, Grids::grid_size);

		cout << "Enter the ending y position: ";
		y = ui_get_int_in_range(0, Grids::grid_size);
	} while ( !(startPos.first == x || startPos.second == y) );

	return make_pair(x, y);
}
pair<int, int> ui_get_pos() {
	int x = 0, y = 0;
	cout << "\033[2J\033[1;1H"; // clear the screen

	cout << "Enter the x component: ";
	x = ui_get_int_in_range(0, Grids::grid_size);

	cout << "Enter the y component: ";
	y = ui_get_int_in_range(0, Grids::grid_size);

	return make_pair(x, y);
}
int ui_get_speed_lmt() {
	cout << "Enter the speed limit: ";
	
	return(ui_get_int_in_range(0, 10));			// 10 IS AN EXAMPLE HERE
}

void ui_print(string message) {
	char a;		// arbritary character, gets deallocated before it can be used

	cout << message << endl
		<< "Enter any character to continue... ";
	cin >> a;
}

/*
void ui_notify(string message) {
	char a;		// arbritary character, gets deallocated before it can be used

	cout << "\033[2J\033[1;1H"; // clear the screen

	cout << "----------------------------------------" << endl
		<< message << endl
		<< "----------------------------------------" << endl << endl
		<< "Enter any character to continue..." << endl;
	cin >> a;
}
*/

int ui_get_int() {
	int number;
	while (true) {
		if (cin >> number) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
		cout << "Sorry that was not a number\n";
		ui_skip_to_number();
	}
}

int ui_get_int_in_range(int low, int high) {
	while (true) {
		int number = ui_get_int();
		if (low <= number && number <= high) {
			return number;
		}
		cout << "Sorry the number is not between " << low << " and "
			<< high << "; Try again...\n";
	}
}
char ui_get_char() {
	char c;
	if (cin >> c) {
		return c;
	}
	cout << "Sorry that was not a character\n";
}
bool ui_get_bool() {
	while (true) {
		char ans = ui_get_char();
		if (ans == 'y' || ans == 'Y') {
			return 1;
		}
		else if (ans == 'n' || ans == 'N') {
			return 0;
		}
		cout << "Sorry that response is invalid; Try again...\n";
	}
}

void ui_skip_to_number() {
	if (cin.fail()) {
		cin.clear();
		for (char ch; cin >> ch;) {
			if (('0' <= ch && ch <= '9') || ch == '-') {
				cin.unget();
				return;
			}
		}
		cout << "The stream is at eof or bad\n";
	}
}
