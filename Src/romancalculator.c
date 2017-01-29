#include <ctype.h>
#include <stdlib.h>
#include "romancalculator.h"

static const char *subtractive[] 	= {"CM", "CD", "XC", "XL", "IX", "IV"};
static const char *subSubstitute[] 	= {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};
static const char romanNumerals[]	= "IVXLCDM";
static const char *expandedRomans[]	= {"\0", "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD"};



static void uncompactRoman(const char*, char*);
static void bubble_sort_descending(char*);
static void combineRomanNum(char*);
static void compactRoman(char*);
static void crossOutCommons(char*, const char*);





void sub2romanNum(const char romanNum1[], const char romanNum2[], char result[])
{
	char mutableRomanNum1[40];
	strcpy(mutableRomanNum1, romanNum1);
	
	crossOutCommons(mutableRomanNum1, romanNum2);
	

}

void crossOutCommons(char num1[], const char num2[])
{
	uint8_t i;
	uint8_t num2len = strlen(num2);
	
	for(i = 0; i < num2len; i++)
	{
		
	}
}



void add2romanNum(const char romanNum1[], const char romanNum2[], char result[])
{
	uncompactRoman(romanNum1, result);
	uncompactRoman(romanNum2, result + strlen(result));
	bubble_sort_descending(result);
	combineRomanNum(result);
	compactRoman(result);

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
			strcpy(uncompactRomanNum, subSubstitute[i]);
			uncompactRomanNum += strlen(subSubstitute[i]);
		}
	}
	while(*romanNum != '\0')
		*(uncompactRomanNum++) = *(romanNum++);
		
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
	
	free(list);
}


void combineRomanNum(char romanNum[])
{
	char *startPtr;
	char *prevStartPtr = &romanNum[strlen(romanNum)];

	uint8_t divisor[] = {5,2,5,2,5,2};
	
	
	uint8_t i;
	for(i = 0; i < 6; i++)
	{
		startPtr = strchr(romanNum, romanNumerals[i]);
		
		if(startPtr != NULL)
		{			
			uint8_t count = 0;
			while( *(startPtr + count) == romanNumerals[i])
				count++;
			
			uint8_t j;
			for(j = count/divisor[i]; j > 0; j--)
			{
				*(startPtr++) = romanNumerals[i+1];
			}
			
			char *tmpPtr = startPtr;
			for(j = count%divisor[i]; j > 0; j--)
			{
				*(startPtr++) = romanNumerals[i];
			}

				
			while(*prevStartPtr != '\0')
				*(startPtr++) = *(prevStartPtr++);
			
						
			*startPtr = '\0';
			prevStartPtr = tmpPtr;
		}
	}
}


void compactRoman(char romanNum[])
{
	uint8_t i;
	char *ptr;
	
	for(i = 0; i < 6; i++)
	{
		ptr = strstr(romanNum, subSubstitute[i]);
		
		if(ptr != NULL)
		{			
			strcpy(ptr, subtractive[i]);
			
			char *tmpPtr = ptr + 2;
			ptr += strlen(subSubstitute[i]);
			while(*ptr != '\0')
				*(tmpPtr++) = *(ptr++);
			
			*tmpPtr = '\0';
		}
	}
}
