#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "romancalculator.h"

const char *subtractive[] 	= {"CM", "CD", "XC", "XL", "IX", "IV"};
const char *subSubstitute[] = {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};



uint8_t add2romanNum(const char romanNum1[], const char romanNum2[], char result[])
{
	
	return 1;
}

void uncompactRoman(const char romanNum[], char uncompactRomanNum[])
{
	uint8_t i;
	char *ptr;
	
	for(i = 0; i < 6 && *romanNum != '\0'; i++)
	{
		ptr = strstr(romanNum, subtractive[i]);
		
		if(ptr != NULL)
		{			
			while(romanNum != ptr)
			{
				*(uncompactRomanNum++) = *(romanNum++);
			}
			romanNum += 2;
			strcpy(uncompactRomanNum,subSubstitute[i]);
			uncompactRomanNum += strlen(subSubstitute[i]);
		}
	}
	
	*uncompactRomanNum = '\0';
}
