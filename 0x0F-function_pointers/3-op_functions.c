/*
 * File: 3-op_functions.c
 * Auth: Lalo Rdz
 */

#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Returns the sum of two numbers.
 * @a: The first integer number.
 * @b: The second integer number.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the substraction of two numbers.
 * @a: The first integer number.
 * @b: The second integer number.
 *
 * Return: The substraction of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the multiplication of two numbers.
 * @a: The first integer number.
 * @b: The second integer number.
 *
 * Return: The multiplication of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the integer division of two numbers.
 * @a: The first integer number.
 * @b: The second integer number.
 *
 * Return: The integer division of a and b.
 */
int op_div(int a, int b)
{
	if (b == 0) /*Checks for posible zero division errors*/
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}
/**
 * op_mod - Returns the remainder of the integer division of two numbers.
 * @a: The first integer number.
 * @b: The second integer number.
 *
 * Return: The remainder of a and b.
 */
int op_mod(int a, int b)
{
	if (b == 0) /*Checks for posible zero division errors*/
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
