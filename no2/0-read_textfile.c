#include "main.h"
#include <stdlib.h>
/**
* read_textfile- read Text File printed into STDOUT.
* @filename: Text File to be read
* @letters: amount of letters to  read
* Return: (w) definite amount of bytes that have been printed and read
*         (0) if function Fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);
	free(buf);
	close(fd);
	return (w);
}
