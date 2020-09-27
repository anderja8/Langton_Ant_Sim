/*********************************************************************
** Program name: Main.cpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: CPP file that defines the main function. Uses the
** menu functions, ant object, and board object to run a Langton's
** ant simulation with conditions specifed by the user.
*********************************************************************/

#include "Ant.hpp"
#include "Board.hpp"
#include "menuFunctions.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::rand;

//Input validation won't catch '123abc'

int main() {
	int initialSelect;
	int finalSelect = 1;
	int rows;
	int cols;
	int steps;
	int startRow;
	int startCol;
	int startDirection;
	
	initialSelect = startAnt();

	while (finalSelect != 2) {
		if (initialSelect == 1) {

			//Get and validate user input
			getUserInput(rows, cols, steps, startRow, startCol, startDirection);

			//Build the ant object
			Ant ant(startRow, startCol, startDirection);

			//Build the board object
			Board gameBoard(rows, cols);

			//start the game
			for (int i = 0; i <= steps; i++) {

				gameBoard.printBoard(ant);
				cout << "Step " << i << " of " << steps << endl;
				cout << "Press enter to continue.\n";
				cin.get();
				cout << endl;

				if (i != steps) {
					gameBoard.makeMove(ant);
				}
			}

			//Get and validate whether to quit or start over
			finalSelect = endAnt();

			//Delete the dynamically allocated gameboard
			gameBoard.deleteBoard();

		}
	}
	
	return 0;
}