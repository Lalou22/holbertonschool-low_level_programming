/*
 * File: 1-print_binary.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_binary - Function that prints the binary representation of a number.
 * @n: Unsigned long int to be printed as a binary.
 *
 * Description: Function that prints the binary using recursion and bit shift.
 * Not allowed to use arrays, malloc, '% operator' or '/ operator'.
 * Return: Void.
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
