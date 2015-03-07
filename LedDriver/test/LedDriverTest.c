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


TEST(LedDriver, TurnOnLed1)
{
    uint16_t virtualleds = 0xFFFF;
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualleds);
}

TEST(LedDriver, TurnOffLed1)
{
    uint16_t virtualleds = 0xFFFF;
    LedDriver_Create(&virtualleds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualleds);
}
