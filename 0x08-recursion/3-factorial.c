/*
 * File: 3-factorial.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * factorial - Factorial of a integer.
 * @n: Integer.
 *
 * Description: Write a function that returns the factorial of a given number.
 * Return: Returns the factorial.
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (1);
	return (n * factorial(n - 1));
}
