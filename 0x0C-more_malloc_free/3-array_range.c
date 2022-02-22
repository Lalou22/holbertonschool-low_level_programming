/*
 * File: 3-array_range.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * array_range - Function that creates an array of integers.
 * @min: Min integer to be included on the array.
 * @max: Max integer to be included on the array.
 *
 * Description: The array created should contain all the values from
 * min (included) to max (included), ordered from min to max.
 * Return: Int pointer to the allocated memory array.
 */
int *array_range(int min, int max)
{
	int *res;
	int i, len;

	if (min > max)
		return (NULL);
	len = max - min + 1;
	res = malloc(len * sizeof(int));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		res[i] = min + i;
	return (res);
}
