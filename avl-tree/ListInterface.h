/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#ifndef ListInterface_h
#define ListInterface_h



/********************************************************
Abstract class declaration for ListInterface
All functions are pure virtual functions to be implemented
     in child/derived class
Class is a generic/template
Abstract class is implemented in List
********************************************************/
template <typename T>
class ListInterface {
public:
	ListInterface() { }
	virtual bool isEmpty() = 0;
	virtual bool add(T newEntry) = 0;
	virtual bool remove(T entry) = 0;
	virtual void clear() = 0;
	virtual bool search(T entry) = 0;
};

#endif
