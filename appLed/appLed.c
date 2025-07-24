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
uint8 uiLedStaus = 0;

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
    if(uiPinNumber != 0)
    {
        consolePrint("LED ON\r\n");
        uiLedStaus = 1;
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
    if(uiPinNumber != 0)
    {
        consolePrint("LED OFF\r\n");
        uiLedStaus = 0;
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
    if(uiPinNumber != 0)
    {
        if(LED_OFF == uiLedStaus)
        {
            appLedStateOn(uiPinNumber);
        }
        else if(LED_ON == uiLedStaus)
        {
            appLedStateOff(uiPinNumber);
        }

        blReturn = true;
    }

    return blReturn;

}

// EOF