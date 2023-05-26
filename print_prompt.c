#include "main.h"
#include <stdlib.h>
#define BUFFERSIZE 256
/**
 * print_prompt - display a prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	char cwd[BUFFERSIZE] = {'0'};
	char *cwdp = getcwd(cwd, sizeof(cwd));
	char *user = getenv("USER");
	char *machine = getenv("NAME");

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, user, strlen(user));
		write(STDOUT_FILENO, "@", strlen("@"));
		write(STDOUT_FILENO, machine, strlen(machine));
		if (cwdp != NULL)
		{
			write(STDOUT_FILENO, ":", strlen(":"));
			write(STDOUT_FILENO, cwd, strlen(cwd));
		}
		write(STDOUT_FILENO, "$ ", strlen("$ "));
	}
}
