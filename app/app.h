// CICD_Example.h 

#pragma once
#include <cmath>
#include <stdio.h>


using namespace std;

class ExampleClass {
public:
	double length;   // Length of a box
	double breadth;  // Breadth of a box
	double height;   // Height of a box
};


/*	Function raises parameter 1 by the power of parameter 2
	Parameter: double b, double p
*/
double cubic(double b, double p)
{
	printf("\n\nGiven base: %f, given Power %f", b, p);
	return pow(b, p);
}

/*	Function calculates the factorial (Fakultät) of all integers smaller than the given parameter
	Parameter: int n
*/
int Factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

/*	Function does some basic calculation based on given INT-Parameter for testing purposes.
	Parameter: int 
*/
int CoverageTest(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

/*	Function returns true if given INT-Parameter is a prime number.
	Parameter: int
*/
bool primeNumber(int n) {
	// catch small and even numbers
	if (n <= 1) return false;
	if (n % 2 == 0) return n == 2;

	// Try to divide n by every odd number i, starting from 3
	for (int i = 3; ;i += 2) {
		// counter only has to be up to the square root of n
		if (i > n / i) break;
		// test possible division by i
		if (n % i == 0) return false;
	}
	// if there was no break until now, the given numer is a prime number
	return true;
}