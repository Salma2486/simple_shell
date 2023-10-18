#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
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
#endif
