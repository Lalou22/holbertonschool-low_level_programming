/*
 * File: 2-getenv.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
char *_getenv(const char *name);
int starts_with(char *haystack, const char *needle);
char *_getpath(char *dir_);

/**
 * main - Write a function that gets an environment variable.
 *
 * Description: Write a function that gets an environment variable.
 * Without using getenv.
 * Return: Always 0.
 */
int main(void)
{
	printf("-----Using standard getenv-----\n");
	printf("PATH: %s\n", getenv("PATH"));
	printf("HOME: %s\n", getenv("HOME"));
	printf("ROOT: %s\n", getenv("ROOT"));
	printf("\n");
	printf("-----Using _getenv-----\n");
	printf("PATH: %s\n", _getenv("PATH"));
	printf("HOME: %s\n", _getenv("HOME"));
	printf("ROOT: %s\n", _getenv("ROOT"));
	printf("\n");
	return (0);
}

/**
 * _getenv - Function that gets an environment variable.
 * @name: String with the environment variable.
 *
 * Description: Function that gets an environment variable.
 * Without using getenv.
 * Return: Environment variable, or NULL.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		if (starts_with(environ[i], name) != 0)
			return (_getpath(environ[i]));
		i++;
	}
	return (NULL);
}

/**
 * starts_with - Function that locates if the string starts with needle.
 * @haystack: Pointer to destination string.
 * @needle: Pointer to second string to be found.
 *
 * Description: Finds if the haystack starts with needle.
 * Return: 0 if not found or 1 otherwise.
 */
int starts_with(char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack++ != *needle++)
			return (0);
	}
	return (1);
}

/**
 * _getpath - Function that locates the = and returns remainding text.
 * @dir_: Pointer to directory file.
 *
 * Description: Write a function that locates the = and returns all the next
 * text, after the symbol.
 * Return: Located substring, or NULL.
 */
char *_getpath(char *dir_)
{
	while (*dir_)
	{
		if (*dir_++ == '=')
			return (dir_++);
	}
	return (NULL);
}
