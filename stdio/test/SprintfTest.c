#include "unity.h"
#include "unity_fixture.h"
#include <stdio.h>
#include <string.h>


TEST_GROUP(sprintf);

static char output[150];
static const char *expected;
TEST_SETUP(sprintf)
{
	memset(output, 0xaa, sizeof(output));
	expected="";
}
TEST_TEAR_DOWN(sprintf)
{
}
static void expect(const char *s)
{
	expected=s;
}
static void given(int charsWitten)
{
	size_t expected_size = strlen(expected);
	TEST_ASSERT_EQUAL(expected_size, charsWitten);
	TEST_ASSERT_EQUAL_STRING(expected, output);
	TEST_ASSERT_BYTES_EQUAL(0xaa, output[expected_size + 1]);
}
TEST(sprintf, NoFormatOperations)
{
	expect("hey");
	given(sprintf(output, "hey"));
}
TEST(sprintf, InsertString)
{
	expect("Hello World\n");
	given(sprintf(output, "Hello %s\n", "World"));
}
