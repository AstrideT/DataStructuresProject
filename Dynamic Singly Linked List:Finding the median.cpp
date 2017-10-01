
//******************************************************************************************************
//Finding the median of a dynamic linked list 
//If n is even,then median is n/2
//If n is odd, then median is (n-1)/2
//******************************************************************************************************

#include <iostream>
using namespace std;

// implementing the dynamic List ADT using Linked List

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
		headPtr = new Node();//creates 1 node
		headPtr->setNextNodePtr(0);//points to nothing end of list
	}

	Node* getHeadPtr() {
		return headPtr;//pointing to head node
	}

	bool isEmpty() {

		if (headPtr->getNextNodePtr() == 0)
			return true;

		return false;
	}

　
	void insert(int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		while (currentNodePtr != 0) {
			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(0);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}

	void insertAtIndex(int insertIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		int index = 0;

		while (currentNodePtr != 0) {

			if (index == insertIndex)
				break;

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
			index++;
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(currentNodePtr);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}

　
	int read(int readIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == readIndex)
				return currentNodePtr->getData();

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;

		}

		return -1; // an invalid value indicating 
				   // index is out of range

	}

　
　
	void modifyElement(int modifyIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == modifyIndex) {
				currentNodePtr->setData(data);
				return;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}

　
	}

　
	void deleteElement(int deleteIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		Node* nextNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == deleteIndex) {
				nextNodePtr = currentNodePtr->getNextNodePtr();
				break;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}

		prevNodePtr->setNextNodePtr(nextNodePtr);

	}

　
	void IterativePrint() {

		Node* currentNodePtr = headPtr->getNextNodePtr();

		while (currentNodePtr != 0) {
			cout << currentNodePtr->getData() << " ";
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		cout << endl;

	}

　
	int findMiddleElement() {
		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int count = -1;

		while (currentNodePtr != 0) {

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			count++;
		}

		int middleIndex;
		if (count % 2 == 0) {
			middleIndex = count / 2;
		}
		else
			middleIndex = (count - 1) / 2;
		return read(middleIndex);
	}

	// add code for the member function to find the value of the 
	// middle element in the list and return the value

　
　
　
};

int main() {

	int listSize;

	cout << "Enter the number of elements you want to insert: ";
	cin >> listSize;

	List integerList; // Create an empty list

	for (int i = 0; i < listSize; i++) {

		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;

		integerList.insertAtIndex(i, value);
	}

	cout << "Contents of the List: ";
	integerList.IterativePrint();
	// add code to call the member function to find the value of the middle element in the
	// integerList and print the return value of the function

	cout << "Middle element is:  " << integerList.findMiddleElement() << endl << endl;

	return 0;
}
