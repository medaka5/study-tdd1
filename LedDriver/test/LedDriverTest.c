#include "unity.h"
#include "unity_fixture.h"

#include "stdint.h"
#include "LedDriver.h"
#include "RuntimeErrorStub.h"


TEST_GROUP(LedDriver);

static uint16_t virtualleds;
TEST_SETUP(LedDriver)
{
    virtualleds = 0xFFFF;
    LedDriver_Create(&virtualleds);
    RuntimeErrorStub_Reset();
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
TEST(LedDriver, TurnOffMultipleLeds)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    LedDriver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16(0xFE7F, virtualleds);
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
TEST(LedDriver, UpperLowerBounds)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualleds);
}

TEST(LedDriver, OutOfBoundsTurnOnNothing)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(3141);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualleds);
}
TEST(LedDriver, OutOfBoundsTurnOffNothing)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualleds);
}
TEST(LedDriver, OutOfBoundsProduceRuntimeError)
{
    LedDriver_TurnOff(0);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",
        RuntimeErrorStub_GetLastError());
}
TEST(LedDriver, IsOn)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}
TEST(LedDriver, IsOff)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_FALSE(LedDriver_IsOff(11));
    LedDriver_TurnOff(11);
    TEST_ASSERT_TRUE(LedDriver_IsOff(11));
}
TEST(LedDriver, OutOfBoundsAlwaysFalse)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));
}


