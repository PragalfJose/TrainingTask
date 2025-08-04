//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : main.c
// Summary  : Fetch and process system time and print. Also toggle LED state
// Note     : None
// Author   : Pragalf T Jose
// Date     : 21/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdlib.h>
#include <string.h>
#include "Common.h"
#include "Console.h"
#include "appTimer.h"
#include "appLed.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//******************************.main.*****************************************
//Purpose   : Fetch and process time from system
//Inputs    : None
//Outputs   : None
//Return    : None
//Notes     : Get sytem time and print it in GMT, IST and PST
//*****************************************************************************
int main()
{
    #ifdef _RPIBOARD
    bool bReturnStatus = false;
    
    bReturnStatus = appLedRpiGpioInit();
    if(bReturnStatus == false)
    {
        consolePrint((uint8*)"GPIO Initialistion Failed\r\n");
    }
    else
    {
        bReturnStatus = appLedRpiSetGpioOutput(LED_PIN);
        if(bReturnStatus == false)
        {
            consolePrint((uint8*)"GPIO Direction set Failed\r\n");
        }
    }
    #endif /*_RPIBOARD*/

    while(true)
    {
        appTimerProcessTime();
        appLedStateOn(LED_PIN);
        appTimerDelay(840);
        appLedStateOff(LED_PIN);
        appTimerDelay(532);
    }

    #ifdef _RPIBOARD
    appLedRpiReleaseChip();
    #endif /*_RPIBOARD*/

    return 0;
    
}