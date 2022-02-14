/*
 * File: 4-free_grid.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * free_grid - Function that frees a 2 dimensional grid.
 * @grid: Integers grid.
 * @height: Rows.
 *
 * Description: Write a function that frees a 2 dimensional grid
 * previously created.
 * Return: None.
 */
void free_grid(int **grid, int height)
{
	int row;

	if (grid == NULL || height <= 0)
		return;
	for (row = 0; row < height; row++)
		free(grid[row]);
	free(grid);
}
