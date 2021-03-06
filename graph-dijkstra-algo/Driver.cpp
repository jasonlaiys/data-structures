/********************************************************
Author: Jason Lai
Date: 8/10/2018
********************************************************/



#include "stdafx.h"
#include "DynamicArray.h"
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;



/*
* Function prototypes (helper functions for main)
*/
void fillKey(DynamicArray<string> *key);
void fillMatrix(DynamicArray<DynamicArray<int>> &matrix);



/*
* Main function
*/
int main()
{
	DynamicArray<string> *key = new DynamicArray<string>();
	DynamicArray<DynamicArray<int>> *matrix = new DynamicArray<DynamicArray<int>>();

	fillKey(key);
	fillMatrix(*matrix);

	Graph<string> *graph = new Graph<string>(matrix, key);

	cout << "\n------------------------ ADJACENCY MATRIX ------------------------" << endl;

	cout << *key << endl;
	cout << *matrix << endl;

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM SFO ------------------------" << endl;
	graph->calcPath("SFO");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM LAX ------------------------" << endl;
	graph->calcPath("LAX");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM DFW ------------------------" << endl;
	graph->calcPath("DFW");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM ORD ------------------------" << endl;
	graph->calcPath("ORD");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM JFK ------------------------" << endl;
	graph->calcPath("JFK");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM BOS ------------------------" << endl;
	graph->calcPath("BOS");
	graph->printPath();
	graph->clear();

	cout << "\n------------------------ CALCULATING SHORTEST PATH FROM MIA ------------------------" << endl;
	graph->calcPath("MIA");
	graph->printPath();
	graph->clear();

	//graph->printMatrix();

	//graph->calcPath("LAX");
	//graph->printPath();

	delete graph;

	return 0;
}



void fillKey(DynamicArray<string> *key) {
	key->add("SFO");
	key->add("LAX");
	key->add("DFW");
	key->add("ORD");
	key->add("JFK");
	key->add("BOS");
	key->add("MIA");
}



void fillMatrix(DynamicArray<DynamicArray<int>> &matrix) {
	DynamicArray<int> temp;

	//Filling values for SFO
	temp.add(0);
	temp.add(337);
	temp.add(1464);
	temp.add(1846);
	temp.add(0);
	temp.add(2704);
	temp.add(0);
	matrix.add(0, temp);

	//Filling values for LAX
	temp.clear();
	temp.add(337);
	temp.add(0);
	temp.add(1235);
	temp.add(0);
	temp.add(0);
	temp.add(0);
	temp.add(2342);
	matrix.add(1, temp);
	
	//Filling values for DFW
	temp.clear();
	temp.add(1464);
	temp.add(1235);
	temp.add(0);
	temp.add(802);
	temp.add(0);
	temp.add(0);
	temp.add(1121);
	matrix.add(2, temp);

	//Filling values for ORD
	temp.clear();
	temp.add(1846);
	temp.add(0);
	temp.add(802);
	temp.add(0);
	temp.add(740);
	temp.add(867);
	temp.add(0);
	matrix.add(3, temp);

	//Filling values for JFK
	temp.clear();
	temp.add(0);
	temp.add(0);
	temp.add(0);
	temp.add(740);
	temp.add(0);
	temp.add(187);
	temp.add(1090);
	matrix.add(4, temp);

	//Filling values for BOS
	temp.clear();
	temp.add(2704);
	temp.add(0);
	temp.add(0);
	temp.add(867);
	temp.add(187);
	temp.add(0);
	temp.add(1258);
	matrix.add(5, temp);

	//Filling values for MIA
	temp.clear();
	temp.add(0);
	temp.add(2342);
	temp.add(1121);
	temp.add(0);
	temp.add(1090);
	temp.add(1258);
	temp.add(0);
	matrix.add(6, temp);

	temp.clear();

}





