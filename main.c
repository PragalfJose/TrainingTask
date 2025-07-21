#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "PrintFunction/PrintFunction.h"

int main()
{
    // variables decleared here
    uint8_t ucInputString[64];

    memset(ucInputString,0,sizeof(ucInputString));
    PrintString("Enter a string");
    scanf("%[^\n]s",ucInputString);

    PrintString(ucInputString);
    return 0;
}