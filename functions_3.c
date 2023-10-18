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
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
	int i = 0;
	unsigned int line_length = 0;

	if (custom_buffer_pos >= custom_buffer_size) {
		custom_buffer_size = read(fileno(stream), custom_buffer, BUFFER_SIZE);
		custom_buffer_pos = 0;
		if (custom_buffer_size <= 0) {
			return custom_buffer_size;
		}
	}

	for (i = custom_buffer_pos; i < custom_buffer_size; i++) {
		if (custom_buffer[i] == '\n') {
			break;
		}
	}

	line_length = i - custom_buffer_pos;

	if (*n < line_length + 1) {
		*n = line_length + 1;
		*lineptr = (char *)realloc(*lineptr, *n);
		if (*lineptr == NULL) {
			return -1;
		}
	}

	strncpy(*lineptr, custom_buffer + custom_buffer_pos, line_length);
	(*lineptr)[line_length] = '\0';

	custom_buffer_pos = i + 1;

	return line_length;
}
