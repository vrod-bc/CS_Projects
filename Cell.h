// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#pragma once
class Cell
{
private:
	char _symbol;
	bool _isStart;
	bool _isEnd;
	int _x;
	int _y;

	// New
	int _stepsToMe;


public:
	Cell();
	Cell(char c, int x, int y);
	Cell(const Cell& obj);
	~Cell();

	bool isEnd();
	bool isStart();
	char getSymbol();
	void setSymbol(char c);
	int getX();
	int getY();

	// New
	int getStepsToMe();
	void setStepsToMe(int steps);
};

