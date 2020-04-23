/*
	Unittests - Includes Tests of single functions/modules

	This file was created as part of my Bachelorthesis to demonstrate the integration of Unittests inside an application.
	It interacts with an Example-Fixture from "FixtureTest.h" which demonstrates a basic Fixture of Google-Test.
	There are also some Testcases which are dependand on a Compiler-Switch.
	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, there will only be some basic testing included.

	Author: Wolfgang Dörfler
*/

#include <iostream>
#include "gtest/gtest.h"
#include "FixtureTest.h"
#include "app.h"


// Create new class based on a Fixture
// All "UnitTest"-Objects are going to inherit the characteristics of the Fixture "CICDFixture"
class UnitTest : public CICDFixture {

};

// TEST(..)		- Normal Tests
// TEST_F(..)	- Fixture Test


// Do some basic testing to demonstrate Google-Test usage
TEST(TestCase_1, RaisePower)
{
	EXPECT_EQ(100000, cubic(10, 5));
	EXPECT_GT(150000, cubic(10, 5));
}

TEST(TestCase_2, Addition) {
	EXPECT_EQ(4, 2 + 2);
}

// Do some basic Fixture-testing to demonstrate Google-Test and Fixture usage
TEST_F(UnitTest, Factorial) {
	// Tests factorial of negative numbers.
	EXPECT_EQ(1, Factorial(-5));
	EXPECT_EQ(1, Factorial(-1));
	EXPECT_GT(Factorial(-10), 0);

	// Tests factorial of 0.
	EXPECT_EQ(1, Factorial(0));

	// Tests factorial of positive numbers.
	EXPECT_EQ(1, Factorial(1));
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
	EXPECT_EQ(40320, Factorial(8));
}

// Some Testcases were put inside Compiler-Switch-dependant code for testing-purposes
#ifdef CS_OFF

TEST_F(UnitTest, primeNumber) {
	// Tests negative inputs
	EXPECT_FALSE(primeNumber(-1));
	EXPECT_FALSE(primeNumber(-2));
	EXPECT_FALSE(primeNumber(INT_MIN));

	// Tests some trivial cases
	EXPECT_FALSE(primeNumber(0));
	EXPECT_FALSE(primeNumber(1));
	EXPECT_TRUE(primeNumber(2));
	EXPECT_TRUE(primeNumber(3));

	// Tests positive inputs
	EXPECT_FALSE(primeNumber(4));
	EXPECT_TRUE(primeNumber(5));
	EXPECT_FALSE(primeNumber(6));
	EXPECT_TRUE(primeNumber(23));
}


#endif // CS_OFF