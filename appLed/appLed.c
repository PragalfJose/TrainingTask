//******************************* appLed **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appLed.c
// Summary  : LED controlling functions
// Note     : Function to control state of an LED
// Author   : Pragalf T Jose
// Date     : 24/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "appLed.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
uint8 ucLedStaus = LED_OFF;

//****************************** Local Functions ******************************

//*******************************.appLedStateOn.*******************************
//Purpose   : Turn ON the Led
//Inputs    : uiPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateOn(uint16 uiPinNumber)
{
    bool blReturn = false;
    if(uiPinNumber != ERR_PIN)
    {
        consolePrint("LED ON\r\n");
        ucLedStaus = LED_ON;
        blReturn = true;
    }

    return blReturn;
}

//******************************.appLedStateOff.*******************************
//Purpose   : Turn OFF the Led
//Inputs    : uiPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateOff(uint16 uiPinNumber)
{
    bool blReturn = false;
    if(uiPinNumber != ERR_PIN)
    {
        consolePrint("LED OFF\r\n");
        ucLedStaus = LED_OFF;
        blReturn = true;
    }

    return blReturn;
}

//*****************************.appLedStateToggle.*****************************
//Purpose   : Toggle current state of the Led
//Inputs    : uiPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateToggle(uint16 uiPinNumber)
{
    bool blReturn = false;
    if(uiPinNumber != ERR_PIN)
    {
        if(LED_OFF == ucLedStaus)
        {
            appLedStateOn(uiPinNumber);
        }
        else if(LED_ON == ucLedStaus)
        {
            appLedStateOff(uiPinNumber);
        }

        blReturn = true;
    }

    return blReturn;

}

// EOF