/********************************************************
Author: Jason Lai
Date: 7/15/2018
********************************************************/



#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/*
* Function prototypes (helper functions for main)
*/
template <typename T> void fillList(List<T>&, string);
template <typename T> void generateStack(Stack<T>&, string);
template <typename T> void generateQueue(Queue<T>&, string);



/*
* Main function
*/
int main()
{
	
	cout << "\n========================= DOUBLY LINKED LIST TEST WITH STRINGS =========================" << endl;
	Util *util = new Util();
	List<string> *stringlist = new List<string>();
	fillList(*stringlist, "Words.txt");


	cout << "\n------------------------ FILLING LIST ------------------------" << endl;
	cout << "List empty (1 for true, 0 for false): " << stringlist->isEmpty() << endl;
	cout << "Number of nodes: " << stringlist->getNumNodes() << endl;
	stringlist->printList();


	cout << "\n------------------------ SORTING LIST ------------------------" << endl;
	util->radixSort(*stringlist);
	stringlist->printList();


	cout << "\n------------------------ SEARCHING LIST ------------------------" << endl;
	cout << "Node memory address: " << util->binarySearch<string>(stringlist, "ever") << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch<string>(stringlist, "apple") << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch<string>(stringlist, "making") << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch<string>(stringlist, "'em") << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch<string>(stringlist, "youth") << endl;


	cout << "\n------------------------ CLEARING LIST ------------------------" << endl;
	stringlist->clear();
	cout << "Number of nodes: " << stringlist->getNumNodes() << endl;
	cout << "List empty (1 for true, 0 for false): " << stringlist->isEmpty() << endl;


	delete stringlist;
	




	cout << endl;
	




	cout << "\n========================= DOUBLY LINKED LIST TEST WITH NUMBERS =========================" << endl;
	List<int> *numslist = new List<int>();
	fillList(*numslist, "Numbers.txt");


	cout << "\n------------------------ FILLING LIST ------------------------" << endl;
	cout << "List empty (1 for true, 0 for false): " << numslist->isEmpty() << endl;
	cout << "Number of nodes: " << numslist->getNumNodes() << endl;
	numslist->printList();


	cout << "\n------------------------ SORTING LIST ------------------------" << endl;
	util->radixSort(*numslist);
	numslist->printList();


	cout << "\n------------------------ SEARCHING LIST ------------------------" << endl;
	cout << "Node memory address: " << util->binarySearch(numslist, 21895) << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch(numslist, 100) << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch(numslist, 17248) << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch(numslist, 12) << "\n" << endl;
	cout << "Node memory address: " << util->binarySearch(numslist, 32718) << endl;


	cout << "\n------------------------ CLEARING LIST ------------------------" << endl;
	numslist->clear();
	cout << "Number of nodes: " << numslist->getNumNodes() << endl;
	cout << "List empty (1 for true, 0 for false): " << numslist->isEmpty() << endl;


	delete util;
	delete numslist;


	return 0;
}



/*
* Function that fills the linked list
*/
template <typename T>
void fillList(List<T> &list, string fname) {
	ifstream in;

	in.open(fname);

	if (in) {
		T temp;

		while (in >> temp) {
			list.add(temp);
		}

	}

	else {
		cout << "File failed to open" << endl;
	}

	in.close();
}



/*
* Function that generates a stack
*/
template <typename T>
void generateStack(Stack<T> &stack, string fname) {
	ifstream in;

	in.open(fname);

	if (in) {
		T temp;

		while (in >> temp) {
			stack.push(temp);
		}

	}

	else {
		cout << "File failed to open" << endl;
	}

	in.close();
} 



/*
* Function that generates a queue
*/
template <typename T>
void generateQueue(Queue<T> &queue, string fname) {
	ifstream in;

	in.open(fname);

	if (in) {
		T temp;

		while (in >> temp) {
			queue.enqueue(temp);
		}

	}

	else {
		cout << "File failed to open" << endl;
	}

	in.close();
}





