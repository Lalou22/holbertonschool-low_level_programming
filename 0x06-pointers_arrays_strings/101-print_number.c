/*
 * File: 101-print_number.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_number - Write a function that prints an integer.
 * @n: Int to be printed.
 * Description: You can only use _putchar function to print.
 * Return: void
 */
void print_number(int n)
{
	int multi = 10;
	
	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	while (n / multi != 0)
		multi = multi * 10;
	while (multi >= 10)
	{
		multi = multi / 10;
		_putchar((n / multi) + 48);
		n = n % multi;
	}
}
