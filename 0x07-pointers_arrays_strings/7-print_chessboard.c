/*
 * File: 7-print_chessboard.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * print_chessboard - Write a function that prints the chessboard.
 * @a: Pointer to chessboard made from chars.
 *
 * Description: Prints actual state of the chessboards.
 * Return: NULL.
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
