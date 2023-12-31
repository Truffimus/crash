#include "shell.h"
/**
* _memset - fills the memory with a constant byte
* @s: memory area pointer
* @b: byte to fill *s with
* @n: number of bytes to be filled
* Return: (s) pointer for memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/**
* ffree - frees a string of many strings
* @pp: string of many strings
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
* _realloc - reallocates a block of the memory
* @ptr: points at previous mallocated block
* @old_size: byte size of the block before
* @new_size: byte size of the new block
*
* Return: pointer to the previus block name
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
