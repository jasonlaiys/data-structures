/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#ifndef Stack_h
#define Stack_h



#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;



/********************************************************
Class declaration for Stack
Class is a generic/template
Class extends List
Functions are defined inline
********************************************************/
template <typename T>
class Stack : public List<T> {
public:

	/*
	* Default constructor for Stack class
	* Constructor calls its superclass' default constructor
	*/
	Stack() {

	}



	/*
	* Function that adds data to the stack
	*/
	void push(T data) {
		List<T>::add(data);
	}



	/*
	* Function that removes and returns the first data of the stack
	*/
	T pop() {
		T value = this->getHead()->getData();
		this->remove(value);
		return value;
	}



	/*
	* Function that returns the first data of the stack
	*/
	T peek() {
		T value = this->getHead()->getData();
		return value;
	}



	/*
	* Function that returns the boolean value of whether the stack is empty
	*/
	bool isEmpty() {
		bool flag = List<T>::isEmpty();
		return flag;
	}



	/*
	* Function that returns the length of the stack
	*/
	int getLength() {
		return this->getNumNodes();
	}



	/*
	* Class destructor for Stack
	*/
	~Stack() {

	}
};

#endif



