/*
 * File: format_printer.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "main.h"
/**
 * check_format - Gets the existance of a selected format.
 * @format: Character string composed of zero or more directives.
 *
 * Description: Checks if the format-char exist on the possibilities list.
 * Return: Number of characters printed (count).
 */
int (*check_format(const char *format))(va_list)
{
	unsigned int index;
	print_t printer[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"b", print_bin},
		{"u", print_unsigned_int},
		{"o", print_oct},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},
		{"p", print_p},
		{"r", print_r},
		{NULL, NULL}
	};

	for (index = 0; printer[index].t != NULL; index++)
	{
		if (*(printer[index].t) == *format)
			break;
	}
	return (printer[index].f);
}
/**
 * print_char - Prints a given char.
 * @c: Character to be printed.
 *
 * Description: Prints the char using _putchar and returns +1 to the count.
 * Return: 1.
 */
int print_char(va_list c)
{
	char letter = (char)va_arg(c, int);

	_putchar(letter);
	return (1);
}
/**
 * print_string - Prints a given str.
 * @s: Characters (string) to be printed.
 *
 * Description: Prints the strings using a loop and the _putchar.
 * Return: Character count of the string.
 */
int print_string(va_list s)
{
	unsigned int count = 0;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (; str[count]; count++)
		_putchar(str[count]);
	return (count);
}
/**
 * print_int - Prints a given int.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints ints using recursion.
 * Return: Character count of the int.
 */
int print_int(va_list i)
{
	int number = va_arg(i, int);
	int count = 0;
	unsigned int n;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	if (number < 0)
	{
		_putchar('-');
		count++;
		number = number * -1;
	}
	n = number;
	count += print_int_recursion(n, 10, 0);
	return (count);
}
/**
 * print_bin - Prints a given int as a binary number.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints bin using recursion.
 * Return: Character count of the int.
 */
int print_bin(va_list i)
{
	unsigned int number = va_arg(i, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_int_recursion(number, 2, 0);
	return (count);
}
/**
 * print_unsigned_int - Prints a given int as a unsigned int.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints oct using recursion.
 * Return: Character count of the int.
 */
int print_unsigned_int(va_list i)
{
	unsigned int number = va_arg(i, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_int_recursion(number, 10, 0);
	return (count);
}
/**
 * print_oct - Prints a given int as an oct.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints oct using recursion.
 * Return: Character count of the int.
 */
int print_oct(va_list i)
{
	unsigned int number = va_arg(i, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_int_recursion(number, 8, 0);
	return (count);
}
/**
 * print_x - Prints a given int as an hex with lowercase.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints hex using recursion.
 * Return: Character count of the int.
 */
int print_x(va_list i)
{
	unsigned int number = va_arg(i, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_int_recursion(number, 16, 1);
	return (count);
}
/**
 * print_X - Prints a given int as an hex with uppercase.
 * @i: Characters (int) to be printed.
 *
 * Description: Calls for the function that prints hex using recursion.
 * Return: Character count of the int.
 */
int print_X(va_list i)
{
	unsigned int number = va_arg(i, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_int_recursion(number, 16, 2);
	return (count);
}
/**
 * print_int_recursion - Prints a given int on base 2, 8, 10.
 * @n: Int to be printed.
 * @base: Base of the convertion, if base 10 prints int number by number.
 * @selector: Variable used for the Upper/lower case on the hex convert.
 *
 * Description: Using recursion prints and counts the elements of an int.
 * Return: Character count of the int.
 */
int print_int_recursion(unsigned int n, int base, int selector)
{
	int count = 0;
	unsigned int number = n;
	char diff;

	switch (selector)
	{
	case 1:
		diff = '0' + 'a' - ':';
		break;
	case 2:
		diff = '0' + 'A' - ':';
		break;
	default:
		diff = '0';
		break;
	}

	if ((number / base == 0) && (number % base == 0))
	{
		return (0);
	}
	else
	{
		count += 1 + print_int_recursion(number / base, base, selector);
		if (number % base < 10)
			_putchar('0' + number % base);
		else
			_putchar(diff + number % base);
	}
	return (count);
}
/**
 * print_S - Prints a string with custom conversion specifier.
 * @S: Int to be printed.
 *
 * Description: Non printable characters (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters).
 * Return: Count of the printed characters.
 */
int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_two_hex(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_two_hex - Prints a int to hex with custom conversion specifier.
 * @c: Char to be printed.
 *
 * Description: prints a char's ascii value in two digit uppercase hex.
 * Return: Count of the printed characters (Always 2).
 */
int print_two_hex(char c)
{
	int count;
	char diff = 'A' - ':';
	char num[2];

	num[0] = c / 16;
	num[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (num[count] >= 10)
			_putchar('0' + diff + num[count]);
		else
			_putchar('0' + num[count]);
	}
	return (count);
}
/**
 * print_p - Prints a memory address.
 * @p: Address to be printed.
 *
 * Description: Print characters 0 and x, then the memory address in Hex.
 * Return: Count of the printed characters.
 */
int print_p(va_list p)
{
	int count = 0;
	unsigned long n;
	char *str = "(nil)";
	unsigned int *parts;

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (; str[count]; count++)
			_putchar(str[count]);
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	parts  = (unsigned int *) &n;
	count += print_int_recursion(parts[1], 16, 1);
	count += print_int_recursion(parts[0], 16, 1);
	return (count);
}
/**
 * print_r - Prints a reversed string.
 * @r: String to be printed.
 *
 * Description: Print characters on reverse order.
 * Return: Count of the printed characters.
 */
int print_r(va_list r)
{
	char *str;
	int len = 0, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (; str[len]; len++)
		;
	for (len--; len >= 0; len--)
	{
		_putchar(str[len]);
		count++;
	}
	return (count);
}
