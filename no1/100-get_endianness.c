#include "main.h"
/**
* get_endianness - see if endian is small or large
* Return: (0) if large, (1) if small
*/
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
