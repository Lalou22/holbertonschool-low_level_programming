/*
 * File: 3-alloc_grid.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * alloc_grid - Returns a pointer to a 2 dimensional array of integers.
 * @width: Columns.
 * @height: Rows.
 *
 * Description: Write a function that returns a pointer to a
 * 2 dimensional array of integers.
 * Each element of the grid should be initialized to 0.
 * If width or height is 0 or negative, return NULL
 * Return: Array of integers.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **a;

	if (width <= 0 || height <= 0)
		return (NULL);
	a = (int **)malloc(height * sizeof(int *));
	if (a == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		a[i] = (int *)malloc(width * sizeof(int));
		if (a[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(a[j]);
			free(a);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			a[i][j] = 0;
	}
	return (a);
}
