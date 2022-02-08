/*
 * File: 102-evenly_divisible.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Find smallest positive number that is evenly divisible
 *
 * Description: Finds evenly divisible by all of the numbers from 1 to 22.
 * Return: Always 0 (Success)
 */
#define max 22
int main(void)
{
	int i, j, temp;
	int aux = 1;
	int numbers[max];

	for (i = 0; i < max; i++)
		numbers[i] = i + 1;

	for (i = 0; i < max; i++)
	{
		temp = numbers[i];
		for (j = i; j < max; j++)
		{
			if(numbers[j] % temp == 0)
				numbers[j] = numbers[j] / temp;
		}
		aux = aux * temp;
	}
	printf("%d\n", aux);
	return (0);
}
