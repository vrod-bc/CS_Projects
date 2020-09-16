// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#pragma once

#include "PriorityNode.h"

template <class T>
class LinkedMinPriorityQueue
{
private: 
	int _size;
	PriorityNode<T>* _front;
	PriorityNode<T>* _rear;

public:
	LinkedMinPriorityQueue();
	LinkedMinPriorityQueue(const LinkedMinPriorityQueue<T>& obj);
	~LinkedMinPriorityQueue();

	void enqueue(T element, double priority);
	T dequeue();
	int size();
	bool is_empty();
};


// You write here now

//Default Constructor
template <class T>
LinkedMinPriorityQueue<T>::LinkedMinPriorityQueue()
{
	_size = 0;
	_front = nullptr;
	_rear = nullptr;
}

// Copy Constructor
template <class T>
LinkedMinPriorityQueue<T>::LinkedMinPriorityQueue(const LinkedMinPriorityQueue& obj)
{
	PriorityNode<T>* cur = obj._front;
	while (cur != nullptr)
	{
		enqueue(cur->getData());
		cur = cur->getNext();
	}
}

// Deconstructor
template <class T>
LinkedMinPriorityQueue<T>::~LinkedMinPriorityQueue()
{
	while (!is_empty())
	{
		dequeue(); // Removes all the Cells in the Queue
	}
}

template <class T>
void LinkedMinPriorityQueue<T>::enqueue(T element, double priority) // Adds Cells to the Queue
{
	PriorityNode<T>* node = new PriorityNode<T>(element, priority); // New element to be added to Queue
	PriorityNode<T>* iterateNode = _front; // Creates a pointer to the front of the Queue in order to iterate over the Queue
	
	if (is_empty()) // If the Queue is empty 
	{
		_front = node; // Set the front to the element to be added
		_rear = node; // Set the rear to the element to be added
	}
	else
	{
		for (int i = 0; i < _size; i++) // iterate over the Queue
		{
			if (node->getPriority() < _front->getPriority()) // If priority less than front
			{
				node->setNext(_front);
				_front = node;
			}
			if (node->getPriority() > _rear->getPriority()) // If priority greater than rear
			{
				_rear->setNext(node);
				_rear = node;
			}
			if (node->getPriority() > _front->getPriority() && node->getPriority() < _rear->getPriority()) 
			{
				for (int i = 0; i < _size; i++) // Iterate over the Queue
				{
					if (node->getPriority() < iterateNode->getNext()->getPriority()) // Place node within the correct order of priority
					{
						node->setNext(iterateNode->getNext());
						iterateNode->setNext(node);
					}
					iterateNode = iterateNode->getNext();
				}
			}
		}
	}
	_size++;
}

template <class T>
T LinkedMinPriorityQueue<T>::dequeue() // Removes a Cell out of Queue from the front
{
	if (is_empty())
	{
		throw std::exception("Queue is empty");
	}

	PriorityNode<T>* toDelete = _front; // Creates a pointer to the front of the Queue
	T result = _front->getData(); // Holds the data of the Cell to be deleted
	_front = _front->getNext(); // Front of the Cell points to the next Cell
	_size--; // Decreases the size of the Queue
	if (is_empty()) // If the Queue is empty
	{
		_rear = nullptr; // Sets the rear to point to nothing
	}
	delete toDelete; // Deletes the pointer to be removed
	return result; // Returns the data of the deleted Cell
}

template <class T>
int LinkedMinPriorityQueue<T>::size() // Returns the size of the Queue
{
	return _size;
}

template <class T>
bool LinkedMinPriorityQueue<T>::is_empty() // Checks if the Queue is empty
{
	return _size == 0;
}