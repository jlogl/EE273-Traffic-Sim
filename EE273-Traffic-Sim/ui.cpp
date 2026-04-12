#include <iostream>;
#include <string>
#include <tuple>
#include "ui.h"

using namespace std;

int top_lvl() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tSet grid size" << endl	// opens grid menu, then gives options for other menus
		<< "2\tConfigure road layout" << endl	// opens only if the grid has been set;
												// intersection menu opens automatically if 2 or more roads share the same grid space
		<< "3\tManage signals" << endl	// opens only if at least one road has been created
		<< "4\tManage vehicles"	<< endl	// opens only if at least one road has been created
		<< "5\tLoad simulation..." << endl
		<< "6\tSave simulation..." << endl
		<< "0\tExit program" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 6));
}
pair<int, int> ui_grid() {
	int r, c;
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please enter the number of rows in the grid:\n";
	r = get_int();
	cout << "Please enter the number of columns in the grid:\n";
	c = get_int();

	return{ r,c };
}
int ui_roads() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tPlace new road..." << endl
		<< "2\tModify road..." << endl
		<< "3\tRemove road..." << endl
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
int ui_signals() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tPlace new signal..." << endl
		<< "2\tModify signal..." << endl
		<< "3\tRemove signal..." << endl
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
int ui_vehicles() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please select one of the options below (enter the number):" << endl
		<< "1\tCreate new vehicle..." << endl
		<< "2\tModify vehicle..." << endl
		<< "3\tRemove vehicle..." << endl
		<< "0\tMain menu" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
}
int type_road() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please specify the type of road from the options below (enter the number):" << endl
		<< "1\tOne lane (one way)" << endl		// traffic in one direction only, no more than one vehicle present at any time
		<< "2\tTwo lanes" << endl				// traffic flows in two opposing directions, up to two vehicles
		<< "0\tGo back" << endl					// return to road options
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 2));
}
int type_intersection() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "An intersection has been created with another road!" << endl
		<< "Please specify the type of intersection from the options below(enter the number) :" << endl
		<< "1\tCrossroads" << endl					// 
		<< "2\tRoundabout" << endl					// give way to the right
		<< "3\tSliproads" << endl					// dont have to worry about collisions
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(1, 3));
}
int type_vehicle() {
	cout << "\033[2J\033[1;1H"; // clear the screen
	cout << "Please specify the type of vehicle from the options below (enter the number):" << endl
		<< "1\tCar" << endl
		<< "2\tBus" << endl
		<< "3\tBike" << endl
		<< "0\tGo back" << endl
		<< "\nEnter Action: ";
	return(ui_get_int_in_range(0, 3));
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