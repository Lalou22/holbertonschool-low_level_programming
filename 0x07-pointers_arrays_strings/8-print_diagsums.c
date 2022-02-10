/*
 * File: 8-print_diagsums.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to square matrix.
 * @size: Number of rows (and columns).
 *
 * Description: Prints the sum of the two diagonals.
 * Return: NULL.
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + ((i * size) + i));
		sum2 += *(a + ((i * size) + (size - 1 - i)));
	}
	printf("%i, %i\n", sum1, sum2);
}
