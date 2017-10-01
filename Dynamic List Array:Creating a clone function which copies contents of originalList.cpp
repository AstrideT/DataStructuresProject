//*************************************************************************************
//Dynamic List Array:Creating a clone function which copies contents of originalList
//into a new list
//*************************************************************************************

#include <iostream>
#include<algorithm>
using namespace std;

// implementing the dynamic List ADT using array
// operations to be implemented: read, Modify, delete, isEmpty, insert, countElements

class List {

private:
	int *array;
	int maxSize; // useful to decide if resizing (doubling the array size) is needed
	int endOfArray;

public:
	List(int size) {
		array = new int[size];
		maxSize = size;
		endOfArray = -1;
	}

	bool isEmpty() {

		if (endOfArray == -1)
			return true;

		return false;
	}

	void resize(int s) {

		int *tempArray = array;

		array = new int[s];

		for (int index = 0; index < min(s, endOfArray + 1); index++) {
			array[index] = tempArray[index];
		}

		maxSize = s;

	}

　
	void insert(int data) {

		if (endOfArray == maxSize - 1)
			resize(2 * maxSize);

		array[++endOfArray] = data;

	}

　
	void insertAtIndex(int insertIndex, int data) {

		// if the user enters an invalid insertIndex, the element is 
		// appended to the array, after the current last element			
		if (insertIndex > endOfArray + 1)
			insertIndex = endOfArray + 1;

		if (endOfArray == maxSize - 1)
			resize(2 * maxSize);

		for (int index = endOfArray; index >= insertIndex; index--)
			array[index + 1] = array[index];

		array[insertIndex] = data;
		endOfArray++;

	}

　
	int read(int index) {
		return array[index];
	}

	void modifyElement(int index, int data) {
		array[index] = data;
	}

　
	void deleteElement(int deleteIndex) {

		// shift elements one cell to the left starting from deleteIndex+1 to endOfArray-1
		// i.e., move element at deleteIndex + 1 to deleteIndex and so on

		for (int index = deleteIndex; index < endOfArray; index++)
			array[index] = array[index + 1];

		endOfArray--;

	}

	int countList() {
		int count = 0;
		for (int index = 0; index <= endOfArray; index++)
			count++;

		return count;
	}

	void print() {

		for (int index = 0; index <= endOfArray; index++)
			cout << array[index] << " ";

		cout << endl;

	}

　
	// Add the code for the member function clone( ) that creates a copy
	// of the List object on which it is called and returns the List
	List clone() {
		int length = endOfArray + 1;
		List* clonearr = new List(length);
		for (int i = 0; i <= endOfArray; i++)
			clonearr->insertAtIndex(i, array[i]);
		return *clonearr;
	}

　
};

int main() {

	int listSize;

	cout << "Enter list size: ";
	cin >> listSize;

	List integerList(1); // we will set the maxSize to 1 and double it as and when needed

	for (int i = 0; i < listSize; i++) {

		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;

		integerList.insertAtIndex(i, value);
	}

	cout << "Contents of the List: ";
	integerList.print();

	List cloneList = integerList.clone();
	cout << "Contents of the cloneList: ";
	cloneList.print();
	cout << endl;

	// call the clone( ) member function on the integerList object and
	// store the returned List object by the name cloneList
	// Then call the print() function on cloneList and print its contents

　
	return 0;
}
