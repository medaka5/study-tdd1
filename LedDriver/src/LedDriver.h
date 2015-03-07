#include <stdint.h>


extern void LedDriver_Create(uint16_t *address);
extern void LedDriver_Destroy(void);
extern void LedDriver_TurnOn(unsigned int ledNumber);
extern void LedDriver_TurnOff(unsigned int ledNumber);
extern void LedDriver_TurnAllOn(void);
