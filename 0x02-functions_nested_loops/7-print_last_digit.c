/*
 * File: 7-print_last_digit.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_last_digit - Print and returns last digit.
 * @n: The int to be computed
 *
 * Description: Write a function that prints the last digit.
 * Return: Last digit
 */
int print_last_digit(int n)
{
	int last = n % 10;

	if (last < 0)
		last = last * -1;
	_putchar('0' + last);
	return (last);
}
