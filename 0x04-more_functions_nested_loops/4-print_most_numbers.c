/*
 * File: 4-print_most_numbers.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_most_numbers - Prints most of the numbers, from 0 to 9
 * Description: Do not print 2 and 4.
 * Return: void
 */
void print_most_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i != 2 && i != 4)
			_putchar(i + 48);
	}
	_putchar('\n');
}
