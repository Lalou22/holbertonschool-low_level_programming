/*
 * File: 6-print_numberz.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Write a program that prints all single digit numbers of base 10
 * starting from 0, followed by a new line.
 * You are not allowed to use any variable of type char
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number = 48;

	while (number <= 57)
	{
		putchar(number);
		number++;
	}
	putchar('\n');
	return (0);
}
