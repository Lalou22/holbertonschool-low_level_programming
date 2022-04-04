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

char **make_env(char **env);
char **find_path(char **env);
char *_strdup(char *duplicate);
int _strlen(char *s);
char **split_line(char *line, char *delim);
void print_parse(char **args);
char *_strcat(char *s1, char *s2);
char **path_com(char **_path, char *command);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	char **_env;
	char **_path;
	char *command = "ls";

	_env = make_env(env);
	_path = find_path(_env);
	printf("\n\n-----Print path-----\n");
	print_parse(_path);
	printf("\n\n-----Print path + command-----\n");
	_path = path_com(_path, command);
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
	printf("-----PATH-----\n%s\n\n", env[i]);
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
	str[l1+l2] = '\0';
	return (str);
}

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
	return(tokens);
}
