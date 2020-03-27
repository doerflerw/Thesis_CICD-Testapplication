#include <iostream>
#include "gtest/gtest.h"
#include "regressiontest.h"
#include "app.h"
#include "caneasy/caneasy.tlh"
//#include "caneasy/caneasy.tli"
#include "caneasy/comsvr.tlh"
//#include "caneasy/comsvr.tli"
#include <atlbase.h>
#include <atlsafe.h>

/*
class CEEnvironment : public ::testing::Environment {
public:
	CEEnvironment() {}
	virtual ~CEEnvironment() {}

	// Override this to define how to set up the environment.
	virtual void SetUp()
	{
		printf("Global own setup\n");
		// add CE Init here
	}

	// Override this to define how to tear down the environment.
	virtual void TearDown()
	{
		printf("Global own teardown\n");
		// add CE Deinit here
	}
};
*/
class CEConnection : public ::testing::Test {
protected:
	void SetUp() override
	{
		CComPtr<CanEasyProcess::ICanEasyProcess> process;
		if (!boConnected)
		{

			auto hr = process.CoCreateInstance(__uuidof(CanEasyProcess::CanEasyProcess));
			if (FAILED(hr))
			{
				printf("====> CoCreateInstance FAILED\n");
				return;
			}

			// keep CanEasy open even if the StreamingApp is beeing closed
			process->KeepAlive();

			auto appDisp = process->GetApplication();
			if (FAILED(hr))
			{
				printf("====> FAILED GetApplication()\n");
				return;
			}

			if (FAILED(appDisp->QueryInterface(&m_pCanEasy)))
			{
				m_pCanEasy = nullptr;
				printf("====> FAILED Interface query\n");
				return;
			}

			printf("====> Connection established\n");
			boConnected = true;

		}
	}

	void TearDown() override
	{

	}

	static bool boConnected;
	static CComPtr<CanEasy::ICanEasyApplication> m_pCanEasy;
};

// only connect to CE once, regardless of test order/types
// all CE tests must be derived from CEConnection
bool CEConnection::boConnected = false;
CComPtr<CanEasy::ICanEasyApplication> CEConnection::m_pCanEasy = nullptr;   // pointer to COM object


TEST_F(CEConnection, ConnectTest)
{
	auto u64Time = 0;
	CEConnection::m_pCanEasy->Simulation->Start();
	Sleep(100);

	u64Time = CEConnection::m_pCanEasy->Simulation->TimestampAsUint64;
	EXPECT_TRUE((u64Time > 0) && (u64Time < 200));

	Sleep(200);

	u64Time = CEConnection::m_pCanEasy->Simulation->TimestampAsUint64;
	EXPECT_TRUE(u64Time > 100);

	CEConnection::m_pCanEasy->Simulation->Stop();
}

TEST_F(CEConnection, RunTestCase1)
{
	//CEConnection::m_pCanEasy->Quit();
}
