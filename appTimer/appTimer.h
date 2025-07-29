//****************************** appTimer *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appTimer.h
// Summary  : Timer related functions
// Note     : None
// Author   : Pragalf T Jose
// Date     : 22/07/2025
//
//*****************************************************************************
#ifndef _APP_TIMER_H
#define _APP_TIMER_H

//******************************* Include Files *******************************
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Common.h"
#include "Console.h"

//******************************* Global Types ********************************
typedef enum 
{
    TIMEZONE_GMT,
    TIMEZONE_IST,
    TIMEZONE_PST
} TIMEZONE_SELECT;

//***************************** Global Constants ******************************
#define NULL_VALUE              0
#define YEAR_OFFSET             1900
#define MONTH_OFFSET            1
#define WEEK_DAY_OFFSET         1
#define HOUR_OFFSET             12
#define MAX_COUNT_VALUE         2500000
#define MS_COUNT_VALUE          1000
// GMT + 5hr 30minutes is GST
#define IST_OFFSET              19800              //05hr 30 minutes to seconds
// GMT - 07hr 00 minutes is PST
#define PST_OFFSET              25200              //07hr 00 minutes to seconds
#define MIN_TIMEZONE            0
#define MAX_TIMEZONE            2

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************

bool appTimerGetEpochTime(uint32 *pulSeconds);
bool appTimerGetGMTTime(uint32 ulSeconds);
bool appTimerGetISTTime(uint32 ulSeconds);
bool appTimerGetPSTTime(uint32 ulSeconds);
bool appTimerConvertTimeToString(struct tm* pstCurrentTime,
                                 uint8 *pucCurrentDateString,
                                 uint8 *pucCurrentTimeString);
bool appTimerDisplayTime( struct tm *pstCurrentTime, TIMEZONE_SELECT zone);
bool appTimerEpochTImeDisplay(int32 ulSeconds);
void appTimerDelay(int32 lSeconds);
void appTimerProcessTime(void);

#endif // _APP_TIMER_H
// EOF

