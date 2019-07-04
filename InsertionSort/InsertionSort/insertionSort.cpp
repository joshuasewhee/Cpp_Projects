/*
 * Name: Joshua Sew-Hee
 * Date: 7/3/2019
 * Desc: Insertion Sort
 * Prob: Sort an array of any given size using insertion sort.
		 Display the minimum, maximum and average values of the array.
		 Detect whether an array is sorted or not, and if it is not sorted, sort it.
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

void fillArray(int array[], int size)
{
	// Seed the randomizer
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		// Keep numbers small for testing
		array[i] = rand() % LIMIT;
	}
}

void insertionSort(int array[], int size)
{
	sort(array, size);

	cout << "Sorted array:\n";
	displayArray(array, size);
	cout << "\n\n";

}

// This function finds the maximum value in the array.
int maxVal(int array[], int size) {
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

// This function finds the minimum value in the array.
int minVal(int array[], int size) {
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

// This function finds the average value in the array.
int averageVal(int array[], int size)
{
	int sum = 0;
	int avg = 0;
	for (int i = 0; i < size; i++) 
	{
		sum = sum + array[i];
	}
	avg = sum / size;
	return avg;
}

int medianVal(int array[], int size)
{
	if (size % 2)
	{
		return (size / 2) + 1; // If odd, n is the median
	}
	else
	{
		return size / 2; // if even, n + 1 is the median
	}
}

// This function finds the mode in a sorted array.
int modeVal(int array[], int size)
{
	int number = array[0]; // First element
	int mode = number; // Mode initialized
	int count = 1; // Initial count
	int counterMode = 1; // Mode counter

	for (int i = 1; i < size; i++)
	{
		if (array[i] == number)
		{
			count++;
		}
		else {
			if (count > counterMode) {
				counterMode = count; // Biggest occurance count
				mode = number;
			}

			count = 1; // Reset count for new number
			number = array[i];
		}
	}
	return mode;
}


// This functions determines if the array is sorted.
bool isSorted(int array[], int size)
{
	// Array is has one or no element.
	if (size == 0 || size == 1)
	{
		return 1;
	}
	for (int i = 1; i < size; i++)
	{
		// Unsorted pair found
		if (array[i-1] > array[i])
		{
			return false;
		}
	}
	// No unsorted pair found
	return true;
}


int main()
{
	int size;
	
	cout << "This program:\n1. generates an array filled with random numbers,\n";
	cout << "2. determines if the array is sorted or not, and if it is not sorted, sorts the latter,\n";
	cout << "3. displays the minimum, maximum, average, median, and mode of the values in the array.\n\n";
	cout << "Enter size of array: ";
	cin >> size;
	int * array = new int[size]; // Create the array with the size the user input
	
	fillArray(array, size);	// Put numbers in the array
	cout << "Original array:\n";
	displayArray(array, size); // Print the newly created array
	cout << "\n\n";

	// Check if array is sorted, and sort it if it is not.
	if (isSorted(array, size)) {
		cout << "Array is already sorted.\n";
		cout << "\n\n";
	}
	else
	{
		cout << "Array is not sorted. Sorting now...\n";
		insertionSort(array, size);
	}

	// Display array information
	cout << "Min number in myArray: " << minVal(array, size) << "\n";
	cout << "Max number in myArray: " << maxVal(array, size) << "\n";
	cout << "Average number in myArray: " << averageVal(array, size) << "\n";
	cout << "Median number in myArray: " << medianVal(array, size) << "\n";
	cout << "Mode number in myArray: " << modeVal(array, size) << "\n";


	return 0;
}