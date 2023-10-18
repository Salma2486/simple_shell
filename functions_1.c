#include "shell.h"
/**
 *prompt - This is the entry point of the code
 *
 *Return:0 Success
 */
void prompt(void)
{
	write(1, "$ ", 2);
}

/**
 *clean_input - This is the entry point of the code
 *@in: kjfcnv
 *@out: kejrgvne
 *Return:0 Success
 */
void clean_input(char *in, char *out)
{
	int i = 0;
	int cd =  0;

	while (*in != '\0')
	{
		if (*in != ' ')
		{
			cd  = 1;
			out[i++] = *in;
		}
		else if (cd == 1)
		{
			while (*in != '\0')
			{
				if (*in != ' ')
				{
					out[i++] = ' ';
					in--;
					break;
				}
				in++;
			}
		}
		in++;
	}
	out[i] = '\0';
}

/**
 *read_input - This is the entry point of the code
 *
 *Return:0 Success
 */

char *read_input(void)
{
	char *input = custom_getline(STDIN_FILENO);
	char *output = NULL;

	if (input == NULL)
	{
		return (NULL);
	}

	output = malloc(strlen(input) + 1);
	if (output == NULL)
	{
		return (NULL);
	}
	clean_input(input, output);

	return (output);
}


/**
 *get_location - This is the entry point of the code
 *@command: lkdfm
 *Return:0 Success
 */
char *get_location(char *command)
{
	char *path, *path_copy = NULL, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
	}
	if (path_copy != NULL)
	{
		free(path_copy);
	}
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
}
/**
 *extract_args - This is the entry point of the code
 *@in: jdkfvd
 *@args: kejgnek
 *
 *Return:0 Success
 */
int extract_args(char *in, char *args[16])
{
	const char delm[2] = " ";
	int i = 0;
	char *token;

	token = strtok(in, delm);
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(args[i++], token);
		token = strtok(NULL, delm);
	}
	args[i] = NULL;
	return (i);
}
