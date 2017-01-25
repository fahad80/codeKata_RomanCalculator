#include <ctype.h>
#include "romancalc.h"


int roman2decimalSingleChar(char romanChar)
{
	romanChar = toupper(romanChar);
	switch(romanChar)
	{
		case 'I': 
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;		
		case 'L':
			return 50;
			break;		
		case 'C':
			return 100;
			break;		
		case 'D':
			return 500;
			break;		
		case 'M':
			return 1000;
			break;	
		default:
			return -1;
	}
    return 1;
}
