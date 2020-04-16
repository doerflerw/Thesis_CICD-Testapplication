/*
	Testapplication

	This file was created as part of my Bachelorthesis. 
	It contains a different functions which are tested within the subprojects of this application.
	It also contains a basic class to demonstrate the usage of function/class interacting to showcase integrationtesting.
	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, there are mostly some basic testcases.

	Author: Wolfgang Dörfler

*/

#pragma once
#include <cmath>
#include <stdio.h>


using namespace std;

// Example Class for Integrationtesting purposes.
class Example {
public:
	double p1;         
	double p2;   
	int p3;


	// Member functions declaration
	void setA(double a);
	void setB(double b);
	void setC(int c);
};

// Member functions definitions
void Example::setA(double a) {
	p1 = a;
}
void Example::setB(double b) {
	p2 = b;
}
void Example::setC(int c) {
	p3 = c;
}


// Testing-Functions

/*	Function which interacts with class object for integration-testing and raises parameter 1 by the power of parameter 2
	Parameter: double b, double p
*/
double integrationCubic(double b, double p)
{
	// Create object of testing-class
	Example Example1;
	Example1.setA(b);
	Example1.setB(p);


	printf("\n\nGiven base: %f, given Power %f", b, p);

	// Use objects data
	return pow(Example1.p1, Example1.p2);
}


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


/*	Function for integrationtesting which interacts with a class object and returns true if given INT-Parameter is a prime number.
	Parameter: int
*/
bool integrationPrimeNumber(int n) {

	Example Example1;
	Example1.setC(n);

	// catch small and even numbers
	if (Example1.p3 <= 1) return false;
	if (Example1.p3 % 2 == 0) return Example1.p3 == 2;

	// Try to divide n by every odd number i, starting from 3
	for (int i = 3; ; i += 2) {
		// counter only has to be up to the square root of n
		if (i > Example1.p3 / i) break;
		// test possible division by i
		if (Example1.p3 % i == 0) return false;
	}
	// if there was no break until now, the given numer is a prime number
	return true;
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