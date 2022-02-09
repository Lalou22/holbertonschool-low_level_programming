/*
 * File: 7-puts_half.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * puts_half - Prints half of a string,
 * @str: Pointer to the char string.
 *
 * Description: Function that prints half of a string, followed by a new line.
 * Return: void
 */
void puts_half(char *str)
{
	int lenght = 0;
	int i, n;

	while (str[lenght] !=  '\0')
		lenght++;

	if ((lenght % 2) == 0)
		n = (lenght / 2);
	else
		n = ((lenght + 1) / 2);

	for (i = n; i < lenght; i++)
		_putchar(str[i]);
	_putchar('\n');
}
