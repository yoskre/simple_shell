#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int handle_buffer(char *buffer);
void print_error(char *buffer);
char *path_find(char *exec);
int execute(char **vector);
void execute_env(void);
void print_prompt(void);

extern char **environ;
enum flag {fault = -1, end = 0, normal = 1};

#endif
