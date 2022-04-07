#include "shell.h"

/**
 * make_env - Function that gets an environment and alloc memory.
 * @env: Array of strings of the environment.
 *
 * Description: Function that gets an environment and alloc memory.
 * Return: New environment.
 */
char **make_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}

/**
 * print_parse - Function that prints a 2D-pointer array.
 * @args: 2D-pointer array to be printed.
 *
 * Description: Function used for testing.
 * Return: Void.
 */
void print_parse(char **args)
{
	int i = 0, j;

	while (args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			printf("%c", args[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
