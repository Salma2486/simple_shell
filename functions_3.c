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
