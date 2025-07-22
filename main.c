//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : main.c
// Summary  : Get system time a print
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
#include <windows.h>

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//******************************.main.*****************************************
//Purpose   : Main function
//Inputs    : None
//Outputs   : None
//Return    : None
//Notes     : Get sytem time and print it in GMT, IST and PST
//*****************************************************************************
int main()
{
    // variables decleared here
    // uint8 pucOutputString[STRING_SIZE] = {0};
    uint8 pucISTTimeString[STRING_SIZE] = {0};
    uint8 pucGMTTimeString[STRING_SIZE] = {0};
    uint8 pucPSTTimeString[STRING_SIZE] = {0};
    uint8 pucISTDateString[STRING_SIZE] = {0};
    uint8 pucGMTDateString[STRING_SIZE] = {0};
    uint8 pucPSTDateString[STRING_SIZE] = {0};
    uint8 pucEpochTimeString[STRING_SIZE] = {0};
    struct tm sCurrentISTTime = {0};
    struct tm sCurrentGMTTime = {0};
    struct tm sCurrentPSTTime = {0};
    uint32 uiEpochTime = 0;
    uint32 uiTemporaryEpochTime = 0;

    while(1)
    {
        appTimerGetEpochTime(&uiEpochTime);
        sprintf(pucEpochTimeString, "Epoch: %u", uiEpochTime);
        appTimerGetLocalTime(&uiEpochTime, &sCurrentISTTime);
        uiTemporaryEpochTime = uiEpochTime - GMT_OFFSET;
        appTimerGetLocalTime(&uiTemporaryEpochTime, &sCurrentGMTTime);
        uiTemporaryEpochTime = uiEpochTime - PST_OFFSET;
        appTimerGetLocalTime(&uiTemporaryEpochTime, &sCurrentPSTTime);
        appTimerConvertTimeToString(&sCurrentISTTime, 
                                    pucISTDateString, 
                                    pucISTTimeString);
        appTimerConvertTimeToString(&sCurrentGMTTime, 
                                    pucGMTDateString, 
                                    pucGMTTimeString);
        appTimerConvertTimeToString(&sCurrentPSTTime, 
                                    pucPSTDateString, 
                                    pucPSTTimeString);

        consolePrint("UTC (0:00)\r\n");
        consolePrint("-------------\r\n");
        consolePrint("Time : ");
        consolePrint(pucGMTTimeString);
        consolePrint("\r\n");
        consolePrint("Date : ");
        consolePrint(pucGMTDateString);
        consolePrint("\r\n");
        consolePrint(pucEpochTimeString);
        consolePrint("\r\n\r\n");
        consolePrint("IST (+05:30)\r\n");
        consolePrint("-------------\r\n");
        consolePrint("Time : ");
        consolePrint(pucISTTimeString);
        consolePrint("\r\n");
        consolePrint("Date : ");
        consolePrint(pucISTDateString);
        consolePrint("\r\n\r\n");
        consolePrint("IST (-07:00)\r\n");
        consolePrint("-------------\r\n");
        consolePrint("Time : ");
        consolePrint(pucPSTTimeString);
        consolePrint("\r\n");
        consolePrint("Date : ");
        consolePrint(pucPSTDateString);
        consolePrint("\r\n\r\n");
        appTimerDelay(1);
    }

    return 0;
    
}