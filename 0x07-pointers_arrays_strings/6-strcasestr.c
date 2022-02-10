/*
 * File: 6-strcasestr.c
 * Auth: Lalo Rdz
 */
#include "main.h"
int check_c(char c1, char c2);
/**
 * _strcasestr - Write a function that locates a substring.
 * @haystack: Pointer to destination string.
 * @needle: Pointer to second string to be found.
 *
 * Description: Finds the first occurrence of needle in haystack.
 * Run man strcasestr to learn more.
 * Return: Beginning of the located substring, or NULL.
 */
char *_strcasestr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (((check_c(haystack[i], needle[0]) == 1)) && needle[j])
		{
			if (check_c(haystack[i + j], needle[j]) == 1)
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (needle[j] !=  '\0')
		{
			i++;
			j = 0;
		}
		else
			return (haystack + i);
	}
	return (0);
}
/**
 * check_c - Function compares 2 Chars, ignoring upper and lower.
 * @c1: First char.
 * @c2: Second char.
 *
 * Description: Compares two different chars.
 * Return: Returns 1 when equal, zero otherwise.
 */
int check_c(char c1, char c2)
{
	if (c1 >= 'a' && c1 <= 'z')
	{
		if (c1 == c2 || c1 == c2 - ('A' - 'a'))
			return (1);
	}
	else if (c1 >= 'A' && c1 <= 'Z')
	{
		if (c1 == c2 || c1 == c2 + ('A' - 'a'))
			return (1);
	}
	else if (c1 == c2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
