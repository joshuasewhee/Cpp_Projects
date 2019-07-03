/*
 * Name: Joshua Sew-Hee
 * Date: 7/2/19
 * Desc: Prime Numbers
 * Prob: Design a program that finds all numbers from 1 to N whose prime factors,
 *		 when added together, sum up to a prime number (for eg. 12 has prime 
 *		 factors 2, 3, and 3, which sums to 7, which is prime.
 */

#include <iostream>
#include "PrimeNumbers.h"

using namespace std;

// This function determines if a number is divisible.
bool isDivisible(int number, int divisor)
{
	return (number % divisor) == 0;
}

// This function determines if a number is prime.
bool isPrime(int number)
{
	if (number < 2)
	{
		cerr << "Error: Prime number cannot be less than 2.\n";
		return false;
	}
	else
	{
		for (int i = 2; i < number; i++)
		{
			if (isDivisible(number, i))
			{
				return false;
			}
		}
		return true;
	}
}

// This function displays N prime numbers.
void displayPrimeNumbers(int limit)
{
	int countCol = 0; // Keep track of columns to be printed
	// Need to hardcode the first prime number for formatting issue for the remaining ones
	if (limit > 1) {
		cout << "2";
	}
	else {
		cerr << "Prime numbers start from 2.\n";
	}

	// Limit is limit+1 one to display prime number if it is the limit, for eg. 7
	for (int i = 2; i < limit + 1; i++)
	{
		if (isPrime(i))
		{
			if (countCol == COLUMNS)
			{
				cout << "\t\n" << i;
				countCol = 0;

			}
			else
			{
				cout << "\t" << i;
				countCol++;
			}

		}
		/*	if (isPrime(i))
			{
				cout << "Prime number " << primeNumberCount << ": " << i << "\n";
				primeNumberCount++;
			}*/
	}
	cout << "\n";
}

// This function displays the prime factors of a number.
void displayPrimeFactors(int n)
{
	cout << "Prime factors of " << n << " are: ";
	// Store the number of 2s that divide n
	// This gets rid of all multiples of 2
	while ((n % 2) == 0)
	{
		// Display 2 as prime factor
		cout << 2 << " ";
		n = n / 2;
	}

	// n must be odd now. So skip one element, i.e. i = i + 2
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while ((n % i) == 0)
		{
			cout << i << " ";
			n = n / i;
		}
	}

	// This condition hanles the case when n is prime number > 2
	if (n > 2)
	{
		cout << n << " ";
	}
	cout << "\n";
}

// This function computes the sum of the prime factors of a number.
int sumOfPrimeFactors(int n)
{
	// Initialize sum to zero
	int sum = 0;

	// Store the number of 2s that divide n in sum
	// This gets rid of all multiples of 2
	while ((n % 2) == 0)
	{
		// Display 2 as prime factor
		n = n / 2;
		sum = sum + 2;
	}

	// n must be odd now. So skip one element, i.e. i = i + 2
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, store i in sum, print i and divide n
		while ((n % i) == 0)
		{
			sum = sum + i;
			n = n / i;
		}
	}

	// This condition hanles the case when n is prime number > 2
	if (n > 2)
	{
		sum = sum + n;
	}
	return sum;
}

// This function displays the sum of prime factors of a number.
void displaySumOfPrimeFactors(int limit)
{
	int sumPF = sumOfPrimeFactors(limit);
	if (sumPF == 2) {
		cout << "Sum of prime factors of " << limit << " is " << sumPF << "\n";
	}
	else
	{
		cout << "Sum of prime factors of " << limit << " are " << sumPF << "\n";
	}
}

// This function displays all numbers from 1 to limit whose prime factors, when
// added together, sum up to a prime number.
void displayPrimeFactorsSumPrime(int limit)
{
	int countCol = 0;
	// Need to hardcode the first prime number for formatting issue for the remaining ones
	if (limit > 1) {
		cout << "All number from 1 to " << limit << " whose prime factors, when " <<
			"added together, sum up to a prime number.\n";
		cout << "2";
	}
	else {
		cerr << "Error: Prime numbers start from 2.\n";
	}

	// This for loop starts at 3 since 2 has already been taken care of above.
	for (int i = 3; i < limit+1; i++)
	{
		if (isPrime(sumOfPrimeFactors(i)))
		{
			if (countCol == COLUMNS)
			{
				cout << "\t\n" << i;
				countCol = 0;
			}
			else
			{
				cout << "\t" << i;
				countCol++;
			}
			//cout << i << "\n";
		}
	}
}

int main()
{
	int limit; // Input of max prime number

	cout << "This program displays prime numbers.\n";
	cout << "Type the upper bound of the prime number you want: ";
	cin >> limit;
	
	//displayPrimeNumbers(limit);
	//displayPrimeFactors(limit);
	//displaySumOfPrimeFactors(limit);
	displayPrimeFactorsSumPrime(limit);
	

	cout << "Done";
	return 0;
}