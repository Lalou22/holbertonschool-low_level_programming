/*
 * File: 5-sqrt_recursion.c
 * Auth: Lalo Rdz
 */
#include "main.h"
int check_int(int x, int n);
/**
 * _sqrt_recursion - Calculates the natural square Root.
 * @n: Integer to be tested.
 *
 * Description: Returns the natural square root of a number.
 * Run man sqrt to learn more.
 * Return: Returns the natural square root, -1 otherwise.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (check_int(1, n));
}
/**
 * check_int - Calculates if x is the natural square Root of n.
 * @x: Integer used on the test.
 * @n: Integer to be tested.
 *
 * Description: Checks for x.
 * Return: Returns the natural square root, -1 otherwise.
 */
int check_int(int x, int n)
{
	if (x * x == n)
		return (x);
	if (x * x > n)
		return (-1);
	return (check_int(x + 1, n));
}
