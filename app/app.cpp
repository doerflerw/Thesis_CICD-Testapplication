/*
	Testapplication 

	This application was created as part of my Bachelorthesis.
	The application contains Unit-, Integration and Regressiontests, which are programmed with help of the Google-Test framework.
	Every category of tests is programmed inside its own subproject.
	The categories have Fixtures to be able to inherit more Testsuites based on the same characteristica, even tho the Fixtures are held pretty basic.
	Some code is put into Compiler-Switch-dependant to demonstrate the usage of Compiler-Switches and Code-Coverage.

	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, the created testcases and testsuites are .
	
	To build and use this Application on a Remote-Station:
		1. Clone the repository to a specific location
		2. Add the name of the Remote-Station and the Source-Directory of the Application to the "buildSource"-Directory of the "build_config.py" script

	Author: Wolfgang Dörfler
*/

#include "app.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	cout << "This Application was created for the cause of demonstrating the Integration of a Softwareproject into the CICD-Pipeline.";

	// Create some failures/memory-leaks which should be detected at the static-code-analysis

	// call an array-element with non-existend index
	int test[10];
	int a = test[12];

	// allocate memory which wont get freed 
	int * q = new int;
	int * p = new int;

	return 0;
}
