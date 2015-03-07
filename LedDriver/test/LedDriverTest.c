#include "unity.h"
#include "unity_fixture.h"

#include "stdint.h"

#include "LedDriver.h"


TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
}
TEST_TEAR_DOWN(LedDriver)
{
}
TEST(LedDriver, AllOffAfterCreate)
{
    uint16_t virtualleds = 0xFFFF;
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
}


