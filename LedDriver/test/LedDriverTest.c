#include "unity.h"
#include "unity_fixture.h"

#include "stdint.h"

#include "LedDriver.h"


TEST_GROUP(LedDriver);

static uint16_t virtualleds;
TEST_SETUP(LedDriver)
{
    virtualleds = 0xFFFF;
    LedDriver_Create(&virtualleds);
}
TEST_TEAR_DOWN(LedDriver)
{
}
TEST(LedDriver, AllOffAfterCreate)
{
    TEST_ASSERT_EQUAL_HEX16(0, virtualleds);
}


TEST(LedDriver, TurnOnLed1)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualleds);
}

TEST(LedDriver, TurnOffLed1)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualleds);
}
TEST(LedDriver, TurnOnLed2)
{
    LedDriver_TurnOn(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002, virtualleds);
}
TEST(LedDriver, TurnOnMultipleLeds)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(0x0180, virtualleds);
}
TEST(LedDriver, AllOn)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualleds);
}
TEST(LedDriver, AllOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualleds);
}
TEST(LedDriver, TurnOffAnyLed)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16(0xFEFF, virtualleds);
}
TEST(LedDriver, LedMemoryIsNotReadableWhenOn)
{
    virtualleds = 0xFFFF;
    LedDriver_TurnOn(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002, virtualleds);
}
TEST(LedDriver, LedMemoryIsNotReadableWhenOff)
{
    LedDriver_TurnAllOn();
    virtualleds = 0x0000;
    LedDriver_TurnOff(2);
    TEST_ASSERT_EQUAL_HEX16(0xFFFD, virtualleds);
}
