#include "LedDriver.h"
#include "RuntimeError.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};

static uint16_t *ledAddress;
static uint16_t ledImage;


static uint16_t convertLedNumberToBit(unsigned int ledNumber) {
    return 1 << (ledNumber - 1);
}
static int IsLedOutOfBounds(uint16_t ledNumber) {
    int ret = (ledNumber < FIRST_LED) || (ledNumber > LAST_LED );
    if (ret) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
    }
    return ret;
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
    if(IsLedOutOfBounds(ledNumber)) {
        return;
    }
    uint16_t newLedImage = (ledImage |= convertLedNumberToBit(ledNumber));
    setLedImage(newLedImage);
}
void LedDriver_TurnOff(unsigned int ledNumber) {
    if(IsLedOutOfBounds(ledNumber)) {
        return;
    }
    uint16_t newLedImage = (ledImage &= ~(convertLedNumberToBit(ledNumber)));
    setLedImage(newLedImage);
}
void LedDriver_TurnAllOn(void) {
    setLedImage(ALL_LEDS_ON);
}

void LedDriver_TurnAllOff(void) {
    setLedImage(ALL_LEDS_OFF);
}
int LedDriver_IsOn(unsigned int ledNumber) {
    if(IsLedOutOfBounds(ledNumber)) {
        return 0;
    }
    return (ledImage & convertLedNumberToBit(ledNumber));
}
int LedDriver_IsOff(unsigned int ledNumber) {
    return !(LedDriver_IsOn(ledNumber));
}
