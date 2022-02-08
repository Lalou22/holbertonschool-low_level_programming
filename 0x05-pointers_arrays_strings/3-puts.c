/*
 * File: 3-puts.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _puts  - Function that prints a string.
 * @str: Pointer to the char string.
 *
 * Description: The standard library provides a similar function: puts.
 * Run man puts to learn more.
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
