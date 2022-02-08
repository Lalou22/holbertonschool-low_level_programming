/*
 * File: 6-print_line.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_line - Draws a straight line in the terminal.
 * @n: number of times the character _ should be printed
 * Description: Draws a straight line in the terminal.
 * Return: void
 */
void print_line(int n)
{
	if (n > 0)
	{
		int i;

		for (i = 0; i < n; i++)
			_putchar('_');
	}
	_putchar('\n');
}
