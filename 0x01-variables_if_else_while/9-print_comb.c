/*
 * File: 9-print_comb.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Write a program that prints all possible combinations of single-digit numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 48;
	while (number <= 57)
	{
		putchar(number);
		if (number != 57)
		{
			putchar(44);
			putchar(' ');
		}	
		number++;
	}
	putchar('\n');
	return (0);
}
