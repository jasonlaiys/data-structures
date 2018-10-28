/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#ifndef List_h
#define List_h



#include "stdafx.h"
#include "ListInterface.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;



/********************************************************
Class declaration for List
Class is a generic/template
Class extends ListInterface
Functions are defined inline
********************************************************/
template <typename T>
class List : public ListInterface<T> {
private:
	Node<T> *head; //head of the linked list
	int numNodes; //var for number of nodes in the list

public:

	/*
	* Default constructor for List class
	* Constructor initializes pointer to head as nullptr
	*      and initializes numNodes to 0
	* Constructor calls its superclass' default constructor
	*/
	List() {
		head = nullptr;
		numNodes = 0;
	}



	/*
	* Getter function that returns value of number of nodes as a const variable
	*/
	int getNumNodes() const {
		return numNodes;
	}



	/*
	* Getter function that returns pointer to list head as a const variable
	*/
	Node<T>* getHead() const {
		return head;
	}



	/*
	* Function that returns a boolean value of whether the linked list is empty
	*/
	virtual bool isEmpty() {
		if (numNodes == 0)
			return true;
		else
			return false;
	}



	/*
	* Function that adds a new node to the linked list
	* Returns true if the operation is successful
	* Returns false as default return value if operation is unsuccessful
	*/
	virtual bool add(T newEntry) {
		Node<T> *newNode = new Node<T>(newEntry);

		if (head == nullptr) {
			newNode->setPrev(nullptr);
			newNode->setNext(nullptr);
			head = newNode;
			numNodes++;
			return true;
		}

		else {
			newNode->setPrev(head);
			head->setNext(newNode);
			head = newNode;
			numNodes++;
			return true;
		}

		return false;
	}



	/*
	* Function that removes a node from the linked list
	* Returns true if the operation is successful
	* Returns false as default return value if operation is unsuccessful
	*/
	virtual bool remove(T entry) {
		Node<T> *nodePtr;
		Node<T> *nextNode;

		if (head == nullptr) {
			return false;
		}

		if (head->getData() == entry) {
			if (head->getPrev() != nullptr) {
				nodePtr = head->getPrev();
				nodePtr->setNext(nullptr);
				delete head;
				numNodes--;
				head = nodePtr;
			}
			else {
				head = nullptr;
				numNodes--;
			}
			return true;
		}

		else {
			nodePtr = head;
			nextNode = nullptr;

			while (nodePtr != nullptr && nodePtr->getData() != entry) {
				nextNode = nodePtr;
				nodePtr = nodePtr->getPrev();
			}

			if (nodePtr->getData() == entry) {
				nextNode->setPrev(nodePtr->getPrev());
				if (nodePtr->getPrev() != nullptr)
					nodePtr->getPrev()->setNext(nextNode);
				delete nodePtr;
				numNodes--;
				return true;
			}

		}

		return false;
	}



	/*
	* Function that removes all nodes from the linked list
	*/
	virtual void clear() {
		Node<T> *nodePtr;
		Node<T> *prevNode;

		nodePtr = head;

		while (nodePtr != nullptr) {
			prevNode = nodePtr->getPrev();
			delete nodePtr;
			numNodes--;
			nodePtr = prevNode;
		}

		head = nullptr;
	}



	/*
	* Function that searches for a specific value in the linked list
	* Returns true if the value/data exists
	* Returns false if the value/data does not exist
	*/
	virtual bool search(T entry) {
		Node<T> *nodePtr;

		nodePtr = head;

		while (nodePtr->getData() != entry) {
			nodePtr = nodePtr->getPrev();
		}

		if (nodePtr->getData() == entry)
			return true;

		else
			return false;
	}



	/*
	* Function that prints the data of all nodes in the list
	*/
	void printList() {
		Node<T> *nodePtr;

		nodePtr = head;

		while (nodePtr != nullptr) {
			cout << nodePtr->getData() << " ";
			nodePtr = nodePtr->getPrev();
		}

		cout << endl;
	}



	/*
	* Function that overloads the == operator for objects of List
	*/
	friend bool operator == (List<T> &l1, List<T> &l2) {
		bool flag = false;

		if (l1.getNumNodes() != l2.getNumNodes())
			return flag;

		Node<T> *nodePtr1 = l1.getHead();
		Node<T> *nodePtr2 = l2.getHead();

		while (nodePtr1 != nullptr && nodePtr2 != nullptr) {
			if (nodePtr1->getData() != nodePtr2->getData())
				return flag;
			nodePtr1 = nodePtr1->getPrev();
			nodePtr2 = nodePtr2->getPrev();
		}

		flag = true;

		return flag;
	}



	/*
	* Function that overloads the != operator for objects of List
	*/
	friend bool operator != (List<T> &l1, List<T> &l2) {
		return !(l1 == l2);
	}



	/*
	* Function that overloads the << operator for objects of List
	*/
	friend ostream& operator << (ostream &stream, List<T> &list) {
		Node<T> *nodePtr = list.getHead();
		while (nodePtr != nullptr) {
			stream << nodePtr->getData() << "\n";
			nodePtr = nodePtr->getPrev();
		}
		return stream;
	}



	/*
	* Class destructor
	* Destructor calls clear method to ensure all nodes are cleared from memory
	*/
	~List() {
		clear();
	}
};

#endif



