/*
 * File: shell.c
 * Auth: Lalo Rdz
 */
#include "shell.h"
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
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		{
			sleep(3);
			wait(&status);
		}
	}
	return (0);
}
