/*
 * File: 9-times_table.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * times_table - Prints the 9 times table.
 *
 * Description: Write a function that prints the 9 times table, starting 0.
 * Return: void
 */
void times_table(void)
{
	int i, j, aux;

	for (i = 0; i < 10; i++)
	{
		_putchar('0');
		for (j = 1; j < 10; j++)
		{
			_putchar(',');
			_putchar(' ');
			aux = i * j;
			if (aux >= 10)
				_putchar((aux / 10) + 48);
			else
				_putchar(' ');
			_putchar((aux % 10) + 48);
		}
		_putchar('\n');
	}
}
