#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<sys/wait.h>
/**
 * freevector - free vector
 * @vector: vector
 *
 * Return: void
 */
void freevector(char **vector)
{
	if (vector != NULL)
		free(vector);
}
/**
 * vectorize - vectorize a buffer
 * @buffer: buffer
 *
 * Return: array of buffer tokens, NULL otherwise
 */
char **vectorize(char *buffer)
{
	char **vector;
	int i;
	int c = 0;
	int tmpc = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == ' ')
			tmpc++;
		else
		{
			c += tmpc;
			tmpc = 0;
		}
	}
	c++;
	vector = malloc((c + 1) * sizeof(char *));
	if (vector == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector[c] = NULL;
	vector[0] = strtok(buffer, " ");
	for (i = 1; i < c; i++)
		vector[i] = strtok(NULL, " ");
	return (vector);
}
/**
 * handle - handle shell buffer
 * @buffer: buffer
 *
 * Return: 1 on normal operations, 0 to exit and -1 on error
 */
int handle(char *buffer)
{
	/* will function like main's argv */
	char **vector;
	
	while (*buffer == ' ' && *buffer != '\0')
		buffer++;
	if (*buffer == '\0')
		return (1);
	vector = vectorize(buffer);
	if (vector == NULL)
		return (-1);
	if (!strcmp("exit", *vector))
	{
		freevector(vector);
		return (0);
	}
	if (access(*vector, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			if (execve(vector[0], vector, environ) == -1)
				exit(-1);
			exit(1);
		}
		else if (pid > 0)
		{
			wait(NULL);
			return (1);
		}
		else
		{
			freevector(vector);
			return (-1);
		}
	}
	freevector(vector);
	return (-1);
}
