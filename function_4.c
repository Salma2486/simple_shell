#include "shell.h"
/**
 * print_exit_error - print exit error
 * @msg: message
 * @args: input aa
 * Return: void
 */
void print_exit_error(char *msg, char *args[16])
{
	char error[128];

	strcpy(error, "./hsh: 1: ");
	strcat(error, args[0]);
	strcat(error, ": ");
	strcat(error, msg);
	strcat(error, args[1]);
	strcat(error, "\n");
	write(STDERR_FILENO, error, strlen(error));
}
/**
 * is_number - check if its number
 * @in: input
 * Return: 0 or 1
 */
int is_number(char *in)
{
	while (*in != '\0')
	{
		if (*in >= '0' && *in <= '9')
		{
		}
		else
		{
			return (0);
		}
		in++;
	}
	return (1);
}
/**
 * handle_exit - print exit error
 * @input: input
 * Return: ret
 */
int handle_exit(char *input)
{
	char *args[16];
	int n = 0;
	int ret = 0;

	if (input == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	n = extract_args(input, args);
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			if (is_number(args[1]) == 0)
			{
				print_exit_error("Illegal number: ", args);
				ret = 2;
			}
			else
			{
				ret = atoi(args[1]);
				if (ret < 0)
				{
					print_exit_error("Illegal number: ", args);
					ret = 2;
				}
			}
		}
	}
	free_args(args, n);
	return (ret);
}
/**
 * check_for_exit - check exit error
 * @input: input
 * Return: 0 or -1
 */
int check_for_exit(char *input)
{
	int i = 0;
	char arr[4];

	for (i = 0 ; i < 4 && input[i] != '\0' ; i++)
	{
		arr[i] = input[i];
	}
	arr[i] = '\0';

	return (strcmp(arr, "exit"));
}
