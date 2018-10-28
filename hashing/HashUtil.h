/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef HashUtil_h
#define HashUtil_h



#include "stdafx.h"
#include "Customer.h"
#include "DynamicArray.h"
#include "Util.h"
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;



/********************************************************
Class declaration for HashUtil
Class acts as a utility container for all hashing related
	functions
Functions are defined inline
********************************************************/
class HashUtil {
private:
	Util util;

public:

	/*
	* Default constructor for HashUtil class
	*/
	HashUtil() {

	}



	/*
	* Function that calculates the hash by adding all the int values 
	*      of the key
	*/
	int basicHash(string key) {
		DynamicArray<string> arr;
		util.parseRegex(arr, key, "[0-9]*");
		int sum = 0;
		for (int i = 0; i < arr.getSize(); i++) {
			string str = arr[i];
			for (int j = 0; j < str.length(); j++) {
				char c = str[j];
				sum += int(c - '0');
			}
		}
		return sum;
	}



	/*
	* Function that calculates the hash by taking the remainder value of
	*      the key divided by the number of buckets
	*/
	int moduloHash(string key, int buckets) {
		DynamicArray<string> arr;
		util.parseRegex(arr, key, "[0-9]*");
		string temp;
		for (int i = 0; i < arr.getSize(); i++) {
			temp += arr[i];
		}
		stringstream ss(temp);
		unsigned long long hash;
		ss >> hash;
		hash %= buckets;
		return hash;
	}



	/*
	* Function that calculates the hash by squaring the key and
	*      extracting the middle ceil(log10(N)) digits of the
	*      squared key
	*/
	int midSquareHash(string key, int buckets) {
		DynamicArray<string> arr;
		util.parseRegex(arr, key, "[0-9]*");
		int r = ceil(log10(buckets));

		unsigned long long int sum = 0;
		for (int i = 0; i < arr.getSize(); i++) {
			sum += stoi(arr[i]);
		}
		sum *= sum;
		string temp(to_string(sum));

		if (temp.length() % 2 == 0) {
			int begin = ((temp.length() / 2) - 1) - (r / 2);
			temp = temp.substr(begin, r);
		}

		else {
			int begin = (temp.length() / 2) - (r / 2);
			temp = temp.substr(begin, r);
		}

		int hash = stoi(temp) % buckets;
		return hash;

	}



	/*
	* Function that calculates the hash by squaring the key and
	*      extracting the middle bits of the squared key
	*/
	int midSquareHashBase2(string key, int buckets) {
		DynamicArray<string> arr;
		util.parseRegex(arr, key, "[0-9]*");
		int r = ceil(log2(buckets));

		unsigned long long int sum = 0;
		for (int i = 0; i < arr.getSize(); i++) {
			sum += stoi(arr[i]);
		}
		sum *= sum;

		int hash = sum >> r;
		hash &= (0xFFFFFFFF >> r);
		hash %= buckets;

		return hash;
	}



	/*
	* Destructor for HashUtil
	*/
	~HashUtil() {

	}

};

#endif


