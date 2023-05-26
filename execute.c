#include "main.h"
/**
 * execute - execute commands
 * @vector: array of program path and arguments
 *
 * Return: normal, end or fault
 */
int execute(char **vector)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(vector[0], vector, environ) == fault)
			exit(fault);
		exit(normal);
	}
	else if (pid > 0)
	{
		wait(NULL);
		return (normal);
	}
	return (fault);
}
