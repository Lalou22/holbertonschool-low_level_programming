/*
 * File: 3-print_alphabets.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Prints lowercase alphabet and then uppercase using only putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}
	letter = 'A';
	while (letter <= 'Z')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
