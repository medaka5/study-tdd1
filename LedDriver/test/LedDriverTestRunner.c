#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, AllOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLed1);
	RUN_TEST_CASE(LedDriver, TurnOffLed1);
	RUN_TEST_CASE(LedDriver, TurnOnLed2);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, AllOn);
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadable);
}
