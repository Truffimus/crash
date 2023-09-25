#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: NULL
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

/**
writeCharToStderr - writes the character 'c' to stderr
@c:character to be printed
Return: 1 on success. On error, -1 
*/
int _eputchar(char z)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(2, buf, s);
		s = 0;
	}
	if (z != BUF_FLUSH)
		buf[s++] = z;
	return (1);
}

/**
writeCharToFileDescriptor - writes the character 'c' to the specified file descriptor 'fd'
@c: The character to print
@fd: The file descriptor
Return: 1 on success. On error, -1 
*/
int _putfd(char z, int d)
{
	static int s;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || s >= WRITE_BUF_SIZE)
	{
		write(d, buf, s);
		s = 0;
	}
	if (z != BUF_FLUSH)
		buf[s++] = z;
	return (1);
}

/**
printInputStringToFileDescriptor - prints a given input string to the specified file descriptor
@str: the string to be printed
@fd: the file descriptor 
Returns: the  characters written given
*/
int _putsfd(char *str, int d)
{
	int z = 0;

	if (!str)
		return (0);
	while (*str)
	{
		z += _putfd(*str++, d);
	}
	return (z);
}
