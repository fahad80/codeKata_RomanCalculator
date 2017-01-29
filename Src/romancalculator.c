/**
  *********************************************************************
  * @file       romancalculator.c 
  * @author     Fahad Mirza (fahadmirza80@yahoo.com)
  * @version    V1.0
  * @brief      Roman Number Arithmetics (+, -)
  *********************************************************************
  */



/*------------------------------*/
/*********** Includes ***********/
/*------------------------------*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "romancalculator.h"



/*--------------------------------------*/
/*********** Global Variables ***********/
/*--------------------------------------*/
static const char *subtractive[] 	= {"CM", "CD", "XC", "XL", "IX", "IV"};
static const char *subSubstitute[] 	= {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};
static const char romanNumerals[]	= "IVXLCDM";
static const char *expandedRomans[]	= {"\0", "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD"};




/*-------------------------------------------*/
/*********** Function Declarations ***********/
/*-------------------------------------------*/
static void uncompactRoman(const char*, char*);
static void bubble_sort_descending(char*);
static void combineRomanNum(char*);
static void compactRoman(char*);
static void crossOutCommons(char*, char*);
static uint8_t isNum1greaterThanNum2(char*, char*);
static uint8_t isItValidRomanNum(const char*);



/*------------------------------------------*/
/*********** Function Definitions ***********/
/*------------------------------------------*/
/**
  * @brief  Subtract two roman numbers.
  * @param  romanNum1: Subtract from - the bigger number
  * 		romanNum2: The smaller number
  * 		result	 : Subtraction holder. An array of size 30 is advisable. 
  * @retval 1: Successful operation
  * 		0: Failed
  */
uint8_t sub2romanNum(const char romanNum1[], const char romanNum2[], char result[])
{
	if((strlen(romanNum1) == 0) || !isItValidRomanNum(romanNum1) || !isItValidRomanNum(romanNum2))
		return 0;
	
	
	char mutableRomanNum2[30];
		
	uncompactRoman(romanNum1, result);
	uncompactRoman(romanNum2, mutableRomanNum2);
	
	if(!isNum1greaterThanNum2(result,mutableRomanNum2))
		return 0;
	
	crossOutCommons(result, mutableRomanNum2);
	bubble_sort_descending(result);
	compactRoman(result);
	
	return 1;
}


/**
  * @brief  Check if number1 is greater than number2
  * @param  num1: First roman number
  * 		num2: Second roman number
  * @retval 1: num1 > num2
  * 		0: num1 <= num2
  */
uint8_t isNum1greaterThanNum2(char num1[], char num2[])
{
	uint8_t i = 0;
	
	while(1)
	{
		if(num1[i] != num2[i])
		{
			if(num2[i] == '\0')
				break;
			
			uint8_t j = 0;
			while(num1[i] != romanNumerals[j++]);
			
			uint8_t k = 0;
			while(num2[i] != romanNumerals[k++]);
			
			if(--j > --k)
				break;
			else
				return 0;
		}
		else
		{
			if(num1[++i] == '\0') 
				return 0;
		}
	}
	
	return 1;
}


/**
  * @brief  Check if the provided roman is valid.
  * @param  num: The roman number that needs to be checked
  * @note   The fuunction will check against "IVXLCDM". So small letters will throw error.
  * @retval 1: Valid roman number
  * 		0: Invalid roman number
  */
uint8_t isItValidRomanNum(const char num[])
{
	uint8_t i, j;
	for(i = 0; num[i] != '\0'; i++)
	{
		for(j = 0; j < 7; j++)
		{
			if(num[i] == romanNumerals[j])
				break;
		}
		
		if(j == 7)
			return 0;
	}
	
	return 1;
}


/**
  * @brief  Crossout symbols from num1 that num2 have.
  * @param  num1: The bigger roman number
  * 		num2: The smaller roman number
  * @note   num1 will hold the end result
  * @retval None
  */
void crossOutCommons(char num1[], char num2[])
{
	uint8_t i = 0;
	char *ptr;
	
	while( num2[i] != '\0')
	{
		ptr = strchr(num1, num2[i]);
		
		if(ptr != NULL)
		{
			while(*ptr != '\0')
			{
				*ptr = *(ptr + 1);
				ptr++;
			}
			
			i++;
		}
		else
		{
			int8_t j = 0;
			
			while(num2[i] != romanNumerals[j++]);
			
			while(j >= 0 && j < 7)
			{
				ptr = strchr(num1, romanNumerals[j]);
				
				if(ptr != NULL)
				{
					while(*(++ptr) != '\0')
					{
						*(ptr - 1) = *ptr;
					}
					strcpy(--ptr, expandedRomans[j]);
					ptr += strlen(expandedRomans[j]);
					*ptr = '\0';
					
					break;
				}
				else
					j++;
			}
			
		}
		
	}
}




/**
  * @brief  Addition of two roman numbers
  * @param  romanNum1: First roman number
  * 		romanNum2: Second roman number
  * 		result   : Summition holder. An array of size 30 is advisable. 
  * @retval 0: Failed
  * 		1: Succesful operation
  */
uint8_t add2romanNum(const char romanNum1[], const char romanNum2[], char result[])
{
	if((isItValidRomanNum(romanNum1) == 0) || (isItValidRomanNum(romanNum2) == 0))
		return 0;
	uncompactRoman(romanNum1, result);
	uncompactRoman(romanNum2, result + strlen(result));
	bubble_sort_descending(result);
	combineRomanNum(result);
	compactRoman(result);

	return 1;
}


/**
  * @brief  Convert any subtractive prefixes to additive suffixes
  * @param  romanNum		 : The roman number
  * 		uncompactRomanNum: Holder of uncompact version of romanNum 
  * @retval None
  */
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



/**
  * @brief  Sort the provided roman number in descending order
  * @param  romanNum: The roman number
  * @retval None
  */
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



/**
  * @brief  Do internal sums (e.g., replace “IIIII” with “V”)
  * @param  romanNum: The roman number
  * @retval None
  */
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



/**
  * @brief  Convert back to subtractive prefixes.
  * @param  romanNum: The Roman number
  * @retval None
  */
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
