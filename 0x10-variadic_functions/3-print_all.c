/*
 * File: 3-print_all.c
 * Auth: Lalo Rdz
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
 * print_c - Print a Char.
 * @element: Char to print.
 *
 * Description: Print a Char send by the funcion print_all.
 * Return: Void.
 */
void print_c(va_list element)
{
	printf("%c", va_arg(element, int));
}

/**
 * print_s - Print a String.
 * @element: String to print.
 *
 * Description: Print a String send by the funcion print_all.
 * Return: Void.
 */
void print_s(va_list element)
{
	char *str = va_arg(element, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_i - Print a Integer.
 * @element: Int to print.
 *
 * Description: Print a Integer send by the funcion print_all.
 * Return: Void.
 */
void print_i(va_list element)
{
	printf("%d", va_arg(element, int));
}

/**
 * print_f - Print a Float.
 * @element: Float to print.
 *
 * Description: Print a Float send by the funcion print_all.
 * Return: Void.
 */
void print_f(va_list element)
{
	printf("%f", va_arg(element, double));
}

/**
 * print_all - Function that prints "anything", followed by a new line.
 * @format: List of types of arguments passed to the function.
 * @...: Elemets to be printed.
 *
 * Description: Prints variadic arguments, for char, integer, float, strings.
 * Return: Void.
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0, j; /* Iterators */
	char *separator = ", ";
	print_functions printer[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"f", print_f},
		{NULL, NULL}
	};
	va_list valist;

	va_start(valist, format);
	while (format != NULL && format[i])
	{
		j = 0;
		while (printer[j].c)
		{
			if (*(printer[j].c) == format[i])
			{
				printer[j].f(valist);
				break;
			}
			j++;
		}
		if ((format[i + 1]) != '\0' && printer[j].c != NULL)
			printf("%s", separator);
		i++;
	}
	va_end(valist);
	printf("\n");
}
