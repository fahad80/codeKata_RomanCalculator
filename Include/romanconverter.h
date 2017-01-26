
#ifndef ROMANCONVERTER_H
#define ROMANCONVERTER_H

#include <stdio.h>
#include <stdint.h>
uint16_t roman2dec_char(char);
uint16_t roman2dec_str(const char*);
uint8_t dec2roman(uint16_t, char*);
uint8_t isItValidRomanNum(const char*);
void strupr(char*);


#endif /* ROMANCONVERTER_H */
