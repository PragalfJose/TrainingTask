//******************************* appLed **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appLed.h
// Summary  : LED related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 24/07/2025
//
//*****************************************************************************
#ifndef _APP_LED_H
#define _APP_LED_H

//******************************* Include Files *******************************
#include <stdbool.h>
#ifdef _RPIBOARD
#include <gpiod.h>
#endif /*_RPIBOARD*/

#include "Console.h"
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define LED_ON                  1
#define LED_OFF                 0
#define LED_PIN                 21               // Connected pin number
#ifdef _RPIBOARD
#define LED_NAME                "Rpi_Led"
#define SW_NAME                 "Rpi_Switch"
#define GPIO_CHIP               "gpiochip0"
#define GPIO_LED                21
#define GPIO_SWITCH             21
#endif /*_RPIBOARD*/

//***************************** Global Variables ******************************

//**************************** Function Declarations **************************

#ifdef _RPIBOARD
bool appLedRpiGpioInit(void);
bool appLedRpiGetChipName(void);
bool appLedRpiGetLineNumber(void);
bool appLedRpiReleaseChip(void);
bool appLedRpiSetGpioOutput(uint16 unPinNumber);
bool appLedRpiSetGpioInput(uint16 unPinNumber);
bool appLedRpiSetGpioPin(uint16 unPinNumber);
bool appLedRpiClearGpioPin(uint16 unPinNumber);
bool appLedRpiCheckGpioPin(uint16 unPinNumber);
#endif /*_RPIBOARD*/

bool appLedStateOn(uint16 unPinNumber);
bool appLedStateOff(uint16 unPinNumber);
bool appLedStateToggle(uint16 unPinNumber);

//*********************** Inline Method Implementations ***********************

#endif // _APP_LED_H
// EOF