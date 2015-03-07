#include "LedDriver.h"

static uint16_t *ledAddress;

static uint16_t ledImage;

static uint16_t convertLedNumberToBit(unsigned int ledNumber) {
    return 1 << (ledNumber - 1);
}

static void setLedImage(uint16_t newLedImage) {
    ledImage = newLedImage;
    *ledAddress = ledImage;
}

void LedDriver_Create(uint16_t *address){
    ledAddress = address;
    setLedImage(0);
}

void LedDriver_Destroy(void) {
}
void LedDriver_TurnOn(unsigned int ledNumber) {
    uint16_t newLedImage = (ledImage |= convertLedNumberToBit(ledNumber));
    setLedImage(newLedImage);
}
void LedDriver_TurnOff(unsigned int ledNumber) {
    uint16_t newLedImage = (ledImage &= ~(convertLedNumberToBit(ledNumber)));
    setLedImage(newLedImage);
}
void LedDriver_TurnAllOn(void) {
    setLedImage(0xFFFF);
}

