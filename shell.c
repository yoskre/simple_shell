#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 1024
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
	char buffer[BUFFERSIZE];
	ssize_t bytesread;

	(void) argc;
	(void) argv;
	while (state)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt) * sizeof(char));
		bytesread = read(STDIN_FILENO, buffer, BUFFERSIZE);
		if (bytesread < 0)
			return (1);
		buffer[bytesread - 1] = '\0';
		state = handle(buffer);
		if (state == -1)
		{
			write(STDERR_FILENO, buffer, strlen(buffer) * sizeof(char));
			write(STDERR_FILENO, ": No such file or directory\n", 28 * sizeof(char));
		}
	}
	return (0);
}
