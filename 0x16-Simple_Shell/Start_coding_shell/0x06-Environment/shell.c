/*
 * File: shell.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

	command = (char *) malloc(size);
	if (command == NULL)
	{
		printf("Error: Unable to allocate memory.");
		return (1);
	}
	while (1)
	{
		char **string_pointer = &command;

		printf("$ ");
		getline(string_pointer, &size, stdin);
		system(command);
		sleep(3);
		printf("\n");
	}
	return (0);
}


