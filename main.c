//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : main.c
// Summary  : Get system time and print
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
    // variables decleared here
    // uint8 pucOutputString[STRING_SIZE] = {0};

    while(true)
    {
        appTimerDisplay();
        appTimerDelay(1);
    }

    return 0;
    
}