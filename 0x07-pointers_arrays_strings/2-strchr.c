/*
 * File: 2-strchr.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strchr - Write a function that locates a character in a string.
 * @s: Char string pointer.
 * @c: Character to be searched.
 *
 * Description: First occurrence of the character c in the string s, or NULL.
 * Run man strchr to learn more.
 * Return: A pointer.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}
