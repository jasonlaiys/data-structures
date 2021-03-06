/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/*
* Function prototypes (helper functions for main)
*/
template <typename T> void fillTree(BinaryTree<T>&, string);



/*
* Main function
*/
int main()
{
	cout << "\n========================= BINARY TREE TEST WITH NUMBERS =========================" << endl;
	BinaryTree<int> *tree2 = new BinaryTree<int>();

	cout << "\n------------------------ FILLING BINARY TREE ------------------------" << endl;
	fillTree(*tree2, "Numbers.txt");
	cout << "Tree successfully filled" << endl;
	cout << "Number of nodes: " << tree2->getNumNodes() << endl;

	cout << "\n------------------------ PRINTING IN INORDER TRAVERSAL ------------------------" << endl;
	tree2->printInorder();

	cout << "\n------------------------ BALANCING TREE ------------------------" << endl;
	tree2->rebalance();

	cout << "\n------------------------ PRINTING IN INORDER TRAVERSAL ------------------------" << endl;
	tree2->printInorder();

	cout << "\n------------------------ PRINTING IN PREORDER TRAVERSAL ------------------------" << endl;
	tree2->printPreorder();

	cout << "\n------------------------ DELETING TREE ------------------------" << endl;
	delete tree2;

	return 0;
}



/*
* Function that fills a binary tree
*/
template <typename T> 
void fillTree(BinaryTree<T> &tree, string fname) {
	ifstream in;

	in.open(fname);

	if (in) {
		T temp;

		while (in >> temp) {
			tree.insert(temp);
		}

	}

	else {
		cout << "File failed to open" << endl;
	}

	in.close();
}







