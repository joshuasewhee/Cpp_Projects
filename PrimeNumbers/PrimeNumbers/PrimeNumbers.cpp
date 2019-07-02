/*
Name: Joshua Sew-Hee
Date: 7/2/19
Desc: Prime Numbers

This program allows the user to enter a limit of desired prime numbers and displays them.
*/
#include <iostream>

using namespace std;

bool isDivisible(int number, int divisor)
{
	return (number % divisor) == 0;
}


bool isPrime(int number)
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

void displayPrimeFactors(int n)
{
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
}

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
		cout << n << " ";
		sum = sum + n;
	}
	return sum;
}


int main()
{
	int limit;
	int primeNumberCount = 1;

	cout << "This program displays prime numbers.\n";
	cout << "Type the upper bound of the prime number you want: ";
	cin >> limit;
	for (int i = 0; i < limit; i++)
	{
		cout ;
		if (isPrime(i))
		{
			cout << "Prime number " << primeNumberCount << ": " << i << "\n";
			primeNumberCount++;
		}
	}

	displayPrimeFactors(limit);
	int sumPF = sumOfPrimeFactors(limit);
	
	for (int i = 0; i < 10; i++)
	{
		if (isPrime(i)) // need to rework
		{
			cout << i << " ";
		}
	}

	if (isPrime(sumOfPrimeFactors(limit)))
	{
		cout << limit << " ";
	}

	cout << "Done";
	
}