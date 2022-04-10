#include "shell.h"

/**
 * main - Function used to test how to get all the folders on PATH.
 * @ac: Number of arguments passed to the program (Unused).
 * @av: Array of strings of the arguments that was passed (Unused).
 * @env: Array of strings of the environment.
 *
 * Description: First get the environment, then find the PATH and parse it.
 * Last print the folders on PATH.
 * Return: Zero always.
 */
int main(int ac, char **av, char **env)
{
	char *line;
	char **_env, **_path;

	UNUSED(ac);
	UNUSED(av);

	_env = make_env(env);
	_path = find_path(_env);

	while (1)
	{
		printf("$ ");
		line = read_line();
		_path = find_path(_env);
		_path = path_com(_path, line);
		execute_path(_path);
	}
}

