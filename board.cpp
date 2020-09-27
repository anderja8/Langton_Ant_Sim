/*********************************************************************
** Program name: board.cpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: CPP file that defines the public member functions of
**              the board class.
*********************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
** Builds the board object. Dynamically allocates a matrix of size
** row x col and sets all values of the matrix to the char ' '.
*********************************************************************/
Board::Board(int row, int col) {

	boardRow = row;
	boardCol = col;

	//dynamically allocate memory for the board matrix
	boardVals = new char*[boardRow];
	for (int i = 0; i < boardRow; ++i) {
		boardVals[i] = new char[boardCol];
	}

	//set all initial values to ' '.
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; ++j) {
			boardVals[i][j] = ' ';
		}
	}
}

/*********************************************************************
** Prints the boardVals values inside of a border. Also prints a '*'
** at the location of the passed ant object.
*********************************************************************/
void Board::printBoard(Ant &ant) {
	
	//debugging line
	//cout << "Beginning print board. Ant row is " << ant.getRow() << " column is " << ant.getColumn() << " and direction is " << ant.getOrientation() << endl;

	//print top border
	for (int i = 0; i < boardCol + 2; i++) {
		cout << "-";
	}

	//index the rows
	for (int i = 0; i < boardRow; i++) {

		//print side border
		cout << endl << "|";

		//if statement to check for ant and print *
		if (i == ant.getRow()) {

			for (int j = 0; j < boardCol; j++) {
				if (j == ant.getColumn()) {
					cout << "*";
				}
				else {
					cout << boardVals[i][j];
				}
			}
		}
		//otherwise just print boardVals
		else {
			for (int j = 0; j < boardCol; j++) {
				cout << boardVals[i][j];
			}
		}

		cout << "|";
	}

	cout << endl;

	//print bottom border
	for (int i = 0; i < boardCol + 2; i++) {
		cout << "-";
	}

	cout << endl;

	//debugging line
	//cout << "Ending print board. Ant row is " << ant.getRow() << " column is " << ant.getColumn() << " and direction is " << ant.getOrientation() << endl;
}

/*********************************************************************
** Changes the location and orientation of the passed ant object, and
** updates the board values according to the Langton's ant rules.
*********************************************************************/
void Board::makeMove(Ant &ant) {
	//debugging line
	//cout << "Beginning make move. Ant row is " << ant.getRow() << " column is " << ant.getColumn() << " and direction is " << ant.getOrientation() << endl;

	//change ant row and column (check for edge conditions and account for them)
	if (ant.getOrientation() == 0) {
		ant.setRow(ant.getRow() - 1);

		if (ant.getRow() < 0) {
			ant.setRow(boardRow - 1);
		}
	}

	if (ant.getOrientation() == 1) {
		ant.setColumn(ant.getColumn() + 1);

		if (ant.getColumn() >= boardCol) {
			ant.setColumn(0);
		}
	}

	if (ant.getOrientation() == 2) {
		ant.setRow(ant.getRow() + 1);

		if (ant.getRow() >= boardRow) {
			ant.setRow(0);
		}
	}

	if (ant.getOrientation() == 3) {
		ant.setColumn(ant.getColumn() - 1);

		if (ant.getColumn() < 0) {
			ant.setColumn(boardCol - 1);
		}
	}

	//read tile color ('#' or ' ') and change ant orientation
	ant.setOrientation(boardVals[ant.getRow()][ant.getColumn()]); //move this step

	//change space ant is occupying to opposite color
	if (boardVals[ant.getRow()][ant.getColumn()] == '#') {
		boardVals[ant.getRow()][ant.getColumn()] = ' ';
	}

	else if (boardVals[ant.getRow()][ant.getColumn()] == ' ') {
		boardVals[ant.getRow()][ant.getColumn()] = '#';
	}

	else {
		std::cout << "Error: unrecognized board tile. Tiles must be ' ' or '#'\n";
	}

	//Debugging line
	//cout << "Ending make move. Ant row is " << ant.getRow() << " column is " << ant.getColumn() << " and direction is " << ant.getOrientation() << endl;
}

/*********************************************************************
** Deletes the dynamically allocated boardVals matrix.
*********************************************************************/
void Board::deleteBoard() {
	for (int i = 0; i < boardRow; ++i) {
		delete [] boardVals[i];
	}
	
	delete [] boardVals;
}
	