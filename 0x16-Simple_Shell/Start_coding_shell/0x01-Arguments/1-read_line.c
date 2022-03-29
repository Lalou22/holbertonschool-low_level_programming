/*
 * File: 1-read_line.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Write a program that wait for the user to enter a command and prints.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Write a program that prints "$ ", wait for the user to enter a command,
 * prints it on the next line.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *string; /* Char array pointer. */
	size_t size = 100; /* Initial size of char array. */

	string = (char *) malloc(size);
	if (string == NULL)
	{
		printf("Error: Unable to allocate memory.");
		exit(1);
	}
	else
	{
		char **string_pointer = &string;

		printf("$ ");
		getline(string_pointer, &size, stdin);
		printf("%s", string);
	}
	return (0);
}
