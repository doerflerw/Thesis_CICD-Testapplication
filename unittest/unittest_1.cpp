// unittest_example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gtest/gtest.h"
#include "FixtureTest.h"
#include "app.h"



// Fixture
// Alle IntegerFunctionTests bernehmen automatisch die Logik von QuickTest durch Vererbung
class IntegerFunctionTest : public QuickTest {
	// Kann Leer bleiben
};

// TEST(..)		- Normaler Tests
// TEST_F(..)	- Fixture Test

TEST_F(IntegerFunctionTest, Factorial) {
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

#ifdef CS_OFF

TEST_F(IntegerFunctionTest, IsPrime) {
	// Tests negative input.
	EXPECT_FALSE(IsPrime(-1));
	EXPECT_FALSE(IsPrime(-2));
	EXPECT_FALSE(IsPrime(INT_MIN));

	// Tests some trivial cases.
	EXPECT_FALSE(IsPrime(0));
	EXPECT_FALSE(IsPrime(1));
	EXPECT_TRUE(IsPrime(2));
	EXPECT_TRUE(IsPrime(3));

	// Tests positive input.
	EXPECT_FALSE(IsPrime(4));
	EXPECT_TRUE(IsPrime(5));
	EXPECT_FALSE(IsPrime(6));
	EXPECT_TRUE(IsPrime(23));
}


#endif // CS_OFF

TEST(TestCase_1, Potenz)
{
	EXPECT_EQ(1000, cubic(10));
}

TEST(TestCase_2, Addition) {
	EXPECT_EQ(4, 2 + 2);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
