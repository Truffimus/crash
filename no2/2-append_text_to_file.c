#include "main.h"
/**
* append_text_to_file - appends info to end of file.
* @filename: points at  filename.
* @text_content:  string added at end of file.
*
* Return: if function fails or filename is NULL (1).
*         if file is not existing or user does not have write permission (1).
*         if not (-1).
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);
	if (o == -1 || w == -1)
		return (-1);
	close(o);
	return (1);
}
