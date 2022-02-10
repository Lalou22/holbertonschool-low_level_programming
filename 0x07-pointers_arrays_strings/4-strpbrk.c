/*
 * File: 4-strpbrk.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strpbrk - Write a function that searches a string for any of a set of bytes.
 * @s: Char string pointer.
 * @accept: Character to be searched.
 *
 * Description: Locates first occurrence in s of any bytes in accept.
 * Run man strpbrk to learn more.
 * Return: Pointer to the byte in s that matches or NULL.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j])
			return (s + i);
	}
	return (0);
}
