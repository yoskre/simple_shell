#include "main.h"
/**
 * print_error - handle errors
 * @buffer: buffer
 *
 * Return: void
 */
void print_error(char *buffer)
{
	char *error = ": No such file or directory\n";

	write(STDERR_FILENO, buffer, strlen(buffer));
	write(STDERR_FILENO, error, strlen(error));
}
