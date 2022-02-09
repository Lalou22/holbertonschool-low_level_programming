/*
 * File: 5-string_toupper.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * string_toupper - Changes lowercase to uppercase.
 * @s: Pointer to string.
 *
 * Description: function that reverses the content of an array of integers.
 * Return: void
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
			*(s + i) += 'A' - 'a';
		i++;
	}
	return (s);
}
