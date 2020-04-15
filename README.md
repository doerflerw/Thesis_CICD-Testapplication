Testapplication 

This application was created as part of my Bachelorthesis.
The application contains Unit-, Integration and Regressiontests, which are programmed with help of the Google-Test framework.
Every category of tests is programmed inside its own subproject.
The categories have Fixtures to be able to inherit more Testsuites based on the same characteristica, even tho the Fixtures are held pretty basic.
Some code is put into Compiler-Switch-dependant to demonstrate the usage of Compiler-Switches and Code-Coverage.

Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, the created testcases and testsuites are .
	
To build and use this Application on a Remote-Station:
	1. Clone the repository to a specific location
	2. Add the name of the Remote-Station and the Source-Directory of the Application to the "buildSource"-Directory of the "build_config.py" script located in "/library/pipeline/" inside the automation-framework-directory

Author: Wolfgang Dörfler