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
//Outputs   : uiSeconds - Epoch time value in seconds 
//Return    : true - got epoch time, false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetEpochTime(uint32 *puiSeconds)
{
    bool blReturn = false;

    if(puiSeconds != NULL)
    {
        time((time_t*)puiSeconds);
        blReturn = true;
    }

    return blReturn;

}

//****************************.appTimerGetLocalTime.***************************
//Purpose   : Get system IST from epoch value
//Inputs    : puiSeconds - Epoch time 
//Outputs   : sCurrentLocalTime - structure with time and date in IST
//Return    : true - Epoch time converted to local time
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerGetLocalTime(uint32 *puiSeconds, struct tm *sCurrentLocalTime)
{
    bool blReturn = false;
    struct tm *sCurrentTime = NULL;

    sCurrentTime = localtime((time_t*)puiSeconds);

    if(puiSeconds != NULL && sCurrentLocalTime != NULL && sCurrentTime != NULL)
    {
        sCurrentLocalTime->tm_year = sCurrentTime->tm_year + YEAR_OFFSET;
        sCurrentLocalTime->tm_mon  = sCurrentTime->tm_mon + MONTH_OFFSET;
        sCurrentLocalTime->tm_wday = sCurrentTime->tm_wday + WEEK_DAY_OFFSET;
        sCurrentLocalTime->tm_mday = sCurrentTime->tm_mday;
        sCurrentLocalTime->tm_hour = sCurrentTime->tm_hour;
        sCurrentLocalTime->tm_min  = sCurrentTime->tm_min;
        sCurrentLocalTime->tm_sec  = sCurrentTime->tm_sec;
        blReturn = true;
    }

    return blReturn;

}

//************************.appTimerConvertTimeToString.************************
//Purpose   : Convert time to a string
//Inputs    : psCurrentTime  - Current time structure
//Outputs   : pucCurrentDate - Current date in string 
//Outputs   : pucCurrentTime - Current time in string 
//Return    : true  - Struct tm values converted to string
//Return    : false - invalid argument
//Notes     : None
//*****************************************************************************
bool appTimerConvertTimeToString(struct tm* psCurrentTime,
                                 uint8 *pucCurrentDateString,
                                 uint8 *pucCurrentTimeString)
{
    bool blReturn = false;

    if(psCurrentTime != NULL && 
       pucCurrentDateString != NULL && 
       pucCurrentTimeString != NULL)
    {
        sprintf(pucCurrentDateString, "%02d/%02d/%04d", 
                psCurrentTime->tm_mday, 
                psCurrentTime->tm_mon, 
                psCurrentTime->tm_year);

        if(psCurrentTime->tm_hour >= HOUR_OFFSET)
        {
            psCurrentTime->tm_hour -= HOUR_OFFSET;
            sprintf(pucCurrentTimeString, "%02d:%02d:%02d PM", 
                    psCurrentTime->tm_hour, 
                    psCurrentTime->tm_min, 
                    psCurrentTime->tm_sec);
        }
        else
        {
            sprintf(pucCurrentTimeString, "%02d:%02d:%02d AM", 
                    psCurrentTime->tm_hour, 
                    psCurrentTime->tm_min, 
                    psCurrentTime->tm_sec);
        }
    }

    return blReturn;
}

//****************************.appTimerDelay.**********************************
//Purpose   : Create a dealy
//Inputs    : uiSeconds - Delay needed in Seconds
//Outputs   : None 
//Outputs   : None 
//Return    : None
//Notes     : Used only for approximate values of dealy. Not accurate
//*****************************************************************************
void appTimerDelay(uint32 uiSeconds)
{
    uint32 uiCountValue1 = 0;
    uint32 uiCountValue2 = 0;
    uint32 uiCountValue3 = 0;
    
    for(uiCountValue3 = 0; uiCountValue3 < uiSeconds; uiCountValue3++)
    {
        for(uiCountValue1 = 0; uiCountValue1 < MS_COUNT_VALUE; uiCountValue1++)
        {
            for(uiCountValue2 = 0; 
                uiCountValue2 < MAX_COUNT_VALUE; 
                uiCountValue2++)
            {

            }
        }
    }
}

// EOF

