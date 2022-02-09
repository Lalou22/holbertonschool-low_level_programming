/*
 * File: 7-leet.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * leet - Encodes a string into 1337.
 * @s: Pointer to string.
 *
 * Description: Encodes using Leetspeak 
 * https://en.wikipedia.org/wiki/Leet
 * Return: Encoded strings.
 */
char *leet(char *s)
{
	int i, j;
	char a[] = "aAeEoOtTlL";
	char b[] = "4433007711";

	for (i = 0; *(s + i); i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (a[j] == *(s + i))
			{
				*(s + i) = b[j];
				break;
			}
		}
	}
	return (s);
}
