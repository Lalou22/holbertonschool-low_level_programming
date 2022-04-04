/*
 * File: 1-shell.c
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
	char *line; /* Char array pointer. */
	char **args;
	char *envp[] = {NULL};
	int status;
	pid_t child_pid;

	while (1)
	{
		printf("$ ");
		/* Modification for test */
		line = read_line();
		args = split_line(line);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(args[0], args, envp) == -1)
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
