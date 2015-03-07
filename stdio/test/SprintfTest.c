#include "unity.h"
#include "unity_fixture.h"
#include <stdio.h>
#include <string.h>


TEST_GROUP(sprintf);

static char output[150];
TEST_SETUP(sprintf)
{
	memset(output, 0xaa, sizeof(output));
}
TEST_TEAR_DOWN(sprintf)
{
}
TEST(sprintf, NoFormatOperations)
{
	memset(output, 0xaa, sizeof(output));
	TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
	TEST_ASSERT_EQUAL_STRING("hey", output);
	TEST_ASSERT_BYTES_EQUAL(0xaa, output[4]);
}
TEST(sprintf, InsertString)
{
	memset(output, 0xaa, sizeof(output));
	TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
	TEST_ASSERT_EQUAL_STRING("Hello World\n", output);
	TEST_ASSERT_BYTES_EQUAL(0xaa, output[13]);
}
