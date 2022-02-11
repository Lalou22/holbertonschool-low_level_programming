/*
 * File: 4-pow_recursion.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _pow_recursion - value of x raised to the power of y.
 * @x: Integer base.
 * @y: Integer power.
 *
 * Description: returns the value of x raised to the power of y.
 * Run man pow to learn more.
 * Return: Returns the factorial, -1 otherwise.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
