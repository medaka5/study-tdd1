#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
	RUN_TEST_CASE(LedDriver, AllOffAfterCreate);
	RUN_TEST_CASE(LedDriver, CreateAndOn1);
}
