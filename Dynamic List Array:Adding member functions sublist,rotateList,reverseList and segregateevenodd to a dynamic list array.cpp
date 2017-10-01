//****************************************************************************
//Project 1: Implementing the dynamic List ADT using array
//Creating member functions: print,sublist,rotatelist, reverse list and segregate even odd
//**********************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

　
　
class List

{

private:
	int *array;
	int maxSize;         // useful to decide if resizing (doubling the array size) is needed
	int endOfArray;     //The last index of array lengthofArray-1

　
　
public:
	List(int size)

	{
		array = new int[size];
		maxSize = size;
		endOfArray = -1;

	}

　
	bool isEmpty()

	{
		if (endOfArray == -1)
			return true;
		return false;

	}

	void resize(int s)

	{
		int *tempArray = array;
		array = new int[s];

		for (int index = 0; index < min(s, endOfArray + 1); index++)
		{
			array[index] = tempArray[index];
		}
		maxSize = s;

	}

　
　
	void insert(int data)//inserts data at the end of array

	{
		if (endOfArray == maxSize - 1)
			resize(2 * maxSize);

		array[++endOfArray] = data;

	}

　
	void insertAtIndex(int insertIndex, int data)

	{

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

　
　
	int read(int index)

	{

		return array[index];

	}

　
　
	void modifyElement(int index, int data)

	{

		array[index] = data;

	}

　
　
	void deleteElement(int deleteIndex)

	{

		/* shift elements one cell to the left starting from deleteIndex+1 to endOfArray-1

		i.e., move element at deleteIndex+1 to deleteIndex and so on */

		for (int index = deleteIndex; index < endOfArray; index++)

			array[index] = array[index + 1];

		endOfArray--;

	}

　
　
	int countList()

	{

		int count = 0;

		for (int index = 0; index <= endOfArray; index++)

			count++;

		return count;

	}

　
	//New added member functions 
	void print()

	{

		for (int index = 0; index <= endOfArray; index++)

			cout << array[index] << " ";
		cout << endl;

	}

	List subList(int fromIndex, int toIndex) {

		int length = (toIndex - fromIndex) + 1;
		List* subarr = new List(length);

　
		for (int i = 0; i <length; i++) {
			subarr->insertAtIndex(i, array[fromIndex]);
			fromIndex++;

		}
		return *subarr;
	}

	void rotateList(int rotationSpace) {

		int temp;

		for (int i = 0; i < rotationSpace; i++) {

			temp = array[0];

			for (int j = 0; j < endOfArray; j++) {

				array[j] = array[j + 1];

			}

			array[endOfArray] = temp;

		}

	}

	void reverseList() {

　
		for (int i = 0; i < (endOfArray + 1) / 2; i++) {

			int temp = array[i];

			array[i] = array[endOfArray - i];

			array[endOfArray - i] = temp;

		}

	};

	void segregateEvenOdd() {
		int temp;
		int endPoint = endOfArray;

　
		for (int i = 0; i <= endPoint; i++) {

			if ((array[i] % 2) == 0) {

				array[i] = array[i];
			}
			else
			{
				temp = array[i];
				for (int index = i; index < endPoint; index++)
					array[index] = array[index + 1];

				array[endPoint] = temp;
				if (array[i] % 2 != 0)
				{
					i--;
					endPoint--;

				}

　
　
			}
		}

	}

　
　
　
};

　
　
　
int main()

{

	int listSize;

	cout << "Enter list size: ";

	cin >> listSize;

　
　
	List integerList(1); // we will set the maxSize to 1 and double it as and when needed

　
　
	for (int i = 0; i < listSize; i++)

	{

		int value;

		cout << "Enter element # " << i << " : ";

		cin >> value;

　
　
		integerList.insertAtIndex(i, value);

	}

　
　
	cout << "Original List: ";

	integerList.print();

	List sublist = integerList.subList(2, 4);
	cout << "Sub list from 2 to 4: ";
	sublist.print();

	integerList.rotateList(2);
	cout << "After rotation(2 elements to the left):";
	integerList.print();

	integerList.reverseList();
	cout << "After reverse: ";
	integerList.print();

　
　
	integerList.segregateEvenOdd();
	cout << "After even or odd segregation: ";

	integerList.print();

	return 0;
}

　
　
