#include <ctype.h>
#include <string.h>
#include "romancalc.h"


uint16_t roman2decimalSingleChar(char romanChar)
{
	romanChar = toupper(romanChar);
	switch(romanChar)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;		
		case 'L': return 50;		
		case 'C': return 100;		
		case 'D': return 500;		
		case 'M': return 1000;	
		default	: return 0;
	}
}



uint16_t roman2decimal(char romanString[])
{
	// Max Roman Value (= 4999) requires 10digits 
	char romanStr[20]; 
	strcpy(romanStr,romanString);
	strupr(romanStr);
	return strlen(romanStr); 
}

void strupr(char s[])
{
	char *tmp = s;

    for (;*tmp;tmp++) 
    {
        *tmp = toupper(*tmp);
    }
}
