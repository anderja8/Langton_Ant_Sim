/*********************************************************************
** Program name: ant.cpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: CPP file that defines the public member functions of
**              the ant class.
*********************************************************************/

#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
** Builds the ant object. Sets the the private member variables
** based on input by the user. Then prints the values specified.
*********************************************************************/
Ant::Ant(int row, int col, int direction) {
	antRow = row;
	antColumn = col;
	antOrientation = direction;
	
	cout << "The starting row of the ant is: " << antRow << endl;
	cout << "The starting column of the ant is : " << antColumn << endl;
	cout << "The ant is facing ";

	if (antOrientation == 0) {
		cout << "north" << endl << endl;
	}
	else if (antOrientation == 1) {
		cout << "east" << endl << endl;
	}
	else if (antOrientation == 2) {
		cout << "south" << endl << endl;
	}
	else {
		cout << "west" << endl << endl;
	}
}

/*********************************************************************
** Sets the row member variable with input from the user.
*********************************************************************/
void Ant::setRow(int row) {
	antRow = row;
}

/*********************************************************************
** Gets the row member variable.
*********************************************************************/
int Ant::getRow() {
	return antRow;
}

/*********************************************************************
** Sets the column member variable with input from the user.
*********************************************************************/
void Ant::setColumn(int col) {
	antColumn = col;
}

/*********************************************************************
** Gets the column member variable.
*********************************************************************/
int Ant::getColumn() {
	return antColumn;
}

/*********************************************************************
** Sets the ant orientation member variable with input from the user.
*********************************************************************/
void Ant::setOrientation(char direction) {

	if (direction == ' ') {
		antOrientation += 1;
		if (antOrientation > 3) {
			antOrientation = 0;
		}
	}
	else if (direction == '#') {
		antOrientation -= 1;
		if (antOrientation < 0) {
			antOrientation = 3;
		}
	}
	else {
		std::cout << "Error: unrecognized board tile. Tiles must be ' ' or '#'\n";
	}
}

/*********************************************************************
** Gets the ant orientation member variable.
*********************************************************************/
int Ant::getOrientation() {
	return antOrientation;
}