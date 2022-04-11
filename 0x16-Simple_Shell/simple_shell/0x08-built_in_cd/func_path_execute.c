#include "shell.h"

/**
 * find_path - Function that creates an 2D-array based on the PATH.
 * @env: Array of strings of the environment.
 *
 * Description: Function that finds on the Env the string for the PATH.
 * Then creates a 2D-pointer array of chars. Using split_line creates
 * a new row for each folder on the PATH (Separated by ':').
 * Return: Parsed-path (2D-pointer array).
 */
char **find_path(char **env)
{
	char *path_line = "PATH=";
	char *delim = ":";
	char **path;
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path_line[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	path = split_line(_strdup(env[i] + 5), delim, "", "");
	return (path);
}

/**
 * path_com - Function that concatenates the command to each folder on PATH.
 * @_path: 2D-pointer array with the folders on PATH.
 * @command: Command to be concatenated to each folder on PATH.
 *
 * Description: Checks if the last char on each folder is '/' and then
 * concatenates the command to each folder (If needed puts the missing '/').
 * Return: Pointer to the resulting concatenated PATH + command.
 */
char **path_com(char **_path, char *command)
{
	int len, bufsize = 64, i = 0;
	char *str;
	char **tokens = malloc(bufsize * sizeof(char *));

	while (_path[i] != NULL)
	{
		str = command;
		len = _strlen(_path[i]);
		if (_path[i][len - 1] != '/')
			str = _strcat("/", str);
		tokens[i] = _strcat(_path[i], str);
		i++;
	}
	tokens[i] = command;
	return (tokens);
}

/**
 * execute_path - Function that checks the folder to execute the command.
 * @_path: Array with all the posibles folders to check.
 * @env: 2D-Char Pointer array with information about the env.
 *
 * Description: Loops through the folders to find the correct one and then
 * Executes the command using "func_exec".
 * Return: Voids.
 */
void execute_path(char **_path, char **env)
{
	int i = 0, b_in = 0;
	char *_env[] = {NULL};
	char **_argv;

	while (_path[i] != NULL)
		i++;
	_argv = split_line(_path[i - 1], " ", "\"", "\"");
	b_in = check_for_builtins(_argv[0], _argv[1], env);

	i = 0;
	while (_path[i] != NULL && b_in == 0)
	{
		_argv = split_line(_path[i], " ", "\"", "\"");
		if (access(_argv[0], X_OK) != -1)
		{
			func_exec(_argv[0], _argv, _env);
			break;
		}
		i++;
	}
	if (_path[i] == NULL && b_in == 0)
		printf("%s: %s: not found\n", _argv[0], _argv[1]);
}

/**
 * func_exec - Function that creates Child process, and executes commands.
 * @pathname: Program to be executed.
 * @argv: Array of pointers to strings passed as command-line arguments.
 * @envp: Array of pointers to strings of environment of the new program.
 *
 * Description: Creates the child process and then execute it.
 * Return: Void.
 */
void func_exec(char *pathname, char **argv, char *const envp[])
{
	int status;
	pid_t child_pid;

	UNUSED(pathname);

	sleep(1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			printf("%s: 1: %s: not found", argv[0], argv[1]);
	}
	else
	{
		sleep(2);
		wait(&status);
	}
}

/**
 * split_line - Function that creates an char array for each element.
 * @line: Original char array to be separated.
 * @delim: Char arrays used to separate the original line.
 * @c1: Char array with 'opening' characters to quoute.
 * @c2: Char array with 'closing' characters to quote.
 *
 * Description: Creates a new memory alloc, based on a string. Each row
 * is created from the original line but separated each time a char found
 * on the char array delim.
 * Return: Parsed-line.
 */
char **split_line(char *line, char *delim, char *c1, char *c2)
{
	int i = 0, j = 0, k = 0, bufsize = 64, position = 0;
	int diff, f_del = 0, f_op = 0, f_cl = 0;
	char *aux = "", *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	while (line[i])
	{
		f_op = compare_chars(line[i], c1);
		if (f_op == 1)
		{
			for (k = i + 1; line[k] && f_cl != 1; k++)
				f_cl = compare_chars(line[k], c2);
			if (f_cl == 1)
			{
				diff = k - i;
				aux = _strncpy(line + i, diff);
				f_op = 0;
				f_cl = 0;
				i = k;
				j = k;
			}
		}
		f_del = compare_chars(line[i], delim);
		if ((f_del == 1 && f_cl == 0) || line[i + 1] == '\0')
		{
			diff = i - j;
			if (line[i + 1] == '\0')
				diff++;
			token = _strncpy(line + j, diff);
			token = _strcat(aux, token);
			aux = "";
			tokens[position] = token;
			position++;
			j = i + 1;
		}
		i++;
	}
	tokens[position] = NULL;
	return (tokens);
}
