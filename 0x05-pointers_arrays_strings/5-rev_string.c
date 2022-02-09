/*
 * File: 5-rev_string.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * rev_string - Function that reverses a string.
 * @s: Pointer to the char string.
 *
 * Description: Function that reverses a string.
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0;
	int j;
	char aux;

	while (s[i] != '\0')
		i++;
	i--;
	for (j = 0; j <= i / 2; j++)
	{
		aux = s[i - j];
		s[i - j] = s[j];
		s[j] = aux;
	}
}
