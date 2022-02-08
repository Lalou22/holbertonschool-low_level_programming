/*
 * File: 10-print_triangle.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_triangle - Prints a triangle.
 * @size: Size of the triangle.
 * Description: Prints a triangle, followed by a new line.
 * Return: void
 */
void print_triangle(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size - i - 1; j++)
				_putchar(' ');
			for (; j < size; j++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
