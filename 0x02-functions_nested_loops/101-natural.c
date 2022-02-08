/*
 * File: 101-natural.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Nature made the natural numbers
 *
 * Description: Find multiples of 3 and 5, then sums them.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, aux;

	aux = 8;
	for (i = 6; i <= 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			aux = aux + i;
	}
	printf("%d\n", aux);
	return (0);
}
