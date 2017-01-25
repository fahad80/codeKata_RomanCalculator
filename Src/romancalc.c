#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "romancalc.h"


uint16_t roman2decimal_char(char romanChar)
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


uint16_t roman2decimal_str(const char romanStr[])
{
	int8_t romanStrLen = strlen(romanStr);
	if(romanStrLen < 1) 
		return 0;
	

	
	uint16_t* romanEquDecVals = (uint16_t*) malloc(romanStrLen * sizeof(uint16_t));
	
	int8_t i;
	for(i = 0; i < romanStrLen; i++)
	{
		*(romanEquDecVals + i) = roman2decimal_char(romanStr[i]);
	}
	
	uint16_t decimalVal = romanEquDecVals[romanStrLen-1];
	for(i = romanStrLen-2; i >= 0; i--)
	{
		if(romanEquDecVals[i] < romanEquDecVals[i+1])
			decimalVal = decimalVal - romanEquDecVals[i];
		else
			decimalVal = decimalVal + romanEquDecVals[i];
	}
	
	free(romanEquDecVals);
	
	return decimalVal; 
}


