/*********************************************************************
** Program name: menuFunctions.hpp
** Author: Jacob Anderson
** Date: 9/27/18
** Description: Header file that lists the menu functions.
*********************************************************************/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

/*********************************************************************
** Welcomes the user to the Langton's ant simulation and asks them to
** start the simulation or quit. Returns their choice in integer form.
*********************************************************************/
int startAnt();

/*********************************************************************
** Gets and validates input from the user to create the board and ant
** objects. In order to 'return' multiple inputs, all parameters are
** passed by reference.
*********************************************************************/
void getUserInput(int &rows, int &cols, int &steps, int &startRow, int &startCol, int &startDirection);

/*********************************************************************
** Informs the user when the simulation ends and asks them if they
** would like to start again or quit. Returns their choice in integer
** form.
*********************************************************************/
int endAnt();

#endif