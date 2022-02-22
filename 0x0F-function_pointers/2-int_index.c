/*
 * File: 2-int_index.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * int_index - Function that searches for an integer.
 * @array: Pointer to the integer array.
 * @size: Quantity of elements to iterate.
 * @cmp: Function to be aplied to compare elements of the array.
 *
 * Description: Function that searches for an integer using different
 * functions to compare.
 * Return: void
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size < 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
