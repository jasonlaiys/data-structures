/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef HashTable_h
#define HashTable_h



#include "stdafx.h"
#include "Hashable.h"
#include "HashUtil.h"
#include "DynamicArray.h"
#include "List.h"
#include <iostream>
using namespace std;



/********************************************************
Class declaration for HashTable
Class is a generic/template
Template is only enabled if T is a derived class of Hashable
Functions are defined inline
********************************************************/
template <typename T, typename enable_if <is_base_of <Hashable, T>::value>::type* = nullptr>
class HashTable {
private:
	DynamicArray<List<T>> *table;
	int hashFunction;
	int collisions;
	int items;
	double collisionRate;
	HashUtil hutil;

public:

	/*
	* Default constructor for HashTable
	* Constructor initializes:
	*      1. all numeric instance variables to 0.0
	*      2. hashFunction variable to the most efficient hash function
	*      3. a DynamicArray of LinkedLists
	*/
	HashTable() {
		table = new DynamicArray<List<T>>();
		hashFunction = 3;
		collisions = 0;
		items = 0;
		collisionRate = 0.0;
	}



	/*
	* Overloaded constructor for Customer
	* Constructor takes a DynamicArray of objects as data to be hashed and
	*     programmer specified hash function
	*/
	HashTable(DynamicArray<T> *data, int hashFunction) : collisions(0), items(0), collisionRate(0.0) {
		table = new DynamicArray<List<T>>(data->getSize() * 1.25);
		this->hashFunction = hashFunction;

		for (int i = 0; i < data->getSize(); i++) {
			put(data->get(i));
		}

		collisionRate = (static_cast<double> (collisions)) / items;
	}



	/*
	* Function that sets the desired hash function provided no data is stored in the hash table
	*/
	void setHashFunction(int function) {
		if (items == 0)
			this->hashFunction = function;
	}



	/*
	* Function that inserts new data into the hash table
	*/
	void put(T &entry) {
		entry.setHash(calculateHash(entry.getKey()));
		int hash = entry.getHash();

		if (hash > -1) {
			if (table->get(hash).getHead() != nullptr) {
				collisions++;
				table->get(hash).add(entry);
			}
			else {
				List<T> *list = new List<T>();
				list->add(entry);
				table->add(hash, *list);
			}
			
			items++;
		}
	}



	/*
	* Function that searches data from the hash table
	*/
	T& lookup(string key) {
		int hash = calculateHash(key);

		Node<T> *nodePtr = table->get(hash).getHead();

		while (nodePtr != nullptr && nodePtr->getData().getKey() != key) {
			nodePtr = nodePtr->getPrev();
		}

		if (nodePtr != nullptr)
			return nodePtr->getData();

		else
			return *(new T());

	}



	/*
	* Function that removes data from the hash table
	*/
	void remove(string key) {
		T data = lookup(key);
		int hash = data.getHash();

		if (data.getKey() == key && hash > -1) {
			table->get(hash).remove(data);
			items--;
		}
	}



	/*
	* Function that clears the hash table
	*/
	void clear() {
		if (table) {
			delete table;
			table = nullptr;
			items = 0;
			collisions = 0;
			collisionRate = 0.0;
		}
	}



	/*
	* Function that calculates the hash value/index of a data based on
	*      the object's key and the hash function
	*/
	int calculateHash(string key) {
		int hash;

		switch (hashFunction) {
		case 0:
			hash = hutil.basicHash(key);
			break;
		case 1:
			hash = hutil.moduloHash(key, table->getMaxSize());
			break;
		case 2:
			hash = hutil.midSquareHash(key, table->getMaxSize());
			break;
		case 3:
			hash = hutil.midSquareHashBase2(key, table->getMaxSize());
			break;
		}

		return hash;
	}



	/*
	* Function that prints the entire hash table
	*/
	void printData() {
		cout << "Items: " << items << endl;
		cout << "Collisions: " << collisions << endl;
		cout << "Collision Rate: " << (collisionRate * 100) << "%" << endl << endl;
		for (int i = 0; i < table->getMaxSize(); i++) {
			if (table->get(i).getHead() != nullptr) {
				cout << "Index: " << i << endl;
				cout << table->get(i) << endl;
			}
		}
	}



	/*
	* Destructor for HashTable
	*/
	~HashTable() {
		clear();
	}

};

#endif;

