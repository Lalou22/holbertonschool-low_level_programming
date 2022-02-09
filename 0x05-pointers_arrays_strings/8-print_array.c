/*
 * File: 8-print_array.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_array - Prints n elements of an array of integers.
 * @a: Pointer to the Int array.
 * @n: Number of ints to be printed.
 *
 * Description: Function that prints n elements of an array of integers.
 * Return: void
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i != n - 1)
			printf(", ");
	}
	putchar('\n');
}
