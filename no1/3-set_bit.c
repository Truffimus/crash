#include "main.h"
/**
* set_bit - puts bit to certain position at 1
* @n: shows num for changing
* @index: position of bit put at 1
*
* Return: (1) if Successful, (-1) if Fails
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
