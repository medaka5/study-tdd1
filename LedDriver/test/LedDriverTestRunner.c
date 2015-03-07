#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, AllOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLed1);
	RUN_TEST_CASE(LedDriver, TurnOffLed1);
}
