
#ifndef ROMANCALC_H
#define ROMANCALC_H

#include <stdio.h>
#include <stdint.h>
uint16_t roman2dec_char(char);
uint16_t roman2dec_str(const char*);
void dec2roman(uint16_t, char*);
uint8_t isItValidRomanNum(const char*);
void strupr(char*);


#endif /* ROMANCALC_H */
