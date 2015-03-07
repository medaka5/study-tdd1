#include "unity.h"
#include "unity_fixture.h"

#include "stdint.h"

#include "LedDriver.h"


TEST_GROUP(LedDriver);

static uint16_t virtualleds;
TEST_SETUP(LedDriver)
{
    virtualleds = 0xFFFF;
}
TEST_TEAR_DOWN(LedDriver)
{
}
TEST(LedDriver, AllOffAfterCreate)
{
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
}


TEST(LedDriver, TurnOnLed1)
{
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualleds);
}

TEST(LedDriver, TurnOffLed1)
{
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualleds);
}
