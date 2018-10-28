/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef Customer_h
#define Customer_h



#include "stdafx.h"
#include "Hashable.h"
#include "DynamicArray.h"
#include "Util.h"
#include "HashUtil.h"
#include <string>
#include <iostream>
using namespace std;



/********************************************************
Class declaration for Customer ADT
Class extends Hashable
Functions are defined inline
********************************************************/
class Customer : public Hashable {
private:
	string firstname;
	string lastname;
	string id;
	int hash;
	Util util;

public:

	/*
	* Default constructor for Customer
	* Constructor initializes:
	*      1. all string instance variables to ""
	*      2. all int instance variables to -1
	*      3. all other instance variables to NULL or nullptr or invalid
	*/
	Customer() {
		firstname = "";
		lastname = "";
		id = "";
		hash = -1;
	}



	/*
	* Overloaded constructor for Customer
	* Customer details are passed into the constructor as comma separated values
	* Util object handles parsing regex for appropriate customer fields
	*/
	Customer(string str) {
		DynamicArray<string> arr;
		util.parseRegex(arr, str, "[^,]*");
		if (arr.getSize() != 0) {
			lastname = arr[0];
			firstname = arr[1];
			id = arr[2];
		}
	}



	/*
	* Overloaded constructor for Customer
	* Customer details are passed into the constructor as strings
	*/
	Customer(string lastname, string firstname, string id) {
		this->firstname = firstname;
		this->lastname = lastname;
		this->id = id;
	}



	/*
	* Overloaded constructor for Customer
	* Customer details are passed into the constructor as another const ref Customer object
	*/
	Customer(const Customer &c) {
		firstname = c.firstname;
		lastname = c.lastname;
		id = c.id;
		hash = c.hash;
	}



	/*
	* Getter function that returns the customer's first name
	*/
	string getFirstName() {
		return firstname;
	}



	/*
	* Getter function that returns the customer's last name
	*/
	string getLastName() {
		return lastname;
	}



	/*
	* Getter function that returns the customer's ID
	*/
	string getID() {
		return id;
	}



	/*
	* FUNCTION TO BE USED WITH HASHTABLE
	* Getter function that returns the key for customer object
	*/
	string getKey() {
		return id;
	}



	/*
	* FUNCTION TO BE USED WITH HASHTABLE
	* Getter function that returns the hash value for customer object
	*/
	int getHash() {
		return hash;
	}



	/*
	* FUNCTION TO BE USED WITH HASHTABLE
	* Setter function that sets the hash value for customer object
	*/
	void setHash(int hash) {
		this->hash = hash;
	}



	/*
	* Function that prints customer data
	*/
	void printData() {
		cout << lastname << ", " << firstname << "\t" << id << endl;
	}



	/*
	* Function that overloads the = operator for objects of Customer
	*/
	Customer& operator = (const Customer &c) {
		firstname = c.firstname;
		lastname = c.lastname;
		id = c.id;
		hash = c.hash;
		return *this;
	}



	/*
	* Function that overloads the == operator for objects of Customer
	*/
	friend bool operator == (const Customer &c1, const Customer &c2) {
		int flag = c1.id.compare(c2.id);
		if (flag == 0)
			return true;

		return false;
	}



	/*
	* Function that overloads the != operator for objects of Customer
	*/
	friend bool operator != (const Customer &c1, const Customer &c2) {
		return !(c1 == c2);
	}



	/*
	* Function that overloads the << operator for objects of Customer
	*/
	friend ostream& operator << (ostream &stream, const Customer &c) {
		stream << c.lastname << ", " << c.firstname << "\t" << c.id;
		return stream;
	}



	/*
	* Destructor for Customer
	*/
	~Customer() {

	}

};

#endif







