#include "main.h"
/**
 * execute_env - print current environment
 *
 * Return: void
 */
void execute_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
}
