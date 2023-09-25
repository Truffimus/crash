#include "main.h"
/**
* clear_bit - puts num of particular bit to 0
* @n: shows num for changing
* @index: position of removed bit
*
* Return: (1) if Successful, (-1) if Fails
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
