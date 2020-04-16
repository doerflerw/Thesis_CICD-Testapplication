/*
	FixtureTest - Includes a basic Fixture-Example to showcase its usability and use it for integrationtesting

	This file was created as part of my Bachelorthesis to demonstrate the integration of a basic Google-Test Fixture inside an application.
	It contains a basic Example-Fixture from Google-Test.
	Due to the fact that this Applications use-case is to only demonstrate the integration into the CICD-Pipeline, the characteristics of the Fixture will only be basic.

	Author: Wolfgang Dörfler
*/

#pragma once

#include "gtest/gtest.h"

// Fixture example for CICD testing
class CICDFixture : public testing::Test {
protected:

	CICDFixture();

	virtual void SetUp();

	virtual void TearDown();

};