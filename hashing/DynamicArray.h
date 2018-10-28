/********************************************************
Author: Jason Lai
Date: 8/10/2018
********************************************************/



#pragma once



#ifndef DynamicArray_h
#define DynamicArray_h



#include "stdafx.h"
#include "ArrayInterface.h"
#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
using namespace std;



enum { INVALID = -1, DEFAULT_CAPACITY = 10 };



/********************************************************
Class declaration for DynamicArray
Class is a generic/template
Class extends ArrayInterface
Functions are defined inline
********************************************************/
template <typename T>
class DynamicArray : public ArrayInterface<T> {
private:
	T *items;
	int itemCount;
	int maxItems;

public:

	/*
	* Constructor for DynamicArray class
	*/
	DynamicArray(int capacity = DEFAULT_CAPACITY) : itemCount(0), maxItems(capacity) {
		items = new T[capacity];
	}



	/*
	* Function that returns the current size of the dynamic array
	*/
	int getSize() {
		return itemCount;
	}



	/*
	* Function that returns a boolean value of whether the dynamic array is empty or not
	*/
	bool isEmpty() {
		return itemCount == 0;
	}



	/*
	* Function that appends a new entry into the dynamic array
	*/
	bool add(const T &newEntry) {
		if (itemCount < maxItems) {
			items[itemCount] = newEntry;
			itemCount++;
			return true;
		}

		else {
			resize(maxItems * 2);			

			items[itemCount] = newEntry;
			itemCount++;

			return true;
		}

		return false;
	}



	/*
	* Function that adds a new entry into a specific index of the dynamic array
	*/
	bool add(int index, const T &newEntry) {
		if (index >= maxItems) {
			resize(maxItems * 2);
		}

		items[index] = newEntry;
		itemCount++;

		return true;
	}



	/*
	* Function that removes an entry from the dynamic array
	*/
	bool remove(T entry) {
		int index = getIndexOf(entry, 0);

		if (!isEmpty() && index > INVALID) {
		
			for (int i = index; i < itemCount; i++) {
				if (index == itemCount - 1) {
					;
				}

				else {
					items[index] = items[index + 1];
				}
			}

			itemCount--;

			return true;

		}

		return false;
	}



	/*
	* Function that clears the dynamic array
	*/
	void clear() {
		itemCount = 0;

		if (items) {
			items = nullptr;
			items = new T[DEFAULT_CAPACITY];
		}
	}



	/*
	* Function that resizes the dynamic array
	*/
	void resize(int size) {
		maxItems = size;
		T *temp = new T[maxItems];

		for (int i = 0; i < itemCount; i++) {
			temp[i] = items[i];
		}

		delete[] items;
		items = temp;

	}



	/*
	* Function that returns the data as an array
	*/
	T* getItems() {
		return items;
	}



	/*
	* Function that returns the max size of the dynamic array
	*/
	int getMaxSize() {
		return maxItems;
	}



	/*
	* Function that returns the index of an entry in the dynamic array
	* Returns -1 if entry is invalid
	*/
	int getIndexOf(T entry, int index) {
		int result = -1;

		if (index < itemCount) {
			if (items[index] == entry) {
				result = index;
			}

			else {
				result = getIndexOf(entry, index + 1);
			}
		}

		return result;
	}



	/*
	* Function that returns an item at a specific index
	*/
	T& get(int index) {
		return items[index];
	}



	/*
	* Function that overloads the [] operator for objects of DynamicArray
	*/
	T& operator [] (int index) {
		return get(index);
	}



	/*
	* Function that overloads the = operator for objects of DynamicArray
	*/
	DynamicArray<T>& operator = (const DynamicArray<T> &arr) {
		items = arr.items;
		itemCount = arr.itemCount;
		maxItems = arr.maxItems;
		return *this;
	}



	/*
	* Function that overloads the == operator for objects of DynamicArray
	*/
	friend bool operator == (const DynamicArray<T> &arr1, const DynamicArray<T> &arr2) {
		bool flag = false;
		if (arr1.items == arr2.items && arr1.itemCount == arr2.itemCount && arr1.maxItems == arr2.maxItems) {
			flag = true;
		}
		return flag;
	}



	/*
	* Function that overloads the != operator for objects of DynamicArray
	*/
	friend bool operator != (const DynamicArray<T> &arr1, const DynamicArray<T> &arr2) {
		return !(arr1 == arr2);
	}



	/*
	* Function that overloads the << operator for objects of DynamicArray
	*/
	friend ostream& operator << (ostream &stream, DynamicArray<T> &darray) {
		//stream << "The array contains " << static_cast<int>(darray.getSize()) << " items:" << endl;
		for (int i = 0; i < darray.getSize(); i++) {
			stream << left << setw(6) << darray[i];
		}
		stream << endl;
		return stream;
	}



	/*
	* Destructor for DynamicArray class
	*/
	~DynamicArray() {
		if (items)
			delete[] items;
	}

};

#endif




