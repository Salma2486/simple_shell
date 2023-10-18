#include "shell.h"
/**
 *main - This is the entry point of the code
 *
 *Return:0 Success
 */
int main(void)
{
	char *input = NULL;
	int exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			input = read_input();
			if (input == NULL)
				continue;
			if (check_for_exit(input) == 0)
			{
				exit_status = handle_exit(input);
				break;
			}
			if (strcmp(input, "env") == 0)
				print_environment();
			else if (strlen(input) > 0)
				execute(input);
			free(input);
		}
		else
		{
			input = read_input();
			if (input == NULL)
				break;
			if (check_for_exit(input) == 0)
			{
				exit_status = handle_exit(input);
				break;
			}
			if (strcmp(input, "env") == 0)
				print_environment();
			else if (strlen(input) > 0)
				exit_status = execute(input);
			if (exit_status != 0)
				break;
			free(input);
		}
	}
	free(input);
	if (exit_status != 0)
		exit(exit_status);
	return (exit_status);
}
