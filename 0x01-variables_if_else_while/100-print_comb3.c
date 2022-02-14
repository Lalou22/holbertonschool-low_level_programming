/*
 * File: 100-print_comb3.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Prints all possible different combinations of two digits.
 *
 * Description: The two digits must be different.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int dec = 48;
	int unit;

	while (dec <= 57)
	{
		unit = dec + 1;
		while (unit <= 57)
		{
			if (dec != unit)
			{
				putchar(dec);
				putchar(unit);
				if (dec != 56 || unit != 57)
				{
					putchar(44);
					putchar(' ');
				}
			}
			unit++;
		}
		dec++;
	}
	putchar('\n');
	return (0);
}
