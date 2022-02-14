/*
 * File: 4-add.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Write a program that adds positive numbers.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: Print the result, followed by a new line.
 * If no number is passed to the program, print 0, followed by a new line.
 * If one of the number contains symbols that are not digits, print Error,
 * followed by a new line, and return 1.
 * Return: Zero.
 */
int main(int argc, char *argv[])
{
	int i, j, res = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		res += atoi(argv[i]);
	}
	printf("%d\n", res);
	return (0);
}
