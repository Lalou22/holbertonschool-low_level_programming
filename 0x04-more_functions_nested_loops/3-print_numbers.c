/*
 * File: 2-mul.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_numbers - Prints the numbers, from 0 to 9
 * Description: Prints numbers followed by new line.
 * Return: void
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
		_putchar(i + 48);
	_putchar('\n');
}
