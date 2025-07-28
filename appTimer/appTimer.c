//****************************** appTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appTimer.c
// Summary  : Timer related functions
// Note     : Timer related functions to fetch and process time from system
// Author   : Pragalf T Jose
// Date     : 22/07/2025
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

//*****************************.appTimerGetGMTTime.****************************
//Purpose   : Get GMT time from epoch value
//Inputs    : pulSeconds - Epoch time 
//Outputs   : None
//Return    : true - Epoch time converted to GMT time
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetGMTTime(uint32 pulSeconds)
{
    bool blReturn = false;
    uint8 pucTimeString[STRING_SIZE] = {0};
    uint8 pucDateString[STRING_SIZE] = {0};
    uint8 pucOutputString[MAX_STRING_SIZE] = {0};
    struct tm *pstCurrentTime = NULL;

    if(pulSeconds != NULL_VALUE)
    {
        pstCurrentTime = gmtime((time_t*)(&pulSeconds));

        if(pstCurrentTime != NULL)
        {
            appTimerConvertTimeToString(pstCurrentTime, 
                                        pucDateString, 
                                        pucTimeString);
            sprintf((char*)pucOutputString, 
                    "Time : %s\r\nDate : %s\r\nEpoch: %u\r\n\r\n", 
                    pucTimeString, 
                    pucDateString, 
                    pulSeconds);
            consolePrint((uint8*)"UTC (0:00)\r\n-------------\r\n");
            consolePrint(pucOutputString);
            blReturn = true;
        }
    }

    return blReturn;

}

//*****************************.appTimerGetISTTime.****************************
//Purpose   : Get IST time from epoch value
//Inputs    : pulSeconds - Epoch time 
//Outputs   : None
//Return    : true - Epoch time converted to IST time
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetISTTime(uint32 pulSeconds)
{
    bool blReturn = false;
    uint8 pucTimeString[STRING_SIZE] = {0};
    uint8 pucDateString[STRING_SIZE] = {0};
    uint8 pucOutputString[MAX_STRING_SIZE] = {0};
    uint32 ulTemperoryEpoch = 0;
    struct tm *pstCurrentTime = NULL;
    
    if(pulSeconds != NULL_VALUE)
    {
        ulTemperoryEpoch = pulSeconds + IST_OFFSET;
        pstCurrentTime = gmtime((time_t*)&ulTemperoryEpoch);

        if((pstCurrentTime != NULL))
        {
            appTimerConvertTimeToString(pstCurrentTime, 
                                        pucDateString, 
                                        pucTimeString);
            sprintf((char*)pucOutputString, 
                    "Time : %s\r\nDate : %s\r\n\r\n", 
                    pucTimeString, 
                    pucDateString);
            consolePrint((uint8*)"IST (+05:30)\r\n-------------\r\n");
            consolePrint(pucOutputString);
            blReturn = true;
        }
    }

    return blReturn;

}

//*****************************.appTimerGetPSTTime.****************************
//Purpose   : Get PST time from epoch value
//Inputs    : pulSeconds - Epoch time 
//Outputs   : None
//Return    : true - Epoch time converted to PST time
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetPSTTime(uint32 pulSeconds)
{
    bool blReturn = false;
    uint8 pucTimeString[STRING_SIZE] = {0};
    uint8 pucDateString[STRING_SIZE] = {0};
    uint8 pucOutputString[MAX_STRING_SIZE] = {0};
    uint32 ulTemperoryEpoch = 0;
    struct tm *pstCurrentTime = NULL;

    if(pulSeconds != NULL_VALUE)
    {
        ulTemperoryEpoch = pulSeconds - PST_OFFSET;
        pstCurrentTime = gmtime((time_t*)&ulTemperoryEpoch);

        if((pstCurrentTime != NULL))
        {
            appTimerConvertTimeToString(pstCurrentTime, 
                                        pucDateString, 
                                        pucTimeString);
            sprintf((char*)pucOutputString, 
                    "Time : %s\r\nDate : %s\r\n\r\n", 
                    pucTimeString, 
                    pucDateString);
            consolePrint((uint8*)"PST (-07:00)\r\n-------------\r\n");
            consolePrint(pucOutputString);
            blReturn = true;
        }
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
    uint8 pucHourOffsetString[MIN_STRING_SIZE] = {0};

    if((pstCurrentTime != NULL) && 
       (pucCurrentDateString != NULL) && 
       (pucCurrentTimeString != NULL))
    {
        sprintf((char*)pucCurrentDateString, "%02d/%02d/%04d", 
                pstCurrentTime->tm_mday, 
                pstCurrentTime->tm_mon, 
                pstCurrentTime->tm_year);

        if(pstCurrentTime->tm_hour >= HOUR_OFFSET)
        {
            sprintf((char*)pucHourOffsetString,"PM");
        }
        else
        {
            sprintf((char*)pucHourOffsetString,"AM");
        }
        if(pstCurrentTime->tm_hour > HOUR_OFFSET)
        {
            pstCurrentTime->tm_hour -= HOUR_OFFSET;
        }

        sprintf((char*)pucCurrentTimeString, "%02d:%02d:%02d %s", 
                    pstCurrentTime->tm_hour, 
                    pstCurrentTime->tm_min, 
                    pstCurrentTime->tm_sec, 
                    pucHourOffsetString);
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
void appTimerDelay(int32 lSeconds)
{
    int32 lStartTime = 0;
    lStartTime = clock();

    while ((clock()) < ((lStartTime) + (lSeconds * CLOCKS_PER_SEC)))
    {

    }
}

//**************************.appTimerProcessTime.******************************
//Purpose   : Fetch epoch time and process to GMT, IST and PST
//Inputs    : None
//Outputs   : None 
//Outputs   : None
//Return    : None
//Notes     : None
//*****************************************************************************
void appTimerProcessTime(void)
{
    uint32 ulEpochSec = 0;
    uint32 ulEpochTime = 0;
    if(appTimerGetEpochTime(&ulEpochSec))
    {
        ulEpochTime = ulEpochSec;
        printf("Time : %u\r\n",ulEpochTime);
        appTimerGetGMTTime(ulEpochTime);
        appTimerGetISTTime(ulEpochTime);
        appTimerGetPSTTime(ulEpochTime);
    }
}

// EOF

