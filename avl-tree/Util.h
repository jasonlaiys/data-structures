/********************************************************
Author: Jason Lai
Date: 7/30/2018
********************************************************/



#pragma once



#ifndef Util_h
#define Util_h



#include "stdafx.h"
#include "List.h"
#include "DynamicArray.h"
#include <regex>
#include <string>
using namespace std;



/********************************************************
Class declaration for Util
Class is not a generic/template
Functions are generics/templates to be able to sort and
	search linked lists of different data types with the
	same util object
Functions are defined inline
********************************************************/
class Util {
private:

	/*
	* PRIVATE MEMBER FUNCTION
	* This function is a helper function to the binary search algorithm
	* This function returns a pointer to a node that is x number of nodes
	*	from the linked list head
	*/
	template <typename T>
	Node<T> *getNodePos(const List<T> *list, int pos) {

		Node<T> *nodePtr = list->getHead();
		int count = 1;

		while (nodePtr->getPrev() != nullptr && count != pos) {
			nodePtr = nodePtr->getPrev();
			count++;
		}

		return nodePtr;

	}



	/*
	* PRIVATE MEMBER FUNCTION
	* This function is a helper function to the radix sort algorithm
	* This function returns a length of the largest integer in the linked list
	*/
	int radixGetMaxLength(const List<int> *list) {
		int maxDigits = 0;
		Node<int> *nodePtr = list->getHead();

		while (nodePtr != nullptr) {
			int digitCount = radixGetLength(nodePtr->getData());
			if (digitCount > maxDigits)
				maxDigits = digitCount;
			nodePtr = nodePtr->getPrev();
		}

		return maxDigits;

	}



	/*
	* PRIVATE MEMBER FUNCTION
	* This function is a helper function to the radix sort algorithm
	* This function returns a length of the largest string in the linked list
	*/
	int radixGetMaxLength(const List<string> *list) {
		int maxLength = 0;
		Node<string> *nodePtr = list->getHead();

		while (nodePtr != nullptr) {
			int charCount = nodePtr->getData().length();
			if (charCount > maxLength)
				maxLength = charCount;
			nodePtr = nodePtr->getPrev();
		}

		return maxLength;

	}



	/*
	* PRIVATE MEMBER FUNCTION
	* This function is a helper function to the radix sort algorithm
	* This function returns the length of an integer
	*/
	int radixGetLength(int value) {
		if (value == 0) {
			return 1;
		}

		int digits = 0;
		while (value != 0) {
			digits++;
			value /= 10;
		}

		return digits;
	}


public:

	/*
	* Default constructor for Util class
	*/
	Util() {
		
	}



	/*
	* Function that parses a regular expression
	*/
	void parseRegex(DynamicArray<string> &data, string text, string split) {
		sregex_token_iterator end;
		regex pattern(split);
		for (sregex_token_iterator pos(text.begin(), text.end(), pattern); pos != end; ++pos) {
			if (pos->length() > 0) {
				if ((static_cast<string>(*pos))[0] != '-')
					data.add(*pos);
			}
		}
	}



	/*
	* Function that sorts a linked list by the selection sort algorithm
	*/
	template <typename T>
	void selectionSort(List<T> &list) {

		Node<T> *nodePtr; //pointer to traverse the linked list
		Node<T> *anchor = list.getHead(); //pointer to sorted part of linked list
		Node<T> *smallest; //pointer to node with smallest value

		while (anchor != nullptr) {
			smallest = anchor;
			nodePtr = anchor;

			while (nodePtr != nullptr) {
				if (smallest->getData() > nodePtr->getData()) {
					smallest = nodePtr;
				}

				nodePtr = nodePtr->getPrev();
			}

			T temp = anchor->getData();
			anchor->setData(smallest->getData());
			smallest->setData(temp);

			anchor = anchor->getPrev();

		}


	}



	/*
	* Function that sorts a linked list of type int by the radix sort algorithm
	*/
	void radixSort(List<int> &list) {

		Node<int> *headRef = list.getHead();
		Node<int> *nodePtr;
		List<int> bucket[10];
		int maxDigits = radixGetMaxLength(&list);
		int pow10 = 1;

		for (int i = 0; i < maxDigits; i++) {
			nodePtr = headRef;

			while (nodePtr != nullptr) {
				int k = abs(nodePtr->getData() / pow10) % 10; //index of bucket array by radix
				bucket[k].add(nodePtr->getData());
				nodePtr = nodePtr->getPrev();
			}

			nodePtr = headRef;

			for (int j = 0; j < 10; j++) {
				Node<int> *bucketNodePtr = bucket[j].getHead();

				if (bucketNodePtr != nullptr) {
					while (bucketNodePtr->getPrev() != nullptr) {
						bucketNodePtr = bucketNodePtr->getPrev();
					}

					while (bucketNodePtr != nullptr) {
						nodePtr->setData(bucketNodePtr->getData());
						bucketNodePtr = bucketNodePtr->getNext();
						nodePtr = nodePtr->getPrev();
					}


					bucket[j].clear();
				}

			}

			pow10 *= 10;

		}

	}



	/*
	* Function that sorts a linked list of type string by the radix sort algorithm
	*/
	void radixSort(List<string> &list) {

		Node<string> *headRef = list.getHead();
		Node<string> *nodePtr;
		List<string> bucket[53];
		int maxLength = radixGetMaxLength(&list);

		for (int i = maxLength - 1; i >= 0; i--) {
			nodePtr = headRef;

			while (nodePtr != nullptr) {
				if (nodePtr->getData().length() < i + 1) {
					bucket[0].add(nodePtr->getData());
				}

				else {
					int index = nodePtr->getData().at(i) - 64; //index of bucket array by ascii value

					if (index >= 33)
						index -= 6;

					if (index < 0 || index > 53)
						index = 0;

					bucket[index].add(nodePtr->getData());
				}

				nodePtr = nodePtr->getPrev();
			}

			nodePtr = headRef;

			for (int j = 0; j < 53; j++) {
				Node<string> *bucketNodePtr = bucket[j].getHead();

				if (bucketNodePtr != nullptr) {
					while (bucketNodePtr->getPrev() != nullptr) {
						bucketNodePtr = bucketNodePtr->getPrev();
					}

					while (bucketNodePtr != nullptr) {
						nodePtr->setData(bucketNodePtr->getData());
						bucketNodePtr = bucketNodePtr->getNext();
						nodePtr = nodePtr->getPrev();
					}

					bucket[j].clear();
				}
			}

		}

	}



	/*
	* Function that performs a binary search for a given data in a doubly linked list
	*/
	template <typename T>
	Node<T> *binarySearch(const List<T> *list, T data) {
		cout << "Binary search: Searching for \"" << data << "\" ... " << endl;

		bool found = false;
		int numSearches = 0;
		int firstPos = 1; //initial position of first node
		int lastPos = list->getNumNodes(); //initial position of last node
		int middlePos;
		Node<T> *first = list->getHead(); //pointer to first node
		Node<T> *last = getNodePos(list, lastPos); //pointer to last node
		Node<T> *middle = nullptr; //pointer to middle node

		while (!found && first->getData() <= last->getData()) {
			
			middlePos = (firstPos + lastPos) / 2;
			middle = getNodePos(list, middlePos);

			if (middle->getData() < data) {
				firstPos = middlePos + 1;
				first = middle->getPrev();
			}

			else if (middle->getData() > data) {
				lastPos = middlePos - 1;
				last = middle->getNext();
			}

			else {
				found = true;
			}

			numSearches++;
		}

		cout << "Number of binary searches: " << numSearches << endl;

		if (found) {
			cout << "Data \"" << data << "\" found" << endl;
		}

		else {
			cout << "Data \"" << data << "\" not found" << endl;
			middle = nullptr;
		}


		return middle;

	}
	


};

#endif




