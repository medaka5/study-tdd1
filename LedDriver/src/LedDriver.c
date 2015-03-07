#include "LedDriver.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

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
    setLedImage(ALL_LEDS_OFF);
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
    setLedImage(ALL_LEDS_ON);
}

void LedDriver_TurnAllOff(void) {
    setLedImage(ALL_LEDS_OFF);
}

