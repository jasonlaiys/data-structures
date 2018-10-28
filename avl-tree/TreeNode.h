/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#pragma once



#ifndef TreeNode_h
#define TreeNode_h



#include "stdafx.h"



/********************************************************
Class declaration for TreeNode
Class is a generic/template
Functions are defined inline
********************************************************/
template <typename T>
class TreeNode {
private:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
	int level; //to store the node level

public:

	/*
	* Default constructor for TreeNode class
	* Constructor initializes pointer to previous node as nullptr
	*      and initializes data variable to NULL
	*/
	TreeNode() {
		left = nullptr;
		right = nullptr;
		level = -1;
	}



	/*
	* Overloaded constructor for Node class
	* Constructor initializes pointer to left and right nodes as nullptr
	*      and initializes data variable to value passed into function
	*      parameter
	*/
	TreeNode(T data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}



	/*
	* Funtion that returns the node's left child node
	*/
	TreeNode<T>* getLeft() {
		return left;
	}



	/*
	* Funtion that sets the node's left child node
	*/
	void setLeft(TreeNode<T> *left) {
		this->left = left;
	}



	/*
	* Funtion that returns the node's right child node
	*/
	TreeNode<T>* getRight() {
		return right;
	}



	/*
	* Funtion that sets the node's right child node
	*/
	void setRight(TreeNode<T> *right) {
		this->right = right;
	}



	/*
	* Funtion that returns the node's data
	*/
	T& getData() {
		return data;
	}



	/*
	* Funtion that sets the node's data
	*/
	void setData(T data) {
		this->data = data;
	}



	/*
	* Funtion that returns the node's level
	*/
	int getLevel() const {
		return level;
	}



	/*
	* Funtion that sets the node's level
	*/
	void setLevel(int level) {
		this->level = level;
	}



	/*
	* Funtion that overloads the == operator for TreeNode
	*/
	friend bool operator == (TreeNode<T> &t1, TreeNode<T> &t2) {
		bool flag = false;

		if ((t1.getData() == t2.getData()) && (t1.getLeft() == t2.getLeft()) && (t1.getRight() == t2.getRight())) {
			flag = true;
		}

		return flag;
	}



	/*
	* Funtion that overloads the != operator for TreeNode
	*/
	friend bool operator != (TreeNode<T> &t1, TreeNode<T> &t2) {
		return !(t1 == t2);
	}


};

#endif


