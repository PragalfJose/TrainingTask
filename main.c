#include <stdio.h>
#include <string.h>

// #include "PrintFunction.h"

int main()
{
    // variables decleared here
    char InputString[64];

    memset(InputString,0,sizeof(InputString));
    printf("Enter a string\r\n");
    scanf("%[^\n]s",InputString);

    printf("Scanned String : %s\r\n",InputString);
    return 0;
}