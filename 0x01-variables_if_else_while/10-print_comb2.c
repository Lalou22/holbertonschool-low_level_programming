/*
 * File: 10-print_comb2.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Write a program that prints the numbers from 00 to 99.
 *
 * Description: Prints.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int dec = 48;
	int unit;

	while (dec <= 57)
	{
		unit = 48;
		while (unit <= 57)
		{
			putchar(dec);
			putchar(unit);
			if (dec != 57 || unit != 57)
			{
				putchar(44);
				putchar(' ');
			}
			unit++;
		}
		dec++;
	}
	putchar('\n');
	return (0);
}
