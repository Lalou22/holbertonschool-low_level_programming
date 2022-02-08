/*
 * File: 4-print_rev.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_rev  - Function that prints a string, in reverse.
 * @s: Pointer to the char string.
 *
 * Description: function that prints a string, in reverse and a new line.
 * Return: void
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	i--;
	for (; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}
