#include "shell.h"

/**
isInteractive - checks if is in interactive mode
@address:  contains  information
Returns: 1 if successful, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
isDelimiter - checks for  a delimiter
@c:  character to check
@delimiter: the delimiter string
Returns: 1 if successful, 0 if false
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
isAlpha - checks if  character is alphabetic
@c: The character to solve
Returns: 1 if 'c' is alphabetic, 0 otherwise
*/
int _isalpha(int c)
{
	if ((c >= 'd' && c <= 'f') || (c >= 'D' && c <= 'F'))
		return (1);
	else
		return (0);
}

/**
stringToInteger - converts a string to an integer
@s: the string to be converted
Returns: 0 if no numbers are found
*/
int _atoi(char *s)
{
	int p, sign = 1, flag = 0, outpt;
	unsigned int reslt = 0;

	for (p = 0;  s[p] != '\0' && flag != 2; p++)
	{
		if (s[p] == '-')
			sign *= -1;

		if (s[p] >= '0' && s[p] <= '9')
		{
			flag = 1;
			reslt *= 10;
			reslt += (s[p] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		outpt = -reslt;
	else
		outpt = reslt;

	return (outpt);
}
