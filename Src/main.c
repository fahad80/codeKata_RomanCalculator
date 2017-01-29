/**
  *********************************************************************
  * @file       main.c 
  * @author     Fahad Mirza (fahadmirza80@yahoo.com)
  * @version    V1.0
  *********************************************************************
  */

#include <string.h>
#include <stdio.h>
#include "romancalculator.h"

int main()
{
	char result[40];
	char num1[30];
	char num2[30];
	
	
	printf("\n*** Addition of two roman numbers ***\n");
	
	printf("Enter first number: ");
	fgets (num1, 29, stdin);
	num1[strcspn(num1, "\r\n")] = 0;
	
	printf("Enter second number: ");
	fgets (num2, 29, stdin);
	num2[strcspn(num2, "\r\n")] = 0;
	
	if(add2romanNum(num1, num2, result))
		printf("%s + %s = %s\n", num1, num2, result);
	else
		printf("Failed to add!\n");
	
	
	
	
	
	printf("\n*** Subtraction of two roman numbers ***\n");
	
	printf("Enter the bigger number: ");
	fgets (num1, 29, stdin);
	num1[strcspn(num1, "\r\n")] = 0;
	
	printf("Enter the smaller number: ");
	fgets (num2, 29, stdin);
	num2[strcspn(num2, "\r\n")] = 0;
	
	if(sub2romanNum(num1, num2, result))
	{
		printf("%s - %s = %s\n", num1, num2, result);
	}
	else
		printf("Failed to subtract!\n");
	
    return 0;
}
