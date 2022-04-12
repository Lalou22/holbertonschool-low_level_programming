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

/**
 * get_env_var - Function that gets an variable on the environment.
 * @var_name: 2D-pointer array to be printed.
 * @env: Array of strings of the environment.
 * @index: Variable's position on the envirionment.
 * @len_: Lenght of the environment.
 *
 * Description: Function that gets an variable on the environment.
 * Return: String with the variable value (If found) or NULL.
 */
char *get_env_var(char *var_name, char **env, int *index, int *len_)
{
	int len_var, len_env = 0, i = 0;
	char *aux = NULL;
	
	*index = -1;
	*len_ = -1;
	if (var_name != NULL)
	{
		len_var = _strlen(var_name);
		while (env[len_env])
		{
			for (i = 0; i < len_var; i++)
				if (var_name[i] != env[len_env][i])
					break;
			if (env[len_env][i] == '=')
			{
				*index = len_env;
			}
			len_env++;
		}
		*len_ = len_env;
		if (*index != -1)
			aux = env[*index] + len_var + 1;
	}
	return (aux);
}
