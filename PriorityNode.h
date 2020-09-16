// NAME: Veronica Rodarte
// STUDENT #: 201704466
// EMAIL: x2017vol@stfx.ca

#pragma once

template <class T>
class PriorityNode
{
private:
	PriorityNode<T>* _next;
	T _data;
	double _priority;

public:
	PriorityNode();
	PriorityNode(T data, double priority);
	PriorityNode(const PriorityNode<T>& obj);
	~PriorityNode();

	PriorityNode<T>* getNext(); 
	void setNext(PriorityNode<T>* node);
	T getData();
	void setData(T data);

	double getPriority();

};

// Put stuff here 


// Default Constructor
template <class T>
PriorityNode<T>::PriorityNode()
{
	_data = 0;
	_next = nullptr;
	_priority = 0.0;
}

// Constructor 
template <class T>
PriorityNode<T>::PriorityNode(T data, double priority)
{
	_data = data; 
	_priority = priority; // the Steps to me + Distance to the end
}

//Copy Constructor
template <class T>
PriorityNode<T>::PriorityNode(const PriorityNode<T>& obj)
{
	_data = obj._data;
	_next = obj._next;
	_priority = obj._priority;
}

/*
Deconstructor 
No need to delete anything
*/
template <class T>
PriorityNode<T>::~PriorityNode()
{
	//Nothing
}

template <class T>
PriorityNode<T>* PriorityNode<T>::getNext() // Gets the current Cell's next Cell
{
	return _next;
}

template <class T>
void PriorityNode<T>::setNext(PriorityNode<T>* node) // Sets the current Cell's next
{
	_next = node;
}

template <class T>
T PriorityNode<T>::getData() // Gets the Cell's data
{
	return _data;
}

template <class T>
void PriorityNode<T>::setData(T data) // Sets the Cell's data
{
	_data = data;
}

template <class T>
double PriorityNode<T>::getPriority() // Gets the Cell's priority
{
	return _priority;
}