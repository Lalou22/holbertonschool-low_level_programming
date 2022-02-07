/*
 * File: 7-print_tebahpla.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Write a program that prints the lowercase alphabet in reverse, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	letter = 'z';
	while (letter >= 'a')
	{
		putchar(letter);
		letter--;
	}
	putchar('\n');
	return (0);
}
