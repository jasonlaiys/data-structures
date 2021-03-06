/********************************************************
Author: Jason Lai
Date: 7/23/2018
********************************************************/



#include "stdafx.h"
#include "Customer.h"
#include "DynamicArray.h"
#include "HashTable.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/*
* Function prototypes (helper functions for main)
*/
void fillArray(DynamicArray<Customer>&, string);
template <typename T> void fillList(List<T>&, string);



/*
* Main function
*/
int main()
{
	cout << "\n========================= READING DATA =========================" << endl;

	cout << "\n------------------------ FILLING DYNAMIC ARRAY ------------------------" << endl;
	DynamicArray<Customer> *arr = new DynamicArray<Customer>();
	fillArray(*arr, "Customer.csv");
	cout << "Data successfully read" << endl << endl;


	cout << "\n========================= HASHING WITH MODULO HASH =========================" << endl;

	cout << "\n------------------------ FILLING HASH TABLE ------------------------" << endl;
	HashTable<Customer> *table = new HashTable<Customer>(arr, 1);
	table->printData();

	cout << "\n------------------------ SEARCHING HASH TABLE ------------------------" << endl;
	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table->lookup("25674316-6058714") << endl << endl;

	cout << "Removing 25674316-6058714 ... " << endl << endl;
	table->remove("25674316-6058714");

	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table->lookup("25674316-6058714") << endl << endl;



	cout << "\n========================= HASHING WITH MID SQUARE HASH BASE 10 =========================" << endl;
	
	cout << "\n------------------------ FILLING HASH TABLE ------------------------" << endl;
	HashTable<Customer> *table2 = new HashTable<Customer>(arr, 2);
	table2->printData();

	cout << "\n------------------------ SEARCHING HASH TABLE ------------------------" << endl;
	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table2->lookup("25674316-6058714") << endl << endl;

	cout << "Removing 25674316-6058714 ... " << endl << endl;
	table2->remove("25674316-6058714");

	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table2->lookup("25674316-6058714") << endl << endl;



	cout << "\n========================= HASHING WITH MID SQUARE HASH BASE 2 =========================" << endl;

	cout << "\n------------------------ FILLING HASH TABLE ------------------------" << endl;

	HashTable<Customer> *table3 = new HashTable<Customer>(arr, 3);
	table3->printData();

	cout << "\n------------------------ SEARCHING HASH TABLE ------------------------" << endl;
	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table3->lookup("25674316-6058714") << endl << endl;

	cout << "Removing 25674316-6058714 ... " << endl << endl;
	table3->remove("25674316-6058714");

	cout << "Searching for 25674316-6058714 ... " << endl;
	cout << "Customer: " << table3->lookup("25674316-6058714") << endl << endl;

	delete table;
	delete table2;
	delete table3;

	return 0;
}



/*
* Function that fills a dynamic array
*/
void fillArray(DynamicArray<Customer> &array, string fname) {
	ifstream in;

	in.open(fname);

	if (in) {
		int index = 0;
		string data;

		while (in >> data) {
			Customer temp(data);
			
			array.add(temp);

			index++;
		}
	}


}



/*
* Function that fills a linked list
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



