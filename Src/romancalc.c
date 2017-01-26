#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "romancalc.h"

const int romanDecValue[] 	= {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* romanNumeral[]	= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};


uint16_t roman2dec_char(char romanChar)
{
	switch(toupper(romanChar))
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


uint16_t roman2dec_str(const char romanStr[])
{
	int8_t romanStrLen = strlen(romanStr);
	if(romanStrLen < 1) 
		return 0;
	

	
	uint16_t resultDeclVal = 0;
	uint16_t romanEquDecVal;
	uint16_t prevDecValue = 0;
	
	int8_t i;
	for(i = romanStrLen-1; i >= 0; i--)
	{
		romanEquDecVal = roman2dec_char(romanStr[i]);
		if(romanEquDecVal == 0)
			return 0;
		
		if (romanEquDecVal < prevDecValue)
			resultDeclVal -= romanEquDecVal;
		else
			resultDeclVal += romanEquDecVal;
		
		prevDecValue = romanEquDecVal;
	}
	
	{
		char convertedRomanNum[20];
		dec2roman(resultDeclVal,convertedRomanNum);
		
		char copiedRomanStr[20];
		strcpy(copiedRomanStr,romanStr);
		strupr(copiedRomanStr);
		if(strcmp(copiedRomanStr, convertedRomanNum) != 0)
			return 0;
	}
		
	return resultDeclVal; 
}

void dec2roman(uint16_t decNum, char romanNum[])
{
	uint8_t i = 0;
	while(decNum != 0)
	{		
		while(romanDecValue[i] <= decNum)
		{
			decNum -= romanDecValue[i];
			strcpy(romanNum,romanNumeral[i]);
			romanNum += strlen(romanNumeral[i]); 
		}
		i++;		
	}
	
	*romanNum = 0;
}


uint8_t isItValidRomanNum(const char suppliedRomanNum[])
{
	uint16_t decVal = roman2dec_str(suppliedRomanNum);
	if(decVal == 0)
		return 0;
	
	return 1;
}

void strupr(char s[])
{
	char *tmp = s;

    for (;*tmp;tmp++) 
    {
        *tmp = toupper(*tmp);
    }
}
