/*
 * File: 0-puts_recursion.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _puts_recursion - Prints a string, followed by a new line.
 * @s: Pointer to string.
 *
 * Description: Prints a string using recursion.
 * Return: NULL.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
