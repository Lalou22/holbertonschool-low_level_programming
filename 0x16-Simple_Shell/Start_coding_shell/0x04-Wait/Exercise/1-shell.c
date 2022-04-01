/*
 * File: 1-shell.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *tokenizer(char *string, char delimiter, int len);
int _strlen(char *s);

/**
 * main - super simple shell
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: Write a first version of a super simple
 * shell that can run commands with their full path, without any argument.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *command; /* Char array pointer. */
	size_t size = 100; /* Initial size of char array. */
	char *argv[] = {NULL, NULL};
	char *envp[] = {NULL};
	int status;
	pid_t child_pid;

	command = (char *) malloc(size);
	if (command == NULL)
	{
		printf("Error: Unable to allocate memory.");
		return (1);
	}
	while (1)
	{
		char *token = (char *) malloc(size);
		if (token == NULL)
		{
			printf("Error: Unable to allocate memory.");
			return (1);
		}
		printf("$ ");
		getline(&command, &size, stdin);
		token = tokenizer(command, '\n', _strlen(command));
		argv[0] = token;
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(token, argv, envp) == -1)
				perror("Could not execve");
		}
		else
		{
			sleep(3);
			wait(&status);
			printf("\n");
		}
	}
	return (0);
}

char *tokenizer(char *string, char delimiter, int len)
{
	char *aux = (char *) malloc(len);
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (string[i] == delimiter)
			break;
		aux[i] = string[i];
	}
	aux[i] = '\0';
	return (aux);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
