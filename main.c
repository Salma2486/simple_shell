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
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
		{
			prompt();
		}
		input = read_input();

		if (input == NULL)
		{
			if (is_interactive)
				continue;
			else
				break;
		}
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		if (strcmp(input, "env") == 0)
			print_environment();

		else if (strlen(input) > 0)
			exit_status = execute(input);
		if (!is_interactive)
		{
			if (exit_status != 0)
				break;
		}
		free(input);
	}
	free(input);
	if (exit_status != 0)
		exit(exit_status);
	return (exit_status);
}
