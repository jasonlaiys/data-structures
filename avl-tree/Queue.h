/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#ifndef Queue_h
#define Queue_h



#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;



/********************************************************
Class declaration for Queue
Class is a generic/template
Class extends List
Functions are defined inline
********************************************************/
template <typename T>
class Queue : public List<T> {
public:

	/*
	* Default constructor for Queue class
	* Constructor calls its superclass' default constructor
	*/
	Queue() {

	}



	/*
	* Function that adds data to the queue
	*/
	void enqueue(T data) {
		this->add(data);
	}



	/*
	* Function that removes data from the queue
	*/
	T dequeue() {
		T value = peek();
		this->remove(value);
		return value;
	}



	/*
	* Function that returns the first data of the queue
	*/
	T peek() {
		Node<T>* nodePtr = this->getHead();

		while (nodePtr->getPrev() != nullptr) {
			nodePtr = nodePtr->getPrev();
		}

		T value = nodePtr->getData();
		return value;
	}



	/*
	* Function that returns the boolean value of whether the queue is empty
	*/
	bool isEmpty() {
		bool flag = this->isEmpty();
		return flag;
	}



	/*
	* Function that returns the length of the queue
	*/
	int getLength() {
		return this->getNumNodes();
	}



	/*
	* Class destructor for Queue
	*/
	~Queue() {

	}
};

#endif


