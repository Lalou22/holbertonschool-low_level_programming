/*
 * File: 100-prime_factor.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>

int is_prime(long int i);
/**
 * main - Finds and prints the largest prime factor
 *
 * Description: Finds and prints the largest prime factor of 612852475143.
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int aux;
	long int i = 2;
	long int limit = 612852475143;

	while ((long)(i * i) <= limit)
	{
		if (is_prime(i) == 1)
			aux = i;
		i++;
	}
	printf("%ld\n", aux);
	return (0);
}

/**
 * is_prime - Checks if int is prime
 * @i: Int to be tested
 *
 * Description: Cheks if an integer is prime.
 * Return: 1 is prime, 0 otherwise
 */
int is_prime(long int i)
{
	long int j;

	for (j = 2; j < i; j++)
	{
		if (i % j == 0)
			return (0);
	}
	return (1);
}
