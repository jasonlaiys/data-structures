/********************************************************
Author: Jason Lai
Date: 8/10/2018
********************************************************/



#pragma once



#ifndef Graph_h
#define Graph_h



#include "stdafx.h"
#include "DynamicArray.h"
#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;



template <typename T>
class Graph {
private:
	DynamicArray<DynamicArray<int>> *matrix;
	DynamicArray<T> path;
	DynamicArray<T> *key;
	DynamicArray<bool> visited;
	DynamicArray<int> distance;
	DynamicArray<int> total_dist;



	/*
	* PRIVATE MEMBER FUNCTION
	* This function gets the shortest distance from one point to another
	*/
	int getMinDist() {

		int min = INT_MAX;
		int min_index = -1;

		for (int i = 0; i < matrix->getSize(); i++) {
			if (visited[i] == false && distance[i] <= min) {
				min = distance[i];
				min_index = i;
			}

		}

		return min_index;
	}



	/*
	* PRIVATE MEMBER FUNCTION
	* This function sets the shortest path
	*/
	void setPath() {
		int min = INT_MAX;
		int min_index = 0;

		for (int i = 0; i < 7; i++) { 
			for (int j = 0; j < 7; j++) {
				if (distance[j] < min) {
					min = distance[j];
					min_index = j;
				}
			}

			path.add(key->get(min_index));
			total_dist.add(distance[min_index]);
			min = INT_MAX;
			distance[min_index] = INT_MAX;
		}
	}

public:

	/*
	* Default constructor for Graph class
	*/
	Graph() {

	}



	/*
	* Overloaded constructor for Graph class
	* Constructor takes matrix and key as args for calculation
	*/
	Graph(DynamicArray<DynamicArray<int>> *m, DynamicArray<T> *k) {
		matrix = m;
		key = k;
	}



	/*
	* Function that returns the shortest path
	*/
	DynamicArray<T>& getPath() {
		return path;
	}



	/*
	* Function that returns the adjacency matrix as a pointer
	*/
	DynamicArray<DynamicArray<int>>* getMatrix() {
		return matrix;
	}



	/*
	* Function that sets the adjacency matrix pointer
	*/
	void setMatrix(DynamicArray<DynamicArray<int>> *matrix) {
		this->matrix = matrix;
	}



	/*
	* Function that returns the key as a pointer
	*/
	DynamicArray<T>* getKey() {
		return key;
	}



	/*
	* Function that sets the key pointer
	*/
	void setKey(DynamicArray<T> *key) {
		this->key = key;
	}



	/*
	* Function that calculates the shortest path given a source
	*/
	void calcPath(T src) {
		for (int i = 0; i < matrix->getSize(); i++) {
			distance.add(INT_MAX);
			visited.add(false);
		}

		int srcIndex = key->getIndexOf(src, 0);

		distance.add(srcIndex, 0);

		for (int i = 0; i < matrix->getSize() - 1; i++) {
			int shortest_dist = getMinDist();
			visited.add(shortest_dist, true);

			for (int j = 0; j < matrix->getSize(); j++) {
				if (!visited[j] && matrix->get(shortest_dist).get(j) != 0 
					&& distance[shortest_dist] != INT_MAX 
					&& distance[shortest_dist] + matrix->get(shortest_dist).get(j) < distance[j]) {

					distance[j] = distance[shortest_dist] + matrix->get(shortest_dist).get(j);
				}
			}

		}

		setPath();

	}



	/*
	* Function that clears the shortest path array
	*/
	void clear() {
		path.clear();
		visited.clear();
		distance.clear();
		total_dist.clear();
	}



	/*
	* Function that prints the shortest path
	*/
	void printPath() {
		cout << "The shortest path from " << path[0] << " to all other destinations: " << endl;
		cout << path << endl;

		cout << "Cost from " << path[0] << " to all other destinations: " << endl;
		for (int i = 1; i < path.getSize(); i++) {
			cout << path[0] << " to " << path[i] << ": " << total_dist[i] << endl;
		}
	}



	/*
	* Function that prints the matrix
	*/
	void printMatrix() {
		cout << matrix << endl;
	}



	/*
	* Destructor for Graph class
	*/
	~Graph() {
		delete matrix;
		delete key;
	}

};

#endif


