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
#include "Common.h"
#include "Console.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define LED_ON                  1
#define LED_OFF                 0
#define ERR_PIN                 0
#define LED_PIN                 15               // Connected pin number

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************

bool appLedStateOn(uint16 unPinNumber);
bool appLedStateOff(uint16 unPinNumber);
bool appLedStateToggle(uint16 unPinNumber);

#endif // _APP_LED_H
// EOF