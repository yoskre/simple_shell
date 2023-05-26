#include "main.h"
/**
 * main - start here
 *
 * Return: normal, end or fault
 */
int main(void)
{
	int state = normal;
	char *buffer = NULL;
	ssize_t bytesread;
	size_t len = 0;

	while (state)
	{
		print_prompt();
		bytesread = getline(&buffer, &len, stdin);
		if (bytesread == fault)
		{
			free(buffer);
			exit(fault);
		}
		buffer[bytesread - 1] = '\0';
		state = handle_buffer(buffer);
		if (state == fault)
		{
			print_error(buffer);
			state = normal;
		}
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		len = 0;
	}
	exit(end);
}
