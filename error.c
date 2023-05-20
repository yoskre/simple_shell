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

	perror(buffer);
	perror(error);
}
