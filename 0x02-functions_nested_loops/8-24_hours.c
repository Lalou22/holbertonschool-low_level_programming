/*
 * File: 8-24_hours.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * jack_bauer - Print minutes.
 *
 * Description: Write a function that prints every minute.
 * Return: void
 */
void jack_bauer(void)
{
	int h1, h2, m1, m2, h_top;

	for (h1 = 0; h1 < 3; h1++)
	{
		if (h1 == 2)
			h_top = 4;
		else
			h_top = 10;
		for (h2 = 0; h2 < h_top; h2++)
		{
			for (m1 = 0; m1 < 6; m1++)
			{
				for (m2 = 0; m2 < 10; m2++)
				{
					_putchar(h1 + 48);
					_putchar(h2 + 48);
					_putchar(':');
					_putchar(m1 + 48);
					_putchar(m2 + 48);
					_putchar('\n');
				}
			}
		}
	}
}
