/*
 * File: 7-print_diagonal.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_diagonal - Draws a diagonal line on the terminal.
 * @n: number of times the character _ should be printed
 * Description: Draws a diagonal line in the terminal.
 * Return: void
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
