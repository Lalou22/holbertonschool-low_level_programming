/*
 * File: 2-print_strings.c
 * Auth: Lalo Rdz
 */
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_strings - Function that prints strings, followed by a new line.
 * @separator: Char used to separate all the printed numbers.
 * @n: Number of elements to be printed.
 * @...: Elemets to be printed.
 *
 * Description: Function that prints all its "..." parameters.
 * Return: Void.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *element;
	va_list valist;

	va_start(valist, n);
	for (i = 0; i < n; i++)
	{
		element = va_arg(valist, char *);
		if (element)
			printf("%s", element);
		else
			printf("(nill)");
		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(valist);
}
