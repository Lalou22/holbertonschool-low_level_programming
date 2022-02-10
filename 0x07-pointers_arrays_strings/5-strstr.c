/*
 * File: 5-strstr.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strstr - Write a function that locates a substring.
 * @haystack: Pointer to destination string.
 * @needle: Pointer to second string to be found.
 *
 * Description: Finds the first occurrence of needle in haystack.
 * Run man strstr to learn more.
 * Return: Beginning of the located substring, or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i] !=  '\0')
	{
		while ((haystack[i] == needle[0]) && needle[j])
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break;
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
