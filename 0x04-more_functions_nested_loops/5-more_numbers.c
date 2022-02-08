/*
 * File: 5-more_numbers.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * more_numbers - Prints 10 times the numbers, from 0 to 14.
 * Description: Prints numbers followed by new line.
 * Return: void
 */
void more_numbers(void)
{
	int i, j, aux;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (j > 9)
			{
				aux = j / 10;
				_putchar(aux + 48);
			}
			aux = j % 10;
			_putchar(aux + 48);
		}
		_putchar('\n');
	}
}
