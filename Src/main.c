#include "romancalculator.h"
#include "romanconverter.h"

int main()
{
	char sum[40];
	char num1[20];
	char num2[20];
	
	uint16_t i,j;
	
	for(i=1; i<4999; i++)
	{
		for(j=1; j<4999; j++)
		{
			dec2roman(i,num1);dec2roman(j,num2);
			add2romanNum(num1, num2, sum);
			if(roman2dec_str(sum) != i+j)
			{
				printf("converted sum: %d\n",roman2dec_str(sum));
				printf("actual sum: %d\n",i+j);
			}
		}
	}
	
    return 0;
}
