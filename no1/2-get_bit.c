#include "main.h"
/**
* get_bit - shows num of bit in position at decimal num
* @n: num searched
* @index: position of bit
*
* Return: num of bit
*/
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
