/*
 * File: 0-print_path.c
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

char **make_env(char **env);
char **find_path(char **env);
char *_strdup(char *duplicate);
int _strlen(char *s);
char **split_line(char *line, char *delim);
void print_parse(char **args);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char **_env;
	char **_path;

	_env = make_env(env);
	_path = find_path(_env);
	print_parse(_path);
}

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

char *_strdup(char *duplicate)
{
	char *copy;
	int i, len;

	if (!duplicate)
		return (NULL);
        len = _strlen(duplicate);
	copy = malloc((len + 1) * sizeof(char));
	for (i = 0; i <= len; i++)
		copy[i] = duplicate[i];
	return (copy);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

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
