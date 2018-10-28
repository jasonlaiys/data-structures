/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#ifndef Node_h
#define Node_h



#include "stdafx.h"



/********************************************************
Class declaration for Node
Class is a generic/template
Functions are defined inline
********************************************************/
template <typename T>
class Node {
private:
	T data; //var to hold data
	Node<T> *prev; //pointer to previous node
	Node<T> *next; //pointer to next node

public:

	/*
	* Default constructor for Node class
	* Constructor initializes pointer to previous node as nullptr
	*      and initializes data variable to NULL
	*/
	Node() {
		data = NULL;
		prev = nullptr;
		next = nullptr;
	}



	/*
	* Overloaded constructor for Node class
	* Constructor initializes pointer to previous node as nullptr
	*      and initializes data variable to value passed into function
	*      parameter
	*/
	Node(T data) {
		this->data = data;
		prev = nullptr;
	}



	/*
	* Getter function that returns pointer to previous node as a
	*      const variable
	*/
	Node<T>* getPrev() const {
		return prev;
	}



	/*
	* Setter function to set value of pointer to previous node
	*/
	void setPrev(Node<T>* prev) {
		this->prev = prev;
	}



	/*
	* Getter function that returns pointer to next node as a
	*      const variable
	*/
	Node<T>* getNext() const {
		return next;
	}



	/*
	* Setter function to set value of pointer to next node
	*/
	void setNext(Node<T>* next) {
		this->next = next;
	}



	/*
	* Getter function that returns value of data as a ref variable
	*/
	T& getData() {
		return data;
	}



	/*
	* Setter function to set value of data
	*/
	void setData(T data) {
		this->data = data;
	}
};

#endif;


