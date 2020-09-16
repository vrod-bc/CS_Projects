// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 

#include <chrono>
#include <thread>
#include <iostream>

#include "Cell.h"
#include "LinkedMinPriorityQueue.h"
#include "Maze.h"
#include "PriorityNode.h"

int main(int argc, char* argv[])
{
		Maze* m = new Maze(argv[1]); // creating the maze
		Cell* start_maze = m->getStart(); // gets a pointer to the start of the maze

		start_maze->setStepsToMe(0); // sets the stepsToMe for start to zero
		Cell* cell = start_maze; // pointer to a Cell
		Cell* neighbor = nullptr;
		LinkedMinPriorityQueue<Cell*>* q = new LinkedMinPriorityQueue<Cell*>(); // Creates Linked Priority Queue

		q->enqueue(start_maze, start_maze->getStepsToMe() + m->distanceToEnd(start_maze)); // Adds the Start Cell to the Queue

		m->draw(); // Draw the maze
		int ite = 0; // iteration counter

		while (!q->is_empty()) // While the Queue is not empty
		{
			q->dequeue(); // Remove a Cell
			ite++; // Update the iteration counter
			if (cell->isEnd()) // The Cell is at the End
			{
				cell->setSymbol('X'); // Update the symbol
				break; // Break out of the loop 
			}

			cell->setSymbol('O'); // Sets the symbol of the current Cell
			m->draw(); // Draws the maze

			for (int i = 0; i < 4; i++) // Iterate over the 4 neighbors
			{
				cell = m->getNextNeighbour(cell); // Pointer to one of the neighbor

				if (cell != nullptr) // If the neighbor exists 
				{
					cell->setStepsToMe(ite); // Sets its Steps to the number it took to get to the neighbor
					q->enqueue(cell, cell->getStepsToMe() + m->distanceToEnd(cell)); // Add it to the Queue
				}
				
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			m->draw(); // Draw the Queue
			cell->setSymbol('.'); // Update the current cells symbol 
		}

		m->drawFinalPath();
		std::cout << "Final State" << std::endl;
		std::cout << "Steps in Final Path: " << cell->getStepsToMe() << std::endl;
		std::cout << "Total Steps: " << ite << std::endl;
		delete m;
		delete q;
		_CrtDumpMemoryLeaks();
		return 0;
}
