//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary  : Console input / output related functions 
// Note     : None
// Author   : Pragalf T Jose
// Date     : 21/07/2025
//
//*****************************************************************************
#ifndef _CONSOLE_H
#define _CONSOLE_H

//******************************* Include Files *******************************
#include <stdio.h>
#include <stdbool.h>
#include "Common.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************
#define STRING_SIZE         64

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************

bool consolePrint(uint8 *pucInputString);

#endif // _CONSOLE_H
// EOF