//**************************** TRAINIGTASK ************************************
// Copyright (c) 2025 Trenser
// All Rights Reserved
//*****************************************************************************
//
// File     : main.c
// Summary  : Program to familiar with coding standards and basic HIT 
//            operations
// Note     : Simple program to print hello world with multiple file
// Author   : Pragalf T Jose
// Date     : 21/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Global.h"
#include "PrintFunction.h"

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************

//***************************** Class Declaration *****************************

//*********************** Inline Method Implementations ***********************

//******************************.main.**********************************
//Purpose   : Main function
//Inputs    : None
//Outputs   : None
//Return    : None
//Notes     : 
//*****************************************************************************
int main()
{
    // variables decleared here
    uint8 pucInputString[STRING_SIZE] = {0};

    memset(pucInputString, 0x00, sizeof(pucInputString));
    PrintString("Enter a string Here");
    scanf("%63[^\n]s", (char *)pucInputString);
    PrintString("Input string is : ");
    PrintString(pucInputString);

    return 0;
    
}