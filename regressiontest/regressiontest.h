/*
	Regressiontests - Fixture to connect to CanEasy

	This file was created as part of my Bachelorthesis to demonstrate the integration of a Fixture to interact with CanEasy inside an application.
	It contains a Fixture which interacts with CanEasy. The Fixture itself was created by a colleague and is not part of the Bachelorthesis.
	This Applications use-case is to only demonstrate the integration into the CICD-Pipeline.
	Has to run on a Remote-Station, so the connection to CanEasy can be established with help of the given Fixture.

	Author: Wolfgang Dörfler
*/

#pragma once

#include "gtest/gtest.h"
#include "caneasy/caneasy.tlh"
#include "caneasy/comsvr.tlh"
#include <atlbase.h>
#include <atlsafe.h>


// Example Fixture to interact with CanEasy
// This Fixture was created by a colleague and is not part of the Bachelorthesis
class RegressionTest : public ::testing::Test {
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

	void TearDown() override {}

	static bool boConnected;
	static CComPtr<CanEasy::ICanEasyApplication> m_pCanEasy;
};