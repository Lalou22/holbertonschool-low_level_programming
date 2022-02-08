/*
 * File: 8-print_square.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_square - Prints a square.
 * @size: Size of the square
 * Description: Prints a square, followed by a new line.
 * Return: void
 */
void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
