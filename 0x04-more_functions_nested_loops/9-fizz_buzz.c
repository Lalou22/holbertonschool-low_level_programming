/*
 * File: 9-fizz_buzz.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Fizz-Buzz test
 *
 * Description: Write a program that prints the numbers from 1 to 100 or text.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	printf("0");
	for (i = 1; i < 100; i++)
	{
		printf(" ");
		if (i % 3 != 0 && i % 5 != 0)
			printf("%d", i);
		if (i % 3 == 0)
			printf("Fizz");
		if (i % 5 == 0)
			printf("Buzz");
	}
	printf("\n");
	return (0);
}
