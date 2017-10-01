// Question3:Merging smaller list to a longer list while eliminating data of smaller list already present in larger list

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
		headPtr = new Node();
		headPtr->setNextNodePtr(0);
	}

	Node* getHeadPtr() {
		return headPtr;
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

　
　
　
　
	// add code to the member function mergeList(List)
	void mergeList(List smallerList) {
		Node*prevNodePtr;
		Node* currentNodePtr = headPtr->getNextNodePtr();
		int endOfLargeList = -1;
		while (currentNodePtr != 0) {
			endOfLargeList++;
			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}
		endOfLargeList++;//to increase end of list 

		Node* smallHeadPtr = smallerList.getHeadPtr();
		currentNodePtr = smallHeadPtr->getNextNodePtr();

		while (currentNodePtr != 0) {
			for (int i = 0; i <= endOfLargeList; i++) {
				if ((currentNodePtr->getData()) == read(i))
				{
					currentNodePtr = currentNodePtr->getNextNodePtr();
					continue;
				}
			}
			insertAtIndex(endOfLargeList, currentNodePtr->getData());
			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
			endOfLargeList++;
		}

	}
};

int main() {

	int largerListSize;

	cout << "Enter the number of elements you want to insert in the larger list: ";
	cin >> largerListSize;

	List largerIntegerList;

	for (int i = 0; i < largerListSize; i++) {

		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;

		largerIntegerList.insertAtIndex(i, value);
	}

	cout << "Contents of the Larger List: ";
	largerIntegerList.IterativePrint();

　
	int smallerListSize;

	cout << "Enter the number of elements you want to insert in the smaller list: ";
	cin >> smallerListSize;

	List smallerIntegerList;

	for (int i = 0; i < smallerListSize; i++) {

		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;

		smallerIntegerList.insertAtIndex(i, value);
	}

	cout << "Contents of the Smaller List: ";
	smallerIntegerList.IterativePrint();

	largerIntegerList.mergeList(smallerIntegerList);

	cout << "Contents of the merged list: ";
	largerIntegerList.IterativePrint();

　
	return 0;
}
