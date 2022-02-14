/*
 * File: 100-change.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of coins to change an amount of money.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: prints the minimum number of coins.
 * If the number of arguments passed to your program is not exactly 1,
 * print Error, followed by a new line, and return 1.
 * If the number passed as the argument is negative, print 0,
 * followed by a new line.
 * Return: Zero.
 */
int main(int argc, char *argv[])
{
	int coins[5] = {25, 10, 5, 2, 1};
	int n = 0;
	int t, v, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	v = atoi(argv[1]);
	if (v > 0)
	{
		for (i = 0; i < 5; i++)
		{
			t = v / coins[i];
			v = v - (t * coins[i]);
			n = n + t;
			if (v == 0)
				break;
		}
	}
	printf("%d\n", n);
	return (0);
}
