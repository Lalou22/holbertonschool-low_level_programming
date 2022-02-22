/*
 * File: 1-array_iterator.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * array_iterator - Executes a function given as a parameter on each element.
 * @array: Pointer to the integer array.
 * @size: Quantity of elements to iterate.
 * @action: Function to be aplied to each element of the array.
 *
 * Description: Function that executes a function given as a parameter
 * on each element of an array.
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
