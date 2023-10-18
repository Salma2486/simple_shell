#include "shell.h"
/**
 *free_args - This is the entry point of the code
 *@args: kjdfb
 *@n: jkdgrnfk
 *Return:0 Success
 */
void free_args(char *args[16], int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		free(args[i]);
	}
}
/**
 *free_cmd - This is the entry point of the code
 *@command: elrjk
 *@arg: oliktmg
 *Return:0 Success
 */
void free_cmd(char *command, char *arg)
{
	if (command != NULL && command != arg)
		free(command);
}
/**
 *print_environment - This is the entry point of the code
 *
 *Return:0 Success
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
/**
 *execute_free - This is the entry point of the code
 *@i: fgtert
 *@c: ergfe
 *@ar: kjtrgnk
 *@len: krjtnrk
 *@f: lifgj
 *Return:0 Success
 */
void execute_free(char *i, char *c, char *ar[16], int len, unsigned int f)
{
	if (f != 0)
		free(i);
	free_args(ar, len);
	free_cmd(c, ar[0]);
}
/**
 *execute - This is the entry point of the code
 *@input: udhfnib
 *Return:0 Success
 */
int execute(char *input)
{
	pid_t pid;
	char *command, *args[16], error[32];
	int status, n = 0;

	if (input == NULL)
		exit(EXIT_SUCCESS);
	n = extract_args(input, args);
	command = args[0];
	command = get_location(command);
	if (command == NULL)
	{strcpy(error, "./hsh: 1: ");
		strcat(error, args[0]);
		strcat(error, ": not found\n");
		write(STDERR_FILENO, error, strlen(error));
		execute_free(input, command, args, n, 0);
		return (127); }
	pid = fork();
	if (pid == -1)
	{write(STDERR_FILENO, "fork() error\n", 13);
		execute_free(input, command, args, n, 1);
		exit(EXIT_FAILURE); }
	if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{perror("execve");
			execute_free(input, command, args, n, 1);
			exit(EXIT_FAILURE); } }
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			execute_free(input, command, args, n, 1);
			exit(EXIT_FAILURE); }
		execute_free(input, command, args, n, 0);
		return (WEXITSTATUS(status)); }
	execute_free(input, command, args, n, 0);
	return (0);
}

