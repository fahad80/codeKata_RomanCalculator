
#ifndef ROMANCALCULATOR_H
#define ROMANCALCULATOR_H

#include <stdio.h>
#include <stdint.h>

uint8_t add2romanNum(const char*, const char*, char*);
void uncompactRoman(const char romanNum[], char uncompactRomanNum[]);
void bubble_sort_descending(char romanNum[]);
void combineRomanNum(char romanNum[]);
void compactRoman(char romanNum[]);

#endif /* ROMANCALCULATOR_H */
