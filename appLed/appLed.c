//******************************* appLed **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appLed.c
// Summary  : LED controlling functions
// Note     : Function to control state of LED
// Author   : Pragalf T Jose
// Date     : 24/07/2025
//
//*****************************************************************************

//******************************* Include Files *******************************
#include "appLed.h"

//******************************* Local Types *********************************

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************
#ifdef _RPIBOARD
struct gpiod_chip *spChip = NULL;      
struct gpiod_line *spOutputLine = NULL;
struct gpiod_line *spInputLine = NULL;
#endif /* _RPIBOARD*/

uint8 ucLedStaus = LED_OFF;

//****************************** Local Functions ******************************

#ifdef _RPIBOARD
//*****************************.appLedRpiGpioInit.*****************************
//Purpose   : Initialise Gpio chip and Line number
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - Initialisation failed
//Notes     : None
//*****************************************************************************
bool appLedRpiGpioInit(void)
{
    bool blReturn = false;

    if(spChip == NULL && spOutputLine == NULL)
    {
        bool blStatusFlag = false;

        blStatusFlag = appLedRpiGetChipName();
        if(blStatusFlag == true)
        {
            blStatusFlag = appLedRpiGetLineNumber();
            if(blStatusFlag == true)
            {
                if((appLedRpiSetGpioOutput(GPIO_LED) == true) && 
                   (appLedRpiSetGpioInput(GPIO_SWITCH) == true))
                {
                    blReturn = true;
                }
                else
                {
                    consolePrint((uint8*)"Pin Direction Set failed\r\n");
                }
            }
            else
            {
                appLedRpiReleaseChip();
                consolePrint((uint8*)"Pin Allocation failed\r\n");
            }
        }
        else
        {
            consolePrint((uint8*)"Chip Allocation failed\r\n");
        }
    }

    return blReturn;

}

//***************************.appLedRpiGetChipName.****************************
//Purpose   : Get details of GPIO chip
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - Chip open failed
//Notes     : Open a corresponding GPIO chip and returns its address
//*****************************************************************************
bool appLedRpiGetChipName(void)
{
    bool blReturn = false;

    spChip = gpiod_chip_open_by_name(GPIO_CHIP);
    if(spChip != NULL)
    {
        blReturn = true;
    }

    return blReturn;

}

//**************************.appLedRpiGetLineNumber.***************************
//Purpose   : Get details of GPIO pin 
//Inputs    : None
//Outputs   : None
//Return    : true - Success, false - Get line number failed
//Notes     : Open a GPIO line and return its address
//*****************************************************************************
bool appLedRpiGetLineNumber(void)
{
    bool blReturn = false;

    spOutputLine = gpiod_chip_get_line(spChip, GPIO_LED);
    spInputLine = gpiod_chip_get_line(spChip, GPIO_SWITCH);
    if(spOutputLine != NULL && spInputLine != NULL)
    {
        blReturn = true;
    }

    return blReturn;

}

//**************************.appLedRpiReleaseChip.*****************************
//Purpose   : Clear given GPIO chip 
//Inputs    : None
//Outputs   : None
//Return    : true - GPIO chip released, false - Failed
//Notes     : Relase a GPIO chip and its allocated resources
//*****************************************************************************
bool appLedRpiReleaseChip(void)
{
    bool blReturn = false;

    if(spChip != NULL)
    {
        gpiod_chip_close(spChip);
        blReturn = true;
    }

    return blReturn;
}

//**************************.appLedRpiSetGpioOutput.***************************
//Purpose   : Set direction of given GPIO pin to output
//Inputs    : unPinNumber - pin number
//Outputs   : None
//Return    : true - GPIO direction Set, false - Failed
//Notes     : None
//*****************************************************************************
bool appLedRpiSetGpioOutput(uint16 unPinNumber)
{
    bool blReturn = false;

    if((spChip != NULL) && (spOutputLine != NULL) && (GPIO_LED == unPinNumber))
    {
        gpiod_line_release(spOutputLine);
        if(RETURN_OK == gpiod_line_request_output(spOutputLine, LED_NAME, TRUE))
        {
            blReturn = true;
        }
    }
    else
    {
        consolePrint((uint8*)"Invalid Parameters GPIO SET OUTPUT\r\n");
    }

    return blReturn;
}

//**************************.appLedRpiSetGpioInput.****************************
//Purpose   : Set direction of given GPIO pin to input
//Inputs    : unPinNumber - pin number
//Outputs   : None
//Return    : true - GPIO direction Set, false - Failed
//Notes     : None
//*****************************************************************************
bool appLedRpiSetGpioInput(uint16 unPinNumber)
{
    bool blReturn = false;

    if((spChip != NULL) && 
       (spInputLine != NULL) && 
       (GPIO_SWITCH == unPinNumber))
    {
        gpiod_line_release(spInputLine);
        if(RETURN_OK == gpiod_line_request_input(spInputLine, SW_NAME))
        {
            blReturn = true;
        }
    }
    else
    {
        consolePrint((uint8*)"Invalid Parameters GPIO SET INPUT\r\n");
    }

    return blReturn;
}

//***************************.appLedRpiSetGpioPin.*****************************
//Purpose   : Set given GPIO pin
//Inputs    : unPinNumber - pin number
//Outputs   : None
//Return    : true - GPIO Set, false - Failed
//Notes     : None
//*****************************************************************************
bool appLedRpiSetGpioPin(uint16 unPinNumber)
{
    bool blReturn = false;

    if((spChip != NULL) && (spOutputLine != NULL) && (GPIO_LED == unPinNumber))
    {
        if(RETURN_OK == gpiod_line_set_value(spOutputLine, TRUE))
        {
            blReturn = true;
        }
        else
        {
            consolePrint((uint8*)"Led ON failed\r\n");
        }
    }
    else
    {
        consolePrint((uint8*)"Invalid Parameters GPIO SET PIN\r\n");
    }

    return blReturn;
}

//**************************.appLedRpiClearGpioPin.****************************
//Purpose   : Clear given GPIO pin 
//Inputs    : unPinNumber - pin number
//Outputs   : None
//Return    : true - GPIO Clear, false - Failed
//Notes     : None
//*****************************************************************************
bool appLedRpiClearGpioPin(uint16 unPinNumber)
{
    bool blReturn = false;

    if((spChip != NULL) && (spOutputLine != NULL) && (GPIO_LED == unPinNumber))
    {
        if(RETURN_OK == gpiod_line_set_value(spOutputLine, FALSE))
        {
            blReturn = true;
        }
        else
        {
            consolePrint((uint8*)"Led OFF failed\r\n");
        }
    }
    else
    {
        consolePrint((uint8*)"Invalid Parameters GPIO CLEAR PIN\r\n");
    }

    return blReturn;
}

//**************************.appLedRpiCheckGpioPin.****************************
//Purpose   : Check given GPIO pin 
//Inputs    : unPinNumber - pin number
//Outputs   : None
//Return    : true - GPIO High, false - GPIO Low
//Notes     : None
//*****************************************************************************
bool appLedRpiCheckGpioPin(uint16 unPinNumber)
{
    bool blReturn = false;

    if((spChip != NULL) && (spInputLine != NULL) && (GPIO_SWITCH == unPinNumber))
    {
        if(TRUE == gpiod_line_get_value(spOutputLine))
        {
            blReturn = true;
        }
    }
    else
    {
        consolePrint((uint8*)"Invalid Parameters GPIO CLEAR PIN\r\n");
    }

    return blReturn;
}
#endif /* _RPIBOARD*/

//*******************************.appLedStateOn.*******************************
//Purpose   : Turn ON the Led
//Inputs    : unPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateOn(uint16 unPinNumber)
{
    bool blReturn = false;

    if(LED_PIN == unPinNumber)
    {
        #ifdef _RPIBOARD
        appLedRpiSetGpioPin(unPinNumber);
        #endif /*_RPIBOARD*/
        consolePrint((uint8*)"LED ON\r\n");
        ucLedStaus = LED_ON;
        blReturn = true;
    }

    return blReturn;
}

//******************************.appLedStateOff.*******************************
//Purpose   : Turn OFF the Led
//Inputs    : unPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateOff(uint16 unPinNumber)
{
    bool blReturn = false;

    if(LED_PIN == unPinNumber)
    {
        #ifdef _RPIBOARD
        appLedRpiClearGpioPin(unPinNumber);
        #endif /*_RPIBOARD*/
        consolePrint((uint8*)"LED OFF\r\n");
        ucLedStaus = LED_OFF;
        blReturn = true;
    }

    return blReturn;
}

//*****************************.appLedStateToggle.*****************************
//Purpose   : Toggle current state of the Led
//Inputs    : unPinNumber - Pin number which Led is Connected
//Outputs   : None
//Return    : true - Led On, false - Invalid argument
//Notes     : None
//*****************************************************************************
bool appLedStateToggle(uint16 unPinNumber)
{
    bool blReturn = false;

    if(LED_PIN == unPinNumber)
    {
        if(LED_OFF == ucLedStaus)
        {
            blReturn = appLedStateOn(unPinNumber);
            if(blReturn == false)
            {
                consolePrint((uint8*)"LED ON Failed\r\n");
            }
        }
        else if(LED_ON == ucLedStaus)
        {
            blReturn = appLedStateOff(unPinNumber);
            if(blReturn == false)
            {
                consolePrint((uint8*)"LED OFF Failed\r\n");
            }
        }
    }

    return blReturn;

}

// EOF