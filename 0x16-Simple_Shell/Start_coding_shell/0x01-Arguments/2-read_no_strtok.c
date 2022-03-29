/*
 * File: 2-read_no_strtok.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>

char* _strtok(char* s, char d);
int _strlen(char *s);

/**
 * main - Write a function that splits a string on an array.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Write a function that splits a string and returns an array of each word
 * of the string. No using strtok.
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
		token = _strtok(string, ' ');
		while( token != NULL )
		{
			printf( "%s\n", token);
			token = _strtok(NULL, ' ');
		}
	}
	return (0);
}

/**
 * _strtok - function that breaks string into tokens using the delimiter.
 * @s: String to be breaked.
 * @d: Character used as a delimiter.
 *
 * Function that breaks a string into a series of tokens using the 
 * delimiter delim. Similar to the standard strtok.
 * Return: Pointer to the first token found in the string.
 */
char* _strtok(char* s, char d)
{
	static char* input = NULL;

	if (s != NULL)
		input = s;
	if (input == NULL)
		return NULL;

	char* result = (char *) malloc(_strlen(input) + 1);
	int i = 0;

	for (; input[i] != '\0'; i++)
	{
		if (input[i] != d)
		{
			result[i] = input[i];
		}
		else
		{
			result[i] = '\0';
			input = input + i + 1;
			return result;
		}
	}

	result[i] = '\0';
	input = NULL;
	return (result);
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

	while (s[i] != '\0')
		i++;
	return (i);
}
