/*
 * File: 1-strdup.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * _strdup - Returns a pointer to a newly allocated space in memory.
 * @str: String given.
 *
 * Description: Write a function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the string given
 * as a parameter.
 * Run man strdup to learn more.
 * Return: NULL if str = NULL, otherwise returns pointer.
 */
char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	i++;
	s = malloc(i * sizeof(char));
	if (str == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		s[j] = str[j];
	return (s);
}
