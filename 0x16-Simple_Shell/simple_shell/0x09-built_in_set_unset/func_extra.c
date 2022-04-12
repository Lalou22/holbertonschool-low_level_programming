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
	if (*index == -1)
	{
		aux = var_name;
	}
	return (aux);
}

/**
 * replace_variable - Function that replace with a variable of the env.
 * @arg: 2D-pointer array to be tested.
 * @env: Array of strings of the environment.
 *
 * Description: Function that gets an variable on the environment.
 * Return: String with the variable replaced (If found) or NULL.
 */
char **replace_variable(char **arg, char **env)
{
	int i = 0, j = 0, len_ = -1, index = -1;
	char **aux;
	char *_line = "";
	int parent_pid;

	while (arg[i])
	{
		_line = "";
		aux = split_line(arg[i], " ", "", "");
		j = 0;
		while (aux[j])
		{
			if (aux[j][0] == '$' && aux[j][1] != '$')
				aux[j] = get_env_var(aux[j] + 1, env, &index, &len_);
			if (aux[j][0] == '$' && aux[j][1] == '$')
			{
				parent_pid = getppid();
				aux[j] = int_to_str(parent_pid);
			}
			if (j == 0)
				_line = aux[j];
			else
				_line = strcat(_line, aux[j]);
			if (aux[j + 1])
				_line = strcat(_line, " ");
			j++;
		}
		arg[i] = _line;
		i++;
	}
	return (arg);
}

/**
 * int_to_str - Function that transforms an integer to a string.
 * @num: Integer to be transformed.
 *
 * Description: Function that transforms an integer to a string.
 * Return: An array with the number.
 */
char *int_to_str(int num)
{
	char *aux;
	int x = num, len, i = 0;

	if (num >= 0)
	{
		aux = malloc(sizeof(char) * 2);
		aux[0] = '0';
		aux[1] = '\0';
		return (aux);
	}
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	i--;
	len = i;
	aux = malloc(sizeof(char) * len);
	x = num;
	while (i >= 0)
	{
		aux[i--] = x % 10 + '0';
		x /= 10;
	}
	aux[len + 1] = '\0';
	return (aux);
}
