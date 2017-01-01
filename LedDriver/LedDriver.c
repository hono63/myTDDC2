
#include "LedDriver.h"

enum{
    ALL_LEDS_ON = 0xffff,
    ALL_LEDS_OFF = 0,
};

enum{
    FIRST_LED = 1,
    LAST_LED = 16,
};

static uint16_t  ledsImage;
static uint16_t* ledsAddress;

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static bool isLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void updateHW()
{
    *ledsAddress = ledsImage;
}

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

// global関数実装

void LedDriver_Create(uint16_t* Leds)
{
    ledsImage = ALL_LEDS_OFF;
    ledsAddress = Leds;
    *Leds = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
    if( !isLedOutOfBounds(ledNumber) ){
        setLedImageBit(ledNumber);
        updateHW();
    }
}

void LedDriver_TurnOff(int ledNumber)
{
    if( !isLedOutOfBounds(ledNumber) ){
        clearLedImageBit(ledNumber);
        updateHW();
     }
}

void LedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHW();
}

bool LedDriver_isON(int ledNumber)
{
    return (bool)(ledsImage & convertLedNumberToBit(ledNumber));
}