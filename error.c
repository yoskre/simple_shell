#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * error - handle errors
 * @buffer: buffer
 *
 * Return: void
 */
void error(char *buffer)
{
	char *error = ": No such file or directory\n";

	write(STDERR_FILENO, buffer, strlen(buffer));
	write(STDERR_FILENO, error, strlen(error));
}
