// Question 1:Printing forward and reversely using recursion

#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
using namespace std;

// implementing the dynamic List ADT using Linked List
// operations to be implemented: read, Modify, delete, isEmpty, insert, countElements

class Node {

private:
	int data;
	Node* nextNodePtr;

public:
	Node() {}

	void setData(int d) {
		data = d;
	}

	int getData() {
		return data;
	}

	void setNextNodePtr(Node* nodePtr) {
		nextNodePtr = nodePtr;
	}

	Node* getNextNodePtr() {
		return nextNodePtr;
	}

};

class List {

private:
	Node *headPtr;

public:
	List() {
		headPtr = new Node();
		headPtr->setNextNodePtr(0);
	}

	bool isEmpty() {

		if (headPtr->getNextNodePtr() == 0)
			return true;

		return false;
	}

	Node* getHeadNodePtr() {
		return headPtr;
	}

	void insert(int data) {

		Node* currentNode = headPtr->getNextNodePtr();
		Node* prevNode = headPtr;

		while (currentNode != 0) {
			prevNode = currentNode;
			currentNode = currentNode->getNextNodePtr();
		}

		Node* newNode = new Node();
		newNode->setData(data);
		newNode->setNextNodePtr(0);
		prevNode->setNextNodePtr(newNode);

	}

	void insertAtIndex(int insertIndex, int data) {

		Node* currentNode = headPtr->getNextNodePtr();
		Node* prevNode = headPtr;

		int index = 0;

		while (currentNode != 0) {

			if (index == insertIndex)
				break;

			prevNode = currentNode;
			currentNode = currentNode->getNextNodePtr();
			index++;
		}

		Node* newNode = new Node();
		newNode->setData(data);
		newNode->setNextNodePtr(currentNode);
		prevNode->setNextNodePtr(newNode);

	}

　
	int read(int readIndex) {

		Node* currentNode = headPtr->getNextNodePtr();
		Node* prevNode = headPtr;
		int index = 0;

		while (currentNode != 0) {

			if (index == readIndex)
				return currentNode->getData();

			prevNode = currentNode;
			currentNode = currentNode->getNextNodePtr();

			index++;

		}

		return -1; // an invalid value indicating 
				   // index is out of range

	}

	void modifyElement(int modifyIndex, int data) {

		Node* currentNode = headPtr->getNextNodePtr();
		Node* prevNode = headPtr;
		int index = 0;

		while (currentNode != 0) {

			if (index == modifyIndex) {
				currentNode->setData(data);
				return;
			}

			prevNode = currentNode;
			currentNode = currentNode->getNextNodePtr();

			index++;
		}

　
	}

　
	void deleteElement(int deleteIndex) {

		Node* currentNode = headPtr->getNextNodePtr();
		Node* prevNode = headPtr;
		Node* nextNode = headPtr;
		int index = 0;

		while (currentNode != 0) {

			if (index == deleteIndex) {
				nextNode = currentNode->getNextNodePtr();
				break;
			}

			prevNode = currentNode;
			currentNode = currentNode->getNextNodePtr();

			index++;
		}

		prevNode->setNextNodePtr(nextNode);

	}

	int countList() {

		Node* currentNode = headPtr->getNextNodePtr();
		int numElements = 0;

		while (currentNode != 0) {

			numElements++;
			currentNode = currentNode->getNextNodePtr();

		}

		return numElements;
	}

　
	void IterativePrint() {

		Node* currentNode = headPtr->getNextNodePtr();

		while (currentNode != 0) {
			cout << currentNode->getData() << " ";
			currentNode = currentNode->getNextNodePtr();
		}

		cout << endl;

	}

　
	// add the code to the member function
	// RecursivePrintForwardReverseOrders(Node*)
	/* Function to reverse the linked list */
	void recursivePrintForwardReverseOrders(Node* forwardHead, Node*reverseHead)
	{

　
		if (forwardHead != 0)
		{

			cout << " " << forwardHead->getData();
			recursivePrintForwardReverseOrders(forwardHead->getNextNodePtr(), reverseHead);
			cout << endl;
		}
		else
		{
			if (reverseHead == 0) {
				cout << endl;
				return;
			}

　
			recursivePrintForwardReverseOrders((forwardHead = 0), reverseHead->getNextNodePtr());

			cout << " " << reverseHead->getData();

		}

　
　
	}
};

int main() {

	int listSize;

	cout << "Enter the number of elements you want to insert: ";
	cin >> listSize;

	List integerList; // Create an empty list

	srand(time(NULL));

	int maxValue;

	cout << "Enter the maximum value for an element: ";
	cin >> maxValue;

　
	for (int i = 0; i < listSize; i++) {
		int value = rand() % maxValue;
		integerList.insertAtIndex(i, value);
	}

	cout << "Contents of the List (IterativePrint): ";
	integerList.IterativePrint();

	cout << endl;

	cout << "Contents of the List (Forward and Reverse Orders) " << endl;
	Node* firstNodePtr = integerList.getHeadNodePtr()->getNextNodePtr();
	integerList.recursivePrintForwardReverseOrders(firstNodePtr, firstNodePtr);

	return 0;
}
