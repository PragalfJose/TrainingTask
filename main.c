//**************************** ProjectConsole *********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : main.c
// Summary  : Scan and print a string
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

//******************************* Global Types ********************************

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//******************************.main.*****************************************
//Purpose   : Main function
//Inputs    : None
//Outputs   : None
//Return    : None
//Notes     : Scan a string from console and print it in output terminal
//*****************************************************************************
int main()
{
    // variables decleared here
    uint8 pucInputString[STRING_SIZE] = {0};

    memset(pucInputString, 0x00, sizeof(pucInputString));
    consolePrint("Enter a string");
    scanf("%63[^\n]s", (char *)pucInputString);
    consolePrint("Input string : ");
    consolePrint(pucInputString);

    return 0;
    
}