/*
 * File: 6-is_prime_number.c
 * Auth: Lalo Rdz
 */
#include "main.h"
int check_prime(int x, int n);
/**
 * is_prime_number - Check if prime.
 * @n: Integer to be tested.
 *
 * Description: Test if n is prime.
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (check_prime(2, n));
}
/**
 * check_prime - Calculates if x is a factor of n.
 * @x: Integer used on the test.
 * @n: Integer to be tested.
 *
 * Description: Checks for x.
 * Return: Returns zero if factor, 1 otherwise.
 */
int check_prime(int x, int n)
{
	if (n % x == 0 && x < n)
		return (0);
	if (n == x)
		return (1);
	return (check_prime(x + 1, n));
}
