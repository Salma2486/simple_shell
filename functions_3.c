#include "shell.h"
/**
 **custom_getline - This is the entry point of the code
 *@fd: dkfjknbed
 *Return:0 Success
 */
char *custom_getline(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int bytes_in_buffer;
	char *line = NULL;
	int line_index = 0;

	while (1)
	{
		if (buffer_index >= bytes_in_buffer)
		{
			bytes_in_buffer = read(fd, buffer, BUFFER_SIZE);
			if (bytes_in_buffer <= 0)
			{
				if (line_index == 0)
				{
					return (NULL);
				}
				else
				{
					break;
				}
			}
			buffer_index = 0;
		}
		while (buffer_index < bytes_in_buffer)
		{
			char current_char = buffer[buffer_index++];

			if (current_char == '\n' || current_char == '\0')
			{
				if (line == NULL)
				{
					line = (char *)malloc(line_index + 1);
				}
				line[line_index++] = current_char;
			}
		}
	}
	return (line);
}

