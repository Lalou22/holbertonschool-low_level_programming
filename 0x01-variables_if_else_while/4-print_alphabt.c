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
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
        	if ( letter != 'e' && letter != 'q')
        	{
                	putchar(letter);
        	}
        	letter++;
	}
	putchar('\n');
	return (0);
}
