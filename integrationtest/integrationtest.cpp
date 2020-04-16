/*
	Integrationtests - Includes Tests which are expected to run without failures

	This file was created as part of my Bachelorthesis to demonstrate the integration of Regressiontests inside an application.
	It contains a Fixture and includes some example tests.
	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, there are just some basic testcases.

	Author: Wolfgang Dörfler
*/

#include <iostream>
#include "gtest/gtest.h"
#include "integrationtest.h"
#include "app.h"

// Testcases which interact with a class and a function for testing purposes
TEST_F(IntegrationTest, IntegrationTesting) {
	EXPECT_EQ(100000, integrationCubic(10, 5));
	EXPECT_GE(150000, integrationCubic(10, 5));
	EXPECT_GT(50000, integrationCubic(10, 5));

	EXPECT_TRUE(integrationPrimeNumber(5));
	EXPECT_FALSE(integrationPrimeNumber(4));
	EXPECT_TRUE(integrationPrimeNumber(23));
	EXPECT_FALSE(integrationPrimeNumber(6));
}

// Some Testcases were put inside Compiler-Switch-dependant code for testing-purposes
#ifdef CS_OFF

TEST_F(IntegrationTest, Integration_CS) {
	EXPECT_EQ(100000, integrationCubic(10, 5));
	EXPECT_GE(150000, integrationCubic(10, 5));
	EXPECT_GT(50000, integrationCubic(10, 5));

	EXPECT_TRUE(integrationPrimeNumber(5));
	EXPECT_FALSE(integrationPrimeNumber(4));
	EXPECT_TRUE(integrationPrimeNumber(23));
	EXPECT_FALSE(integrationPrimeNumber(6));
}

#endif // CS_OFF