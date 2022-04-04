/*
 * File: 5-exe_cmd.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/*
 * Macro used to avoid warnings for unused arguments on main
 */
#define UNUSED(x) (void)(x)

char **make_env(char **env);
char **find_path(char **env);
char *_strdup(char *original);
int _strlen(char *s);
char **split_line(char *line, char *delim);
void print_parse(char **args);
char *_strcat(char *s1, char *s2);
char **path_com(char **_path, char *command);
char *read_line(void);
char *remove_char(char *line, char c);
void execute_path(char **_path);
void func_exec(char *pathname, char **argv, char *const envp[]);

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
	char **_env;
	char **_path;
	char *line;

	UNUSED(ac);
	UNUSED(av);

	_env = make_env(env);
	_path = find_path(_env);

	while (1)
	{
		printf("-----Gets command from keyboard-----\n");
		printf("$ ");
		line = read_line();
		printf("\n\n-----Checks path + command-----\n");
		_path = find_path(_env);
		_path = path_com(_path, line);
		execute_path(_path);
	}
}

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
	path = split_line(_strdup(env[i] + 5), delim);
	return (path);
}

/**
 * _strdup - Function that creates a mem alloc space for a string copy.
 * @original: Char array to be duplicated.
 *
 * Description: Function that duplicates a string.
 * Return: Copy of the original string or NULL if failed.
 */
char *_strdup(char *original)
{
	char *copy;
	int i, len;

	if (!original)
		return (NULL);
	len = _strlen(original);
	copy = malloc((len + 1) * sizeof(char));
	for (i = 0; i <= len; i++)
		copy[i] = original[i];
	return (copy);
}

/**
 * _strlen - Function that returns the length of a string.
 * @s: Pointer to the char string.
 *
 * Description: The standard library provides a similar function: strlen.
 * Run man strlen to learn more.
 * Return: Length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * split_line - Function that creates an char array for each element.
 * @line: Original char array to be separated.
 * @delim: Char arrays used to separate the original line.
 *
 * Description: Creates a new memory alloc, based on a string. Each row
 * is created from the original line but separated each time a char found
 * on the char array delim.
 * Return: Parsed-line.
 */
char **split_line(char *line, char *delim)
{
	int bufsize = 64, position = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		printf("Error: Unable to allocate memory.");
		exit(1);
	}
	token = strtok(line, delim);
	while (token)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
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
 * _strcat - Function that concatenates two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Description: Function that appends the s2 to  s1.
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *s1, char *s2)
{
	int i, l1, l2;
	char *str;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	for (i = 0; i < l1; i++)
		str[i] = s1[i];
	for (i = 0; i < l2; i++)
		str[l1 + i] = s2[i];
	str[l1 + l2] = '\0';
	return (str);
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
	return (tokens);
}

/**
 * read_line - Function to read information from the user.
 * @void: Void parameter.
 *
 * Description: Utilices the standard function getline
 * and checks for error.
 * Return: Char pointer "line".
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("readline");
			exit(1);
		}
	}
	line = remove_char(line, '\n');
	return (line);
}

/**
 * remove_char - Function to creates a new_str removing all the selected char.
 * @line: Original char array that may contain the char to be ignored.
 * @c: Char to be ignored on the line.
 *
 * Description: Loops through the line and ignores the char 'c'.
 * Return: New line.
 */
char *remove_char(char *line, char c)
{
	char *new_line;
	int i, j, len;

	len = _strlen(line);
	new_line = malloc((len + 1) * sizeof(char));
	for (i = 0, j = 0; j < len; i++, j++)
	{
		if (line[i] == c)
			j++;
		new_line[i] = line[j];
	}
	new_line[i] = '\0';
	return (new_line);
}

void execute_path(char **_path)
{
	int i = 0;
	char *_env[] = {NULL};
	char **_argv;

	while (_path[i] != NULL)
	{
		_argv = split_line(_path[i], " ");
		if (access(_argv[0], X_OK) != -1)
		{
			printf("Executing the command on: %s\n", _argv[0]);
			func_exec(_argv[0], _argv, _env);
			break;
		}
		i++;
	}
	if (_path[i] == NULL)
		printf("Not executable file found\n");
}

void func_exec(char *pathname, char **argv, char *const envp[])
{
	int status;
	pid_t child_pid;

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
			printf("%s: No such file\n", pathname);
	}
	else
	{
		sleep(3);
		wait(&status);
	}
	printf("\n");
}
