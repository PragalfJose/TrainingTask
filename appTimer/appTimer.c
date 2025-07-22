//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File 	: appTimer.c
// Summary 	: Timer related functions
// Note 	: Timer related functions to fetch and process time from system
// Author 	: Pragalf T Jose
// Date 	: 22/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "appTimer.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//****************************.appTimerGetEpochTime.***************************
//Purpose   : Get system epoch time
//Inputs    : None
//Outputs   : pulSeconds - Epoch time value in seconds 
//Return    : true - got epoch time, false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetEpochTime(uint32 *pulSeconds)
{
    bool blReturn = false;

    if(pulSeconds != NULL)
    {
        time((time_t*)pulSeconds);
        blReturn = true;
    }

    return blReturn;

}

//****************************.appTimerGetLocalTime.***************************
//Purpose   : Get system IST from epoch value
//Inputs    : pulSeconds - Epoch time 
//Outputs   : pstCurrentLocalTime - structure with time and date in IST
//Return    : true - Epoch time converted to local time
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetLocalTime(uint32 *pulSeconds, struct tm *pstCurrentLocalTime)
{
    bool blReturn = false;
    struct tm *pstCurrentTime = NULL;

    pstCurrentTime = localtime((time_t*)pulSeconds);

    if((pulSeconds != NULL) && 
       (pstCurrentLocalTime != NULL) &&
       (pstCurrentTime != NULL))
    {
        pstCurrentLocalTime->tm_year = pstCurrentTime->tm_year + YEAR_OFFSET;
        pstCurrentLocalTime->tm_mon  = pstCurrentTime->tm_mon + MONTH_OFFSET;
        pstCurrentLocalTime->tm_wday = pstCurrentTime->tm_wday + WEEK_DAY_OFFSET;
        pstCurrentLocalTime->tm_mday = pstCurrentTime->tm_mday;
        pstCurrentLocalTime->tm_hour = pstCurrentTime->tm_hour;
        pstCurrentLocalTime->tm_min  = pstCurrentTime->tm_min;
        pstCurrentLocalTime->tm_sec  = pstCurrentTime->tm_sec;
        blReturn = true;
    }

    return blReturn;

}

//************************.appTimerConvertTimeToString.************************
//Purpose   : Convert time to a string
//Inputs    : pstCurrentTime  - Current time structure
//Outputs   : pucCurrentDate - Current date in string 
//Outputs   : pucCurrentTime - Current time in string 
//Return    : true  - Struct tm values converted to string
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerConvertTimeToString(struct tm* pstCurrentTime,
                                 uint8 *pucCurrentDateString,
                                 uint8 *pucCurrentTimeString)
{
    bool blReturn = false;

    if((pstCurrentTime != NULL) && 
       (pucCurrentDateString != NULL) && 
       (pucCurrentTimeString != NULL))
    {
        sprintf(pucCurrentDateString, "%02d/%02d/%04d", 
                pstCurrentTime->tm_mday, 
                pstCurrentTime->tm_mon, 
                pstCurrentTime->tm_year);

        if(pstCurrentTime->tm_hour >= HOUR_OFFSET)
        {
            pstCurrentTime->tm_hour -= HOUR_OFFSET;
            sprintf(pucCurrentTimeString, "%02d:%02d:%02d PM", 
                    pstCurrentTime->tm_hour, 
                    pstCurrentTime->tm_min, 
                    pstCurrentTime->tm_sec);
        }
        else
        {
            sprintf(pucCurrentTimeString, "%02d:%02d:%02d AM", 
                    pstCurrentTime->tm_hour, 
                    pstCurrentTime->tm_min, 
                    pstCurrentTime->tm_sec);
        }
    }

    return blReturn;
}

//****************************.appTimerDelay.**********************************
//Purpose   : Create a dealy
//Inputs    : ulSeconds - Delay needed in Seconds
//Outputs   : None 
//Return    : None
//Notes     : None
//*****************************************************************************
void appTimerDelay(uint32 ulSeconds)
{
    uint32 ulStartTime = 0;
    ulStartTime = (uint32)clock();

    while ((clock()) < ((ulStartTime) + (ulSeconds * CLOCKS_PER_SEC)))
    {

    }
}

//***************************.appTimerDisplay.*********************************
//Purpose   : Display system Time
//Inputs    : None
//Outputs   : None 
//Outputs   : None
//Return    : None
//Notes     : Used only for approximate values of dealy. Not accurate
//*****************************************************************************
void appTimerDisplay(void)
{
    uint8 pucTimeString[STRING_SIZE] = {0};
    uint8 pucDateString[STRING_SIZE] = {0};
    uint8 pucEpochTimeString[STRING_SIZE] = {0};
    uint8 pucOutputString[MAX_STRING_SIZE] = {0};
    struct tm stCurrentTime = {0};
    uint32 ulEpochTime = 0;
    uint32 ulTemporaryEpochTime = 0;

    appTimerGetEpochTime(&ulEpochTime);
    sprintf(pucEpochTimeString, "Epoch: %u", ulEpochTime);

    ulTemporaryEpochTime = ulEpochTime - GMT_OFFSET;
    appTimerGetLocalTime(&ulTemporaryEpochTime, &stCurrentTime);
    appTimerConvertTimeToString(&stCurrentTime, 
                                pucDateString, 
                                pucTimeString);
    sprintf(pucOutputString, 
          "Time : %s\r\nDate : %s\r\nEpoch: %s\r\n\r\n", 
          pucTimeString, 
          pucDateString, 
          pucEpochTimeString);
    consolePrint("UTC (0:00)\r\n-------------\r\n");
    consolePrint(pucOutputString);

    appTimerGetLocalTime(&ulEpochTime, &stCurrentTime);
    appTimerConvertTimeToString(&stCurrentTime, 
                                pucDateString, 
                                pucTimeString);
    sprintf(pucOutputString, 
          "Time : %s\r\nDate : %s\r\n\r\n", 
          pucTimeString, 
          pucDateString);
    consolePrint("IST (+05:30)\r\n-------------\r\n");
    consolePrint(pucOutputString);

    ulTemporaryEpochTime = ulEpochTime - PST_OFFSET;
    appTimerGetLocalTime(&ulTemporaryEpochTime, &stCurrentTime);
    appTimerConvertTimeToString(&stCurrentTime, 
                                pucDateString, 
                                pucTimeString);
    sprintf(pucOutputString, 
          "Time : %s\r\nDate : %s\r\n\r\n", 
          pucTimeString, 
          pucDateString);
    consolePrint("PST (+07:00)\r\n-------------\r\n");
    consolePrint(pucOutputString);
}

// EOF

