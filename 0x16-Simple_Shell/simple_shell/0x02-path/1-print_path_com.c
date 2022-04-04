/*
 * File: 1-print_path_com.c
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
	char *command = "ls";

	UNUSED(ac);
	UNUSED(av);

	_env = make_env(env);
	_path = find_path(_env);
	printf("\n\n-----Print path-----\n");
	print_parse(_path);
	printf("\n\n-----Print path + command-----\n");
	_path = path_com(_path, command);
	print_parse(_path);
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
	printf("-----PATH-----\n%s\n\n", env[i]);
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
