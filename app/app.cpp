// CICD_Example.cpp : Defines the entry point for the application.
//

#include "app.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Hello World"; // prints Hello World
	cubic(20);
	int test[10];
	int a = test[12];

	// create memory leak for testing
	int * q = new int;
	int * p = new int;

	return 0;
}