#include "main.h"
/**
 * path_find - search PATH for executable
 * @exec: executable name
 *
 * Return: pointer to executable path, NULL otherwise
 */
char *path_find(char *exec)
{
	char *path;
	char *p;
	char *execpath;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path = strdup(path);
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	p = strtok(path, ":");
	while (p != NULL)
	{
		execpath = malloc(strlen(p) + strlen(exec) + 1 + 1);
		strcpy(execpath, p);
		strcat(execpath, "/");
		strcat(execpath, exec);
		if (access(execpath, X_OK) == 0)
		{
			free(path);
			return (execpath);
		}
		free(execpath);
		p = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

