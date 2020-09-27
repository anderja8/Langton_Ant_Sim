/*********************************************************************
** Program name: menuFunctions.cpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: CPP file that defines the menu functions.
*********************************************************************/

#include "menuFunctions.hpp"
#include <iostream>

using std::cout;
using std::cin;

/*********************************************************************
** Welcomes the user to the Langton's ant simulation and asks them to
** start the simulation or quit. Returns their choice in integer form.
*********************************************************************/
int startAnt() {
	int initialChoice;
	int whileInt = 0;

	cout << "Welcome to the Langton's Ant Simulation. Please choose how to proceed.\n";
	cout << "1. Start Langton's Ant simulation\n";
	cout << "2. Quit\n";

	while (whileInt != 1) {
		cin >> initialChoice;
		
		if (initialChoice == 1 or initialChoice == 2) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter '1' for choice to start the simulation or '2' to quit.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return initialChoice;
}

/*********************************************************************
** Gets and validates input from the user to create the board and ant
** objects. In order to 'return' multiple inputs, all parameters are
** passed by reference.
*********************************************************************/
void getUserInput(int &rows, int &cols, int &steps, int &startRow, int &startCol, int &startDirection) {

	int whileInt = 0;

	//Display simulation rules to the user.
	cout << "\nBelow are some rules governing the simulation:\n";
	cout << "This simulation assumes the ant has already changed the color of the first tile.\n";
	cout << "This means that the color of the starting tile will display as white when the\n";
	cout << "ant moves off of it.\n";
	cout << "If the ant walks off the board, it will appear on the opposite side of the\n";
	cout << "board.\n";
	cout << "There is an option to have the ant start at a random position and face in a\n";
	cout << "random direction. When prompted for starting position and direction of the\n";
	cout << "ant, enter negative numbers.\n\n";
	cout << "Beginning simulation now.\n";

	//Get the number of rows
	cout << "Please enter the number of rows for the board. The minimum number of rows is 2.\n";

	while (whileInt != 1) {
		cin >> rows;
		
		if (rows > 1) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number > 1 and do not spell out the number.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	whileInt = 0;

	//Get the number of columns
	cout << "Please enter the number of columns for the board. The minimum number of columns is 2.\n";

	while (whileInt != 1) {
		cin >> cols;
		
		if (cols > 1) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number > 1 and do not spell out the number.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	whileInt = 0;

	//Get the number of steps
	cout << "Please enter the number of steps for the ant to take. The minimum number of steps is 1.\n";

	while (whileInt != 1) {
		cin >> steps;
		
		if (steps > 0) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number > 0 and do not spell out the number.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	whileInt = 0;

	//Get the starting row of the ant
	cout << "Please enter the starting row for the ant. The top row is 0\n";
	cout << "and the bottom row is the(number of rows - 1)\n";
	cout << "If you would like the ant to start on a random row, enter a negative number. \n";

	while (whileInt != 1) {
		cin >> startRow;
		
		if (startRow < 0) {
			startRow = rand() % rows;
			whileInt = 1;
		}
		else if (startRow < rows) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and (number of rows - 1), or a negative number for a random row.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	whileInt = 0;

	//Get the starting column of the ant
	cout << "Please enter the starting column for the ant. The far left column is 0\n";
	cout << "and the far right column is the (number of rows - 1)\n";
	cout << "If you would like the ant to start on a random column, enter a negative number. \n";

	while (whileInt != 1) {
		cin >> startCol;
		
		if (startCol < 0) {
			startCol = rand() % cols;
			whileInt = 1;
		}
		else if (startCol < cols) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and (number of rows - 1), or a negative number for a random column.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	whileInt = 0;

	//Get direction of the ant
	cout << "Please enter the starting direction for the ant. Enter '0' for North, '1' for East, '2' for South, and '3' for West\n";
	cout << "If you would like the ant to start in a random direction, enter a negative number. \n";

	while (whileInt != 1) {
		cin >> startDirection;
		
		if (startDirection < 0) {
			startDirection = rand() % 4;
			whileInt = 1;
		}
		else if (startDirection < 4) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter a number between 0 and 3, or a negative number for a random direction.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

/*********************************************************************
** Informs the user when the simulation ends and asks them if they
** would like to start again or quit. Returns their choice in integer
** form.
*********************************************************************/
int endAnt() {
	int finalChoice;
	int whileInt = 0;

	cout << "The simulation is now over. Please choose how to proceed.\n";
	cout << "1. Start Langton's Ant simulation again\n";
	cout << "2. Quit\n";

	while (whileInt != 1) {
		cin >> finalChoice;
		
		if (finalChoice == 1 or finalChoice == 2) {
			whileInt = 1;
		}
		else {
			cout << "Invalid input. Please enter '1' for choice to start the simulation or '2' to quit.\n";
		}
		
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return finalChoice;
}