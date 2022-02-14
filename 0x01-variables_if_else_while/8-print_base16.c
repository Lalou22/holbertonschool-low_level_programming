/*
 * File: 8-print_base16.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Write a program that prints all the numbers of base 16.
 * in lowercase, followed by a new line.
 * Return: Always 0 (Success).
 */
int main(void)
{
	int number = 48;

	while (number <= 57)
	{
		putchar(number);
		number++;
	}
	number = 97;
	while (number <= 102)
	{
		putchar(number);
		number++;
	}
	putchar('\n');
	return (0);
}
