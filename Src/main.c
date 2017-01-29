#include "romancalculator.h"
#include "romanconverter.h"

int main()
{
	char sub[40];
	char num1[30];
	char num2[30];
	
	int16_t i,j;
	
	for(i=4999; i>0; i--)
	{
		for(j=1; j<i; j++)
		{
			dec2roman(i,num1);dec2roman(j,num2);
			sub2romanNum(num1, num2, sub);
			if(roman2dec_str(sub) != i-j)
			{
				printf("converted sub: %d\n",roman2dec_str(sub));
				printf("actual sub: %d\n",i-j);
			}
		}
	}
	
    return 0;
}
