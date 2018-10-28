/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef ArrayInterface_h
#define ArrayInterface_h



/********************************************************
Abstract class declaration for ArrayInterface
All functions are pure virtual functions to be implemented
	in child/derived class
Class is a generic/template
Abstract class is implemented in DynamicArray
********************************************************/
template <typename T>
class ArrayInterface {
public:
	ArrayInterface() { }
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual bool add(const T &newEntry) = 0;
	virtual bool remove(T entry) = 0;
	virtual void clear() = 0;
	virtual void resize(int size) = 0;
};

#endif


