#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, AllOffAfterCreate);
	RUN_TEST_CASE(LedDriver, TurnOnLed1);
	RUN_TEST_CASE(LedDriver, TurnOffLed1);
	RUN_TEST_CASE(LedDriver, TurnOnLed2);
	RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
	RUN_TEST_CASE(LedDriver, TurnOffMultipleLeds);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
	RUN_TEST_CASE(LedDriver, AllOn);
	RUN_TEST_CASE(LedDriver, AllOff);
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadableWhenOn);
	RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadableWhenOff);
	RUN_TEST_CASE(LedDriver, UpperLowerBounds);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOnNothing);
	RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffNothing);
	RUN_TEST_CASE(LedDriver, OutOfBoundsProduceRuntimeError);
	RUN_TEST_CASE(LedDriver, IsOn);
	RUN_TEST_CASE(LedDriver, IsOff);
	RUN_TEST_CASE(LedDriver, OutOfBoundsAlwaysFalse);
}
