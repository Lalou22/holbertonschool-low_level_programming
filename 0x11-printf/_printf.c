/*
 * File: _printf.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "main.h"
/**
 * _printf - Function that produces output according to a format.
 * @format: Character string composed of zero or more directives.
 * @...: Variadic function arguments used to describe the format used to print.
 *
 * Description: man 3 printf for more detail.
 * Return: Number of characters printed (count).
 */
int _printf(const char *format, ...)
{
	unsigned int index = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);

	while (format[index])
	{
		/* Prints the chars with no special format */
		for (; format[index] && format[index] != '%'; index++)
		{
			_putchar(format[index]);
			count++;
		}

		/* Returns when the "format" ends */
		if (!format[index])
			return (count);

		/* Any format used is composed of at least two chars */
		/* First char "%" and the second is a symbol */
		f = check_format(&format[index + 1]);

		/* Applies the correct function for the symbol used */
		if (f != NULL)
		{
			count += f(valist);
			index += 2;
			continue;
		}
		else
		{
			if (format[index + 1] == '\0')
				return (-1);

			_putchar('%');
			count++;
			if (format[index + 1] != '%')
			{
				_putchar(format[index + 1]);
				count++;
			}
			index += 2;
			continue;
		}
	}

	va_end(valist);
	return (count);
}
