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
	
	char tmpRomanNum[20];
	strcpy(tmpRomanNum, romanNum);
	char *romanNumPtr = tmpRomanNum;
	
	for(i = 0; i < 6 && *romanNumPtr != '\0'; i++)
	{
		ptr = strstr(romanNumPtr, subtractive[i]);
		
		if(ptr != NULL)
		{
			*ptr = '\0';
			strcpy(uncompactRomanNum,romanNumPtr);
			uncompactRomanNum += strlen(romanNumPtr);
			romanNumPtr += strlen(romanNumPtr) + 2;
			strcpy(uncompactRomanNum,subSubstitute[i]);
			uncompactRomanNum += strlen(subSubstitute[i]);
		}
	}
	
	*uncompactRomanNum = '\0';
}
