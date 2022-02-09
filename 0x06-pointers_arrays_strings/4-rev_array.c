/*
 * File: 4-rev_array.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * reverse_array - Reverses the content of an array of integers.
 * @a: Pointer to string.
 * @n: Size of the string.
 *
 * Description: function that reverses the content of an array of integers.
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0, t;

	n = n - 1;
	while (i < n)
	{
		t = *(a + i);
		*(a + i) = *(a + n);
		*(a + n) = t;
		i++;
		n--;
	}
}
