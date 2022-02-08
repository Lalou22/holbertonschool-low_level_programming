#include "main.h"
/**
 * print_sign - Check if a int is post, negt or zero
 * @n: The int to be checked
 *
 * Description: Write a function that prints the sign of a number.
 * Return: -1, 1 or 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	return (0);
}
