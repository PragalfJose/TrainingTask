//**************************** TRAINIGTASK ************************************
// Copyright (c) 2025 Trenser
// All Rights Reserved
//*****************************************************************************
//
// File     : PrintFunction.c
// Summary  : Write a program to familiar with coding standards and basic GIT 
//            operations
// Note     : Simple program to print hello world with multiple file
// Author   : Pragalf T Jose
// Date     : 21/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "PrintFunction.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//*********************** Class Method Implementations ************************

//******************************.PrintString.**********************************
//Purpose   : Print an input string
//Inputs    : pucInputString - Input string to print
//Outputs   : None
//Return    : true - print success, false - invalid argument
//Notes     : 
//*****************************************************************************
bool PrintString(uint8 *pucInputString)
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