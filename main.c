#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "PrintFunction/PrintFunction.h"

#define STRING_SIZE 64

int main()
{
    // variables decleared here
    uint8_t ucInputString[STRING_SIZE];

    memset(ucInputString,0,sizeof(ucInputString));
    PrintString("Enter a string");
    scanf("%64[^\n]s",ucInputString);

    PrintString(ucInputString);
    return 0;
}