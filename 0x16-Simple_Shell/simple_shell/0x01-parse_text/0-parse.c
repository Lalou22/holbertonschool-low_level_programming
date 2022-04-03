/*
 * File: 0-parse.c
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

char *read_line(void);
char **split_line(char *line);
void print_parse(char **args);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line;
	char **args;

	while (1)
	{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		print_parse(args);
		free(line);
		free(args);
	}
	return (0);
}

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if(feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char *delim = " \n";
	char *token;
	char **tokens = malloc(bufsize * sizeof(char*));

	if (!tokens)
	{
		printf("Error: Unable to allocate memory.");
	        exit(EXIT_FAILURE);
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
