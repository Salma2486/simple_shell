#include "shell.h"
/**
 *check_for_path - it check if it in current path or not
 *@cmd: input
 *Return: 0 or 1
 */
int check_for_path(char *cmd)
{
	if (cmd[0] == '.' && cmd[1] == '/')
		return (1);
	else if ((cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/') || cmd[0] == '/')
		return (1);
	else
		return (0);
}
/**
 * custom_getline - our getline function
 * @lineptr: input
 * @n: unsigned
 * @stream: filename
 * Return: 0
 */
size_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	unsigned int line_length = 0;
	int i;
	char *new_lineptr;

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = (char *)malloc(BUFFER_SIZE);
		*n = BUFFER_SIZE;
	}
	while (1)
	{
		if (pos >= custom_buffer_size)
		{ custom_buffer_size = read(fileno(stream), custom, BUFFER_SIZE);
			pos = 0;
			if (custom_buffer_size <= 0)
			{
				if (line_length == 0)
					return (-1);
				break; }
		}

		for (i = pos; i < custom_buffer_size; i++)
		{
			if (custom[i] == '\n')
			{i++;
				break; }
		}
		if (line_length + i - pos + 1 > *n)
		{ *n = line_length + i - pos + 1;
			new_lineptr = (char *)realloc(*lineptr, *n);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr; }
		strncpy(*lineptr + line_length, custom + pos, i - pos);
		line_length += i - pos;
		pos = i;
		if (custom[i - 1] == '\n')
			break; }
	(*lineptr)[line_length] = '\0';
	return (line_length);
}
