/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef Hashable_h
#define Hashable_h



#include <string>
using namespace std;



/********************************************************
Abstract class declaration for Hashable
All functions are pure virtual functions to be implemented
	in child/derived class
Used as a template enabler for HashTable generic
********************************************************/
class Hashable {
public:
	virtual string getKey() = 0;
	virtual int getHash() = 0;
	virtual void setHash(int hash) = 0;
};

#endif

