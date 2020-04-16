/*
	Regressiontests - Includes Tests which are expected to run without failures

	This file was created as part of my Bachelorthesis to demonstrate the integration of Regressiontests inside an application.
	It it interacts with a Fixture which then interacts with CanEasy and includes some example tests.
	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, there wont be any more testing of CanEasy.
	Has to run on a Remote-Station, so the connection to CanEasy can be established.

	Author: Wolfgang Dörfler
*/

#include <iostream>
#include "gtest/gtest.h"
#include "regressiontest.h"
#include "app.h"


// only connect to CE once, regardless of test order/types
// all CE tests must be derived from CEConnection
bool RegressionTest::boConnected = false;
CComPtr<CanEasy::ICanEasyApplication> RegressionTest::m_pCanEasy = nullptr;   // pointer to COM object

// Testcase to establish a CanEasy connection
TEST_F(RegressionTest, ConnectTest)
{
	auto u64Time = 0;
	RegressionTest::m_pCanEasy->Simulation->Start();
	Sleep(150);

	u64Time = RegressionTest::m_pCanEasy->Simulation->TimestampAsUint64;
	EXPECT_TRUE((u64Time > 0) && (u64Time < 200));

	Sleep(250);

	u64Time = RegressionTest::m_pCanEasy->Simulation->TimestampAsUint64;
	EXPECT_TRUE(u64Time > 150);

	RegressionTest::m_pCanEasy->Simulation->Stop();
}

// Testcase which can be filled with basic CanEasy-Tests
TEST_F(RegressionTest, RunTestCase1)
{

}
