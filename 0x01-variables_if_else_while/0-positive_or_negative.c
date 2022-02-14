/*
 * File: 0-positive_or_negative.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Assign a random number to the variable n each time it is executed.
 *
 * Description: Positive anything is better than negative nothing.
 * Return: Zero.
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
/* your code goes there */
	if (n > 0)
		printf("%d is positive\n", n);
	if (n < 0)
		printf("%d is negative\n", n);
	if (n == 0)
		printf("%d is zero\n", n);
	return (0);
}
