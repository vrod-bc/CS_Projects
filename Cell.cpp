// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#include "Cell.h"

//Default Constructor
Cell::Cell()
{
	_symbol = ' ';
	_isStart = false; // Checks if Cell is the Start
	_isEnd = false; // Checks if Cell is the End
	_x = 0; // X coordinate of the Cell
	_y = 0; // Y coordinate of the Cell
	_stepsToMe = -1; // Keeps track of the number of Steps it takes to get to Cell
}

//Constructor 
Cell::Cell(char c, int x, int y)
{
	_symbol = c; // Sets the Cell's symbol
	_x = x;
	_y = y;
	_isStart = (_symbol == 'S'); 
	_isEnd = (_symbol == 'E');
	_stepsToMe = -1; 
}

// Copy Constructor
Cell::Cell(const Cell& obj)
{
	_symbol = obj._symbol;
	_isStart = obj._isStart;
	_isEnd = obj._isEnd;
	_x = obj._x;
	_y = obj._y;
	_stepsToMe = obj._stepsToMe;
}

/*
Deconstructor
No need to delete anything
*/
Cell::~Cell()
{
	// Nothing special
}

char Cell::getSymbol() // Gets the symbol of the Cell
{
	return _symbol;
}

void Cell::setSymbol(char c) // Sets the symbol of the Cell
{
	_symbol =c;
}

bool Cell::isStart() // Checks if the Cell is the Start
{
	return _isStart;
}

bool Cell::isEnd() // Checks if the Cell is the End
{
	return _isEnd;
}

int Cell::getX() // Gets the X coordinate of the Cell
{
	return _x;
}

int Cell::getY() // Gets the Y coordinate of the Cell
{
	return _y;
}



// New

int Cell::getStepsToMe() // Gets the number of Steps it took to get to the Cell
{
	return _stepsToMe;
}


void Cell::setStepsToMe(int steps) // Sets the number of Steps it takes to get to the Cell
{
	_stepsToMe = steps; 
}
