/*********************************************************************
** Program name: Board.hpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: Header file that defines the board class. This class
**              will store the number of rows and columns of the 
**              board, and the values of each tile of the board.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Ant.hpp"

class Board
{
private:
	char** boardVals;
	int boardRow;
	int boardCol;

public:
	/*********************************************************************
	** Builds the board object. Dynamically allocates a matrix of size
	** row x col and sets all values of the matrix to the char ' '.
	*********************************************************************/
	Board(int row, int col);

	/*********************************************************************
	** Prints the boardVals values inside of a border. Also prints a '*'
	** at the location of the passed ant object.
	*********************************************************************/
	void printBoard(Ant &ant);

	/*********************************************************************
	** Changes the location and orientation of the passed ant object, and
	** updates the board values according to the Langton's ant rules.
	*********************************************************************/
	void makeMove(Ant &ant);
	
	/*********************************************************************
	** Deletes the dynamically allocated boardVals matrix.
	*********************************************************************/
	void deleteBoard();
};

#endif	