/*
 * File: 2-read_line_av.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Write a function that splits a string on an array.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Write a function that splits a string and returns an array of each word
 * of the string. man strtok
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
		char *token;

		printf("$ ");
		getline(string_pointer, &size, stdin);
		token = strtok(string, " ");
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}
	return (0);
}
