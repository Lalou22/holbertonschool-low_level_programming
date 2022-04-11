#include "shell.h"

/**
 * check_bi - Function that "checks" for a built-in implemenatation.
 * @bi: String with the name of the built-in to be checked.
 * @arg_0: Argument Zero used in some built-ins.
 * @arg_1: Argument One used in some built-ins.
 * @env: Array of strings of the environment.
 * @f: Pointer to the int value used to indicate if a built-in was used.
 *
 * Description: Function that gets a built-in and checks for existance.
 * If found executes the built-in and returns an integer bigger than 0.
 * Return: 0 if not found the built-in.
 */
char **check_bi(char *bi, char *arg_0, char *arg_1, char **env, int *f)
{
	char **new_env = env;

	*f = 0;
	if (_strcmp(bi, "exit") == 0)
	{
		*f = 1;
		new_exit();
	}
	if (_strcmp(bi, "env") == 0)
	{
		*f = 2;
		print_parse(env);
	}
	if (_strcmp(bi, "setenv") == 0)
	{
		*f = 3;
		if (arg_0 && arg_1)
			new_env = set_env(arg_0, arg_1, env);
	}
	if (_strcmp(bi, "unsetenv") == 0)
	{
		*f = 4;
		if (arg_0)
			new_env = unset_env(arg_0, env);
	}
	if (_strcmp(bi, "cd") == 0)
	{
		*f = 5;
		change_dir(arg_0, env);
	}
	if (_strcmp(bi, "clear") == 0)
	{
		*f = 6;
		system("clear");
	}
	return (new_env);
}

/**
 * new_exit - Function to exit the shell.
 *
 * Description: Exits the shell.
 * Return: Void.
 */
void new_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * set_env - Built-in to set an environment.
 * @var: Name of the variable to be set.
 * @val: Value of the variable to be set.
 * @env: Array of strings of the environment.
 *
 * Description: Built-in function to set an environment variable.
 * Return: Environment.
 */
char **set_env(char *var, char *val, char **env)
{
	int len_var, len_env = 0, index = -1, i = 0;
	char *str;
	char **new_env;

	len_var = _strlen(var);
	while (env[len_env])
	{
		for (i = 0; i < len_var; i++)
			if (var[i] != env[len_env][i])
				break;
		if (env[len_env][i] == '=')
			index = len_env;
		len_env++;
	}
	str = _strcat(var, "=");
	str = _strcat(str, val);
	if (index != -1)
	{
		new_env = malloc((len_env + 1) * sizeof(char *));
		for (i = 0; i < len_env; i++)
		{
			if (i == index)
				new_env[i] = str;
			else
				new_env[i] = env[i];
		}
	}
	else
	{
		new_env = malloc((len_env + 2) * sizeof(char *));
		for (i = 0; i < len_env; i++)
			new_env[i] = env[i];
		new_env[i] = str;
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

/**
 * unset_env - Built-in to unset an environment.
 * @var: Name of the variable to be set.
 * @env: Array of strings of the environment.
 *
 * Description: Built-in function to unset an environment variable.
 * Return: Environment.
 */
char **unset_env(char *var, char **env)
{
	int len_var, len_env = 0, index = -1, i = 0, j = 0;
	char **new_env;

	len_var = _strlen(var);
	while (env[len_env])
	{
		for (i = 0; i < len_var; i++)
			if (var[i] != env[len_env][i])
				break;
		if (env[len_env][i] == '=')
			index = len_env;
		len_env++;
	}
	if (index == -1)
	{
		return (env);
	}
	else
	{
		new_env = malloc((len_env) * sizeof(char *));
		for (i = 0, j = 0; i < len_env - 1; i++, j++)
		{
			if (j == index)
			{
				j++;
			}
			new_env[i] = env[j];
		}
	}
	new_env[j] = NULL;
	return (new_env);
}

/**
 * change_dir - Built-in to change folder.
 * @arg: Name of the variable to be set.
 * @env: Array of strings of the environment.
 *
 * Description: Built-in function to change the folder.
 * Return: Void.
 */
void change_dir(char *arg, char **env)
{
	int i, j;
	char *path_line = "HOME=";
	char *_path;
	char s[100];

	if (arg == NULL)
	{
		for (i = 0; env[i]; i++)
		{
			for (j = 0; j < 5; j++)
				if (path_line[j] != env[i][j])
					break;
			if (j == 5)
				break;
		}
		_path = env[i] + 5;
	}
	else
	{
		_path = arg;
	}
	chdir(_path);
	printf("$%s\n", getcwd(s, 100));
}
