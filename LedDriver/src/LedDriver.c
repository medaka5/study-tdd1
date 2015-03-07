#include "LedDriver.h"

static uint16_t *ledAddress;

void LedDriver_Create(uint16_t *address){
    ledAddress = address;
    *address = 0;
}

void LedDriver_Destroy(void) {
}
void LedDriver_TurnOn(unsigned int ledNumber) {
    *ledAddress = 1;
}