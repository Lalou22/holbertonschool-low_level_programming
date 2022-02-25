/*
 * File: 1-print_numbers.c
 * Auth: Lalo Rdz
 */
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - Function that prints numbers, followed by a new line.
 * @separator: Char used to separate all the printed numbers.
 * @n: Number of elements to be printed.
 * @...: Elemets to be printed.
 *
 * Description: Function that prints all its "..." parameters.
 * Return: Void.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	int element;
	va_list valist;

	va_start(valist, n);
	for (i = 0; i < n; i++)
	{
		element = va_arg(valist, int);
		printf("%d", element);
		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(valist);
}
