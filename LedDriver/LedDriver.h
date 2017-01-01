#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include "type.h"

void LedDriver_Create(uint16_t* Leds);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn();
bool LedDriver_isON(int ledNumber);

#endif /* _LED_DRIVER_H_ */