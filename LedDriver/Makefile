
UNITY_ROOT=$(HOME)/tools/Unity
UNITY_SRC=$(UNITY_ROOT)/src/unity.c $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c
UNITY_INC=-I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src


TARGET=all_tests

SRC_FILES1=$(UNITY_SRC) test/LedDriverTest.c test/LedDriverTestRunner.c test/all_tests.c src/LedDriver.c mocks/RuntimeErrorStub.c

all:
	$(CC) $(CFLAGS) $(UNITY_INC) -Isrc -Imocks -Iinclude $(SRC_FILES1) -o $(TARGET)
	./$(TARGET)


