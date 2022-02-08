/*
 * File: 102-fibonacci.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Prints the first 50 Fibonacci numbers
 *
 * Description: 50 Fibonacci numbers, starting with 1 and 2, and new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a, b, aux;
	int i;

	a = 1;
	b = 2;
	printf("%ld, %ld", a, b);
	for (i = 0; i < 48; i++)
	{
		aux = b;
		b = a + b;
		a = aux;
		printf(", %ld", b);
	}
	printf("\n");
	return (0);
}
