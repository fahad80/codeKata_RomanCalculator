#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "romancalculator.h"

const char *subtractive[] 	= {"CM", "CD", "XC", "XL", "IX", "IV"};
const char *subSubstitute[] = {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};
const char romanNumerals[]	= "IVXLCDM";



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

void bubble_sort_descending(char romanNum[])
{
	uint8_t length = strlen(romanNum);
	uint8_t *list = (uint8_t*) malloc(length * sizeof(uint8_t));
	uint8_t i, j, temp;
 
	for(i = 0; i < length; i++)
	{
		j = 0;
		while(*(romanNum + i) != romanNumerals[j++]);
		list[i] = j - 1;
	}
 
 
    for (i = 0; i < (length - 1); i++)
    {
		for (j = 0; j < (length - i - 1); j++)
		{
			if (list[j] < list[j+1])
			{
				/* Swapping */
				temp      = list[j];
				list[j]   = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	
	for(i = 0; i < length; i++)
	{
		*(romanNum + i) = romanNumerals[list[i]];
	}
}
