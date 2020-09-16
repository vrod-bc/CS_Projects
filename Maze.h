// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#pragma once

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "Cell.h"

class Maze
{
private:
	int _height;
	int _width;
	int _startX;
	int _startY;
	int _endX;
	int _endY;

	Cell*** _maze;

public:
	Maze();
	Maze(std::string fileName);
	~Maze();

	Cell* getStart();
	bool isLocationValid(int x, int y);
	
	void draw();
	std::string to_string();

	// Changed a little
	Cell* getNextNeighbour(Cell* cur);

	// New
	Cell* getEnd();
	double distanceToEnd(Cell* cur);
	int drawFinalPath();

};

