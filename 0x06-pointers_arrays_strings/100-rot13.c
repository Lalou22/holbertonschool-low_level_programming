/*
 * File: 100-rot13.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * rot13 - Encodes a string using rot13.
 * @s: Pointer to string.
 *
 * Description: Encodes using Rotate by 13 places. 
 * https://en.wikipedia.org/wiki/ROT13
 * Return: Encoded strings.
 */
char *rot13(char *s)
{
	int i, j;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(s + i); i++)
	{
		for (j = 0; j < 52; j++)
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
