#include <string.h>
#include "romanconverter.h"
#include "romancalculator.h"

int main()
{
	char buffer[20];
	
	uncompactRoman("CDLXXIX", buffer);
	
	printf("%s\n", buffer);
	
    return 0;
}
