/*
 * File: 3-strspn.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strspn - Write a function that gets the length of a prefix substring.
 * @s: Char string pointer.
 * @accept: Character to be searched.
 *
 * Description: Gets the length of a prefix substring.
 * Run man strspn to learn more.
 * Return: Number of bytes in s which consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (!accept[j])
			break;
	}
	return (i);
}
