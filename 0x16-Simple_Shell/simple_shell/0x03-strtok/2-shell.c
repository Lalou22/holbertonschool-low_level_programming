/*
 * File: 1-shell.c
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
void print_parse(char **args);
char *_strcat(char *s1, char *s2);
char **path_com(char **_path, char *command);
char *read_line(void);
char *remove_char(char *line, char c);
void execute_path(char **_path);
void func_exec(char *pathname, char **argv, char *const envp[]);
char **split_line(char *line, char *delim, char *c1, char *c2);
char *_strncpy(char *src, int n);
int compare_chars(char c, char *str);

/* New function */
char *_getline(void);

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
	path = split_line(_strdup(env[i] + 5), delim, "", "");
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
	tokens[i] = command;
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

	line = _getline();
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

/**
 * execute_path - Function that checks the folder to execute the command.
 * @_path: Array with all the posibles folders to check.
 *
 * Description: Loops through the folders to find the correct one and then
 * Executes the command using "func_exec".
 * Return: Voids.
 */
void execute_path(char **_path)
{
	int i = 0;
	char *_env[] = {NULL};
	char **_argv;

	while (_path[i] != NULL)
	{
		_argv = split_line(_path[i], " ", "\"", "\"");
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
	char *aux = "";
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	while (line[i])
	{
		f_op = compare_chars(line[i], c1);
		/* If found an char on the 'opening' string */
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
		/* If found an char on the 'delim' string */
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

/**
 * compare_chars - Function that loops str to compare with c.
 * @c: Char to be compared.
 * @str: String with different chars.
 *
 * Description: Function that loops str, and compares c.
 * Return: 1 if equals and 0 otherwise.
 */
int compare_chars(char c, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncpy - Write a function that copies a string..
 * @src: Pointer to source string.
 * @n: Integer that limits concat.
 *
 * Description: Function that copy the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *src, int n)
{
	int len;
	char *aux = malloc(sizeof(char) * n);

	for (len = 0; src[len] !=  '\0' && len < n; len++)
		aux[len] = src[len];
	aux[len] = '\0';
	return (aux);
}

char *_getline(void)
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}
}
