/*********************************************************************
** Program name: Ant.hpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: Header file that defines the ant class. This class
**              will store the ant location and orientation. It also
**              provides functionality to change the location and
**              orientation of the ant.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
private:
	int antRow, antColumn, antOrientation;
	
public:
	
	/*********************************************************************
	** Builds the ant object. Sets the the private member variables
	** based on input by the user. Then prints the values specified.
	*********************************************************************/
	Ant(int row, int col, int direction);

	/*********************************************************************
	** Sets the row member variable with input from the user.
	*********************************************************************/
	void setRow(int row);
	
	/*********************************************************************
	** Gets the row member variable.
	*********************************************************************/
	int getRow();

	/*********************************************************************
	** Sets the column member variable with input from the user.
	*********************************************************************/
	void setColumn(int col);

	/*********************************************************************
	** Gets the column member variable.
	*********************************************************************/
	int getColumn();

	/*********************************************************************
	** Sets the ant orientation member variable with input from the user.
	*********************************************************************/
	void setOrientation(char direction);

	/*********************************************************************
	** Gets the ant orientation member variable.
	*********************************************************************/
	int getOrientation();
};

#endif	