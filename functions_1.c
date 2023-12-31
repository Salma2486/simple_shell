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

	if (*in == '#')
	{
		out[i] = '\0';
		return; }
	while (*in != '\0')
	{
		if (*in == '#')
		{
			in--;
			if (*in == ' ')
			{
				in++;
				break; }
			in++;
			cd = 1;
			out[i++] = *in; }
		else if (*in != ' ')
		{
			cd  = 1;
			out[i++] = *in; }
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
	char *input = NULL;
	char *output = NULL;
	size_t input_size = 0;
	ssize_t read;

	while (1)
	{
		read = getline(&input, &input_size, stdin);
		if (read == -1)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		input[strcspn(input, "\n")] = '\0';

		if (input[0] == '#')
		{
			free(input);
			return (strdup(""));
		}

		break;
	}

	output = malloc(sizeof(char) * (strlen(input) + 1));
	if (output == NULL)
	{
		free(input);
		return (NULL);
	}
	clean_input(input, output);
	free(input);
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

	if (check_for_path(command) == 0)
	{
		path = getenv("PATH");
		if (path)
		{
			path_copy = strdup(path);
			command_length = strlen(command);
			path_token = strtok(path_copy, ":");
			while (path_token != NULL)
			{directory_length = strlen(path_token);
				file_path = malloc(command_length + directory_length + 2);
				strcpy(file_path, path_token);
				strcat(file_path, "/");
				strcat(file_path, command);
				strcat(file_path, "\0");
				if (stat(file_path, &buffer) == 0)
				{free(path_copy);
					return (file_path);
				}
				else
				{free(file_path);
					path_token = strtok(NULL, ":"); }
			}
		}
	}
	else
	{
		if (path_copy != NULL)
			free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		else
			return (NULL); }
	if (path_copy != NULL)
		free(path_copy);
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

