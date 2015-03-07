#include "LedDriver.h"

static uint16_t *ledAddress;
static uint16_t convertLedNumberToBit(unsigned int ledNumber) {
    return 1 << (ledNumber - 1);
}

void LedDriver_Create(uint16_t *address){
    ledAddress = address;
    *address = 0;
}

void LedDriver_Destroy(void) {
}
void LedDriver_TurnOn(unsigned int ledNumber) {
    *ledAddress |= convertLedNumberToBit(ledNumber);
}
void LedDriver_TurnOff(unsigned int ledNumber) {
    *ledAddress &= ~(convertLedNumberToBit(ledNumber));
}
void LedDriver_TurnAllOn(void) {
    *ledAddress = 0xFFFF;
}
