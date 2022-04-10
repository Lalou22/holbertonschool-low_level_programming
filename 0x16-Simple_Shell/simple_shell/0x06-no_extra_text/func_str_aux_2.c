#include "shell.h"

/**
 * _strncmp - Write a function that compares two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Description: The standard library provides a similar function: strcmp.
 * Run man strcmp to learn more.
 * Return: Outputs the difference of s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
