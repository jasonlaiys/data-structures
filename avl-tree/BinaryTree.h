/********************************************************
Author: Jason Lai
Date: 8/4/2018
********************************************************/



#pragma once



#ifndef BinaryTree_h
#define BinaryTree_h



#include "stdafx.h"
#include "TreeNode.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
using namespace std;



/********************************************************
Class declaration for BinaryTree
Class is a generic/template
Functions are defined inline
********************************************************/
template <typename T>
class BinaryTree {
private:
	TreeNode<T> *root;
	int numNodes;

	/*
	* PRIVATE MEMBER FUNCTION
	* Function that recursively deletes tree nodes to clear the tree
	* Function is called by/helper to public member function clear()
	*/
	void clear(TreeNode<T> *node) {
		if (node != nullptr) {
			clear(node->getLeft());
			clear(node->getRight());
			delete node;
			numNodes--;
		}
	}

public:

	/*Default constructor for TreeNode class
	* Constructor initializes pointer to root as nullptr
	*      and initializes numNodes and levels to 0
	*/
	BinaryTree() {
		root = nullptr;
		numNodes = 0;
	}



	/*
	* Function that returns the number of nodes
	*/
	int getNumNodes() const {
		return numNodes;
	}



	/*
	* Function that returns a pointer to the tree's root
	*/
	TreeNode<T>* getRoot() {
		return root;
	}



	/*
	* Function that returns a boolean value of whether the tree is empty
	*/
	bool isEmpty() {
		return (numNodes == 0);
	}



	/*
	* Function that calculates the height difference between the node's
	* left and right subtree
	*/
	int getHeightDiff(TreeNode<T> *node) {
		int l_height = getHeight(node->getLeft());
		int r_height = getHeight(node->getRight());
		int hdiff = l_height - r_height;
		return hdiff;
	}



	/*
	* Function that calculates the height of a node subtree
	*/
	int getHeight(TreeNode<T> *node) {
		int h = 0;
		if (node != nullptr) {
			int l_height = getHeight(node->getLeft());
			int r_height = getHeight(node->getRight());
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}

		return h;
	}



	/*
	* Function that balances the tree
	*/
	TreeNode<T>* balance(TreeNode<T> *nodePtr) {
		int bal_factor = getHeightDiff(nodePtr);		

		if (bal_factor < -1) {
			if (getHeightDiff(nodePtr->getRight()) > 0) {
				nodePtr = rl_rotation(nodePtr);
			}

			else {
				nodePtr = rr_rotation(nodePtr);
			}
		}

		else if (bal_factor > 1) {
			if (getHeightDiff(nodePtr->getLeft()) > 0) {
				nodePtr = ll_rotation(nodePtr);
			}

			else {
				nodePtr = lr_rotation(nodePtr);
			}
		}

		else
			;

		return nodePtr;
	}



	/*
	* Function that segments and balances the left subtree
	*/
	void rebal_left(TreeNode<T> *par, TreeNode<T> *ptr) {
		bool flag = false;

		if (ptr != nullptr) {
			while (abs(getHeightDiff(ptr)) > 1) {
				ptr = balance(ptr);
				par->setLeft(ptr);
				flag = true;
			}
		}

		if (flag) {
			if (par->getLeft()->getLeft() != nullptr) {
				rebal_left(par->getLeft(), par->getLeft()->getLeft());
			}
			if (par->getRight()->getRight() != nullptr) {
				rebal_right(par, par->getRight());
			}
		}

	}



	/*
	* Function that segments and balances the right subtree
	*/
	void rebal_right(TreeNode<T> *par, TreeNode<T> *ptr) {
		bool flag = false;

		if (ptr != nullptr) {
			while (abs(getHeightDiff(ptr)) > 1) {
				ptr = balance(ptr);
				par->setRight(ptr);
				flag = true;
			}
		}

		if (flag) {
			if (par->getRight()->getRight() != nullptr) {
				rebal_right(par->getRight(), par->getRight()->getRight());
			}
			if (par->getLeft()->getLeft() != nullptr) {
				rebal_left(par, par->getLeft());
			}
		}

	}



	/*
	* Function that rebalances the entire tree
	*/
	void rebalance() {
		while (abs(getHeightDiff(root)) > 1) {
			root = balance(root);
		}

		rebal_left(root, root->getLeft());
		recalc_height(root);
	}



	/*
	* Function that recalculates the height of the given node
	* and all of its other child nodes
	*/
	void recalc_height(TreeNode<T>* node) {
		TreeNode<T>* ptr;
		Stack<TreeNode<T>*> *stack = new Stack<TreeNode<T>*>();
		int height = getHeight(node);

		stack->push(node);

		while (!stack->isEmpty()) {
			ptr = stack->pop();
			ptr->setLevel(height - getHeight(ptr));

			if (ptr->getRight() != nullptr) {
				stack->push(ptr->getRight());
			}

			if (ptr->getLeft() != nullptr) {
				stack->push(ptr->getLeft());
			}
		}
	}



	/*
	* Function that performs left-left rotation on a degenerate subtree
	*/
	TreeNode<T>* ll_rotation(TreeNode<T> *par) {
		TreeNode<T> *node = par->getLeft();
		par->setLeft(node->getRight());
		node->setRight(par);
		return node;
	}



	/*
	* Function that performs left-right rotation on a degenerate subtree
	*/
	TreeNode<T>* lr_rotation(TreeNode<T> *par) {
		TreeNode<T> *node = par->getLeft();
		par->setLeft(rr_rotation(node));
		node = ll_rotation(par);
		return node;
	}



	/*
	* Function that performs right-right rotation on a degenerate subtree
	*/
	TreeNode<T>* rr_rotation(TreeNode<T> *par) {
		TreeNode<T> *node = par->getRight();
		par->setRight(node->getLeft());
		node->setLeft(par);
		return node;
	}



	/*
	* Function that performs right-left rotation on a degenerate subtree
	*/
	TreeNode<T>* rl_rotation(TreeNode<T> *par) {
		TreeNode<T> *node = par->getRight();
		par->setRight(ll_rotation(node));
		node = rr_rotation(par);
		return node;
	}



	/*
	* Function that inserts a new entry into the tree
	*/
	bool insert(T newEntry) {
		TreeNode<T> *newNode = new TreeNode<T>(newEntry);

		if (root == nullptr) {
			newNode->setLevel(0);
			root = newNode;
			numNodes++;
			return true;
		}

		else {
			bool inserting = true;
			int level = 0;
			TreeNode<T> *nodePtr = root;

			while (inserting) {
				level++;
				if (newEntry < nodePtr->getData()) {
					if (nodePtr->getLeft() == nullptr) {
						newNode->setLevel(level);
						nodePtr->setLeft(newNode);
						inserting = false;
					}

					else {
						nodePtr = nodePtr->getLeft();
					}
				}

				else {
					if (nodePtr->getRight() == nullptr) {
						newNode->setLevel(level);
						nodePtr->setRight(newNode);
						inserting = false;
					}

					else {
						nodePtr = nodePtr->getRight();
					}
				}
			}

			numNodes++;
			return true;
		}

		return false;

	}



	/*
	* Function that searches for a specific entry in the tree
	* Returns true if found
	* Returns false if not found
	*/
	bool search(T entry) {
		TreeNode<T> *nodePtr = root;

		while (nodePtr->getData() != entry && nodePtr != nullptr) {
			if (entry < nodePtr->getData())
				nodePtr = nodePtr->getLeft();
			else
				nodePtr = nodePtr->getRight();
		}

		return !(nodePtr == nullptr);
	}



	/*
	* Function that removes an entry from the tree
	*/
	void remove(T entry) {
		TreeNode<T> *parent = nullptr;
		TreeNode<T> *nodePtr = root;

		while (nodePtr != nullptr) {
			if (nodePtr->getData() == entry) {
				if (nodePtr->getLeft() == nullptr && nodePtr->getRight() == nullptr) {
					if (parent == nullptr) {
						root->setData(NULL);
						root = nullptr;
					}
					else if (parent->getLeft() == nodePtr) {
						parent->setLeft(nullptr);
					}
					else {
						parent->setRight(nullptr);
					}
				}

				else if (nodePtr->getLeft() != nullptr && nodePtr->getRight() == nullptr) {
					if (parent == nullptr) {
						root = nodePtr->getLeft();
					}
					else if (parent->getLeft() == nodePtr) {
						parent->setLeft(nodePtr->getLeft());
					}
					else {
						parent->setRight(nodePtr->getLeft());
					}
				}

				else if (nodePtr->getLeft() == nullptr && nodePtr->getRight() != nullptr) {
					if (parent == nullptr) {
						root = nodePtr->getRight();
					}
					else if (parent->getLeft() == nodePtr) {
						parent->setLeft(nodePtr->getRight());
					}
					else {
						parent->setRight(nodePtr->getRight());
					}
				}

				else {
					TreeNode<T> *next = nodePtr->getRight();
					TreeNode<T> *parent_next = nodePtr;
					while (next->getLeft() != nullptr) {
						parent_next = next;
						next = next->getLeft();
					}
					nodePtr->setData(next->getData());
					parent_next->setLeft(nullptr);
					delete next;
				}

				numNodes--;
				return;
			}

			else if (nodePtr->getData() < entry) {
				parent = nodePtr;
				nodePtr = nodePtr->getRight();
			}

			else {
				parent = nodePtr;
				nodePtr = nodePtr->getLeft();
			}
		}
	}



	/*
	* Function that clears the tree
	*/
	void clear() {
		clear(root);
	}



	/*
	* Function that prints the tree in inorder traversal
	*/
	void printInorder() {
		TreeNode<T> *nodePtr = root;
		Stack<TreeNode<T>> *stack = new Stack<TreeNode<T>>();
		bool done = false;

		while (!done) {
			if (nodePtr != nullptr) {
				stack->push(*nodePtr);
				nodePtr = nodePtr->getLeft();
			}

			else {
				if (!stack->isEmpty()) {
					TreeNode<T> tnode = stack->pop();
					printLevel(tnode.getLevel());
					cout << tnode.getData() << endl;
					nodePtr = tnode.getRight();
				}

				else {
					done = true;
				}
			}
		}
	}



	/*
	* Function that prints the tree in preorder traversal
	*/
	void printPreorder() {
		TreeNode<T> nodePtr;
		Stack<TreeNode<T>> *stack = new Stack<TreeNode<T>>();

		stack->push(*root);

		while (!stack->isEmpty()) {
			nodePtr = stack->pop();
			printLevel(nodePtr.getLevel());
			cout << nodePtr.getData() << endl;

			if (nodePtr.getRight() != nullptr) {
				stack->push(*(nodePtr.getRight()));
			}

			if (nodePtr.getLeft() != nullptr) {
				stack->push(*(nodePtr.getLeft()));
			}

		}
	}



	/*
	* Function that prints the tree in postorder traversal
	*/
	void printPostorder() {
		TreeNode<T> nodePtr;
		Stack<TreeNode<T>> *stack = new Stack<TreeNode<T>>();
		Stack<TreeNode<T>> *out = new Stack<TreeNode<T>>();

		stack->push(*root);

		while (!stack->isEmpty()) {
			nodePtr = stack->pop();
			out->push(nodePtr);

			if (nodePtr.getLeft() != nullptr) {
				stack->push(*(nodePtr.getLeft()));
			}

			if (nodePtr.getRight() != nullptr) {
				stack->push(*(nodePtr.getRight()));
			}
		} 

		while (!out->isEmpty()) {
			nodePtr = out->pop();
			printLevel(nodePtr.getLevel());
			cout << nodePtr.getData() << endl;
		}

	}



	/*
	* Function that prints an indicator for the node's level
	*/
	void printLevel(int level) {
		for (int i = 0; i < level; i++) {
			cout << left << "-----| " << setw(5);
		}
	}



	/*
	* Destructor for BinaryTree
	*/
	~BinaryTree() {
		clear();
	}

	
};

#endif;


