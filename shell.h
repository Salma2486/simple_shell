#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void prompt(void);
void clean_input(char *in, char *out);
char *read_input(void);
int extract_args(char *in, char *args[16]);
void free_args(char *args[16], int n);
void print_environment(void);
int execute(char *cmd);

#endif
