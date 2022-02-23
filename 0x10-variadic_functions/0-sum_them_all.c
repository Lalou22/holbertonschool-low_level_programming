/*
 * File: 0-sum_them_all.c
 * Auth: Lalo Rdz
 */
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - Function that returns the sum of all its parameters.
 * @n: Number of elements to be sum.
 * @...: Elemets to be sum.
 *
 * Description: Function that sum all its parameters.
 * Return: Sum.
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;
	va_list valist;

	va_start(valist, n);
	for (i = 0; i < n; i++)
		sum += va_arg(valist, int);
	va_end(valist);
	return (sum);
}
