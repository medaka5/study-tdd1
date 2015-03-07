#include "unity.h"
#include "unity_fixture.h"
#include <stdio.h>

TEST_GROUP(sprintf);
TEST_SETUP(sprintf)
{
}
TEST_TEAR_DOWN(sprintf)
{
}
TEST(sprintf, NoFormatOperations)
{
	char output[5];
	TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
	TEST_ASSERT_EQUAL_STRING("hey", output);
}
