/*
 * Name: Joshua Sew-Hee
 * Date: 7/3/2019
 * Desc: Insertion Sort
 * Prob: Sort an array of any given size using insertion sort
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "insertionSort.h"

using namespace std;

// This function finds the smallest remaining element of an array
int findSmallestRemainingElement(int array[], int size, int index)
{
	int index_of_smallest_value = index;
	for (int i = index + 1; i < size; i++)
	{
		if (array[i] < array[index_of_smallest_value])
		{
			index_of_smallest_value = i;
		}
	}
	return index_of_smallest_value;
}

// This function swaps two numbers in an array using their indexes
void swap(int array[], int first_index, int second_index)
{
	int temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}

// This function sorts the array of a given size.
void sort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int index = findSmallestRemainingElement(array, size, i);
		swap(array, i, index);
	}
}

// Helper function to display the before and after arrays
void displayArray(int array[], int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
		{
			cout << ", ";
		}
		cout << array[i];
	}
	cout << "}";
}

void insertionSort(int array[], int size)
{
	// Seed the randomizer
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		// Keep numbers small for testing
		array[i] = rand() % LIMIT;
	}
	cout << "Original array:\n";
	displayArray(array, size);
	cout << '\n';

	sort(array, size);

	cout << "Sorted array:\n";
	displayArray(array, size);
	cout << '\n';
}

int isMax(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int isMin(int array[], int size) {
	int min = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

int main()
{
	int size;
	//cout << "Enter size of array: ";
	//cin >> size;
	
	//int* array = new int[size]; //Create the array with the size the user input

	int myArray[15] = {94, 24, 50, 96, 44, 49, 92, 85, 76, 20, 11, 7, 92, 79, 37};
	//int array[15] = { 78, 92, 49, 9, 7, 41, 58, 28, 77, 23, 81, 24, 21, 82, 60 };
	//cout << sizeof(array)/4;

	//insertionSort(array, size);
	cout << "Max number in myArray: " << isMax(myArray, 15) << "\n";
	cout << "Min number in myArray: " << isMin(myArray, 15) << "\n";
}