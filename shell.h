#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024
extern char **environ;
void prompt(void);
char *read_input(void);
void clean_input(char *in, char *out);
char *get_location(char *command);
int extract_args(char *in, char *args[16]);
void free_args(char *args[16], int n);
void free_cmd(char *command, char *arg);
void print_environment(void);
void execute_free(char *i, char *c, char *ar[16], int len, unsigned int f);
int execute(char *cmd);
int check_for_path(char *cmd);
int check_for_exit(char *input);
int handle_exit(char *input);
int is_number(char *in);
void print_exit_error(char *msg, char *args[16]);

#endif
