/*
 * File: 5-print_numbers.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Write a program that prints all single digit numbers of base 10 starting from 0, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	letter = '0';
	while (letter <= '9')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
