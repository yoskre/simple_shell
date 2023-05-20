#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - start here
 * @argc: argument count
 * @argv: argument vectors
 *
 * Return: 0 if good, 1 if error
 */
int main(int argc, char **argv)
{
	int state = 1;
	char *prompt = "$ ";
	char *buffer = NULL;
	ssize_t bytesread;
	size_t len = 0;

	(void) argc;
	(void) argv;
	while (state)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
			len = 0;
		}
		write(STDOUT_FILENO, prompt, strlen(prompt) * sizeof(char));
		bytesread = getline(&buffer, &len, stdin);
		if (bytesread < 0)
		{
			free(buffer);
			return (1);
		}
		buffer[bytesread - 1] = '\0';
		state = handle(buffer);
		if (state == -1)
			error(buffer);
	}
	if (buffer != NULL)
		free(buffer);
	return (0);
}
