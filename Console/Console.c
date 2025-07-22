//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : Console.c
// Summary  : Includes function to output data to terminal
// Note     : None
// Author   : Pragalf T Jose
// Date     : 21/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "Console.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//******************************.PrintString.**********************************
//Purpose   : Print an input string
//Inputs    : pucInputString - Input string to print
//Outputs   : None
//Return    : true - print success, false - invalid argument
//Notes     : None
//*****************************************************************************
bool consolePrint(uint8 *pucInputString)
{
    bool blReturn = false;

    if(pucInputString != NULL)
    {
        printf("%s\r\n", pucInputString);
        blReturn = true;
    }

    return blReturn;
}

// EOF