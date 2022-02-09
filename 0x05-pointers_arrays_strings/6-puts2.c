/*
 * File: 6-puts2.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * puts2 - Prints every other character of a string.
 * @str: Pointer to the char string.
 *
 * Description: Function that prints every other character of a string.
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;
	int j;

	while (str[i] != '\0')
		i++;
	for (j = 0; j < i; j += 2)
	{
		_putchar(str[j]);
	}
	_putchar('\n');
}
