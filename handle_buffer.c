#include "main.h"
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
			tmpc = 1;
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
 * handle_buffer - handle shell buffer
 * @buffer: buffer
 *
 * Return: normal, end or fault
 */
int handle_buffer(char *buffer)
{
	char **vector, *path;

	while (*buffer == ' ')
		buffer++;
	if (*buffer == '\0')
		return (normal);
	vector = vectorize(buffer);
	if (vector == NULL)
		return (fault);
	if (!strcmp("exit", *vector))
	{
		free(vector);
		return (end);
	}
	if (!strcmp("env", *vector))
	{
		execute_env();
		free(vector);
		return (normal);
	}
	path = path_find(*vector);
	if (path)
		*vector = path;
	if (access(*vector, X_OK) == 0)
		if (execute(vector) == normal)
		{
			free(vector);
			free(path);
			return (normal);
		}
	free(vector);
	free(path);
	return (fault);
}
