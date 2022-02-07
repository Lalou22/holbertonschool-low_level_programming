/*
 * File: 4-print_alphabt.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Print all the letters except q and e.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int dec_1, unit_1, dec_2, unit_2;
	/**
	* dec_1, unit_1, dec_2, unit_2
	*
	* Description: Variables used form decimals and units
	*/
	dec_1 = 48;
	while (dec_1 <= 57)
	{
		unit_1 = 48;
		while (unit_1 <= 57)
		{
			dec_2 = dec_1;
			while (dec_2 <= 57)
			{
				if (dec_1 == dec_2)
					unit_2 = unit_1 + 1;
				else
					unit_2 = 48;
				while (unit_2 <= 57)
				{
					putchar(dec_1);
					putchar(unit_1);
					putchar(' ');
					putchar(dec_2);
					putchar(unit_2);
					if (dec_1 != 57 || unit_1 != 56)
					{
						putchar(44);
						putchar(' ');
					}
					unit_2++;
				}
				dec_2++;
			}
			unit_1++;
		}
		dec_1++;
	}
	putchar('\n');
	return (0);
}
