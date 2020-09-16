// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#include "Maze.h"



Maze::Maze()
{
	_height = 0;
	_width = 0;
	_startX = 0;
	_startY = 0;
	_endX = 0;
	_endY = 0;
	_maze = nullptr;
}


Maze::Maze(std::string fileName)
{
	std::ifstream mazeFile(fileName); //opens the file
	std::string line; // variable holding the lines read

	// Read height and width
	std::getline(mazeFile, line);
	_height = std::stoi(line); // First line is the height of the maze
	std::getline(mazeFile, line);
	_width = std::stoi(line); // Second line is the width of the maze

	// Start the 2D array of Cell pointers
	_maze = new Cell**[_height];

	// Create the maze
	for (int i = 0; i < _height; i++)
	{
		std::getline(mazeFile, line);
		_maze[i] = new Cell*[_width];

		for (int j = 0; j < _width; j++)
		{
			_maze[i][j] = new Cell(line[j], j, i);

			if (_maze[i][j]->isStart())
			{
				_startX = j;
				_startY = i;
			}
			if (_maze[i][j]->isEnd())
			{
				_endX = j;
				_endY = i;
			}
		}
	}
}

// The maze object is the one making the cells, so it's 
// responsible for deleting all the cells
Maze::~Maze()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			delete _maze[i][j]; // Deletes each individual Cell
		}
		delete[] _maze[i]; // Deletes the 2D array of Cells
	}
	delete[] _maze; // Deletes the maze
}

Cell* Maze::getStart() // Gets the Start of the maze
{
	return _maze[_startY][_startX];
}

void Maze::draw() // Draws out the maze
{
	std::cout << this->to_string() << "\n" << std::endl;
}

bool Maze::isLocationValid(int x, int y) // Verifies if the location is within the maze
{
	return y >= 0 && y < _height && x >= 0 && x < _width;
}

std::string Maze::to_string() // The string version of the maze
{
	std::string s = "";

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			s+= _maze[i][j]->getSymbol();
		}
		s += "\n";
	}
	return s;
}

Cell* Maze::getNextNeighbour(Cell* cur)
{
	int x = cur->getX(); // Gets the current Cell's x coordinate
	int y = cur->getY(); // Gets the current Cell's y coordinate

	// Go clockwise
	// note, y-1 means up, not down
	int xs[4] = { x,     x + 1, x,     x - 1 }; // the 4 x coordinates around the current Cell
	int ys[4] = { y - 1, y,     y + 1, y }; // the 4 y coordinates around the current Cell

	int nX = 0;
	int nY = 0;

	// Iterate over the 4 possible neighbours 
	for (int i = 0; i < 4; i++)
	{
		nX = xs[i];
		nY = ys[i];

		// If the location is in the map 
		if (isLocationValid(nX, nY))
		{
			// If the cell is eligible to move into (not currently in stack, or looked)
			// Basically, if it's open or it's the end. 
			if (_maze[nY][nX]->getSymbol() == ' ' || _maze[nY][nX]->getSymbol() == 'E')
			{
				return _maze[nY][nX]; // return the pointer to Cell
			}
		}
	}

	// If we get here, then there is no eligible neighbour
	return nullptr;
}

Cell* Maze::getEnd() // Gets a pointer to the End of the maze
{
	return _maze[_endY][_endX];
}

double Maze::distanceToEnd(Cell* cur) // Gets the distance to the end of the maze from the current Cell
{
	double curX = (double)cur->getX();
	double curY = (double)cur->getY();

	return std::sqrt(std::pow(_endX - curX, 2) + std::pow(_endY - curY, 2));
}


int Maze::drawFinalPath() // Draws the shortest path to the End
{
	int steps = 1;
	Cell* cur = getEnd(); // Pointer to End Cell
	int stm = cur->getStepsToMe(); // Gets to Steps to the End

	while (stm >= 0)
	{
		steps++;
		cur->setSymbol('@'); // Sets the symbols of the Cell in the path

		int x = cur->getX(); // the x coordinate of the End Cell
		int y = cur->getY(); // the y coordinate of teh End Cell

		int nX = 0;
		int nY = 0;

		// Go clockwise
		// note, y-1 means up, not down
		int xs[4] = { x,     x + 1, x,     x - 1 }; // Gets x coordinate for possible neighbors
		int ys[4] = { y - 1, y,     y + 1, y }; // y coordinates for possible neighbors

		for (int i = 0; i < 4; i++)
		{
			nX = xs[i];
			nY = ys[i];

			// If the location is in the map 
			if (isLocationValid(nX, nY))
			{
				if (_maze[nY][nX]->getStepsToMe() == cur->getStepsToMe() - 1) // backtracks to the neighbor before the current End Cell
				{
					cur = _maze[nY][nX]; // Sets the cur Cell to the new Cell
					stm = cur->getStepsToMe(); // Gets the new Cell Steps to Me
					break;
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		draw();

		if (stm == 0) // if the Steps to Me is at the Start
		{
			cur->setSymbol('@'); // Sets the symbol of the Start 
			break;
		}
	}
	return steps; // Returns the Steps of the path with shortest steps
}