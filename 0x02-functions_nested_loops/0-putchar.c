/*
 * File: 0-putchar.c
 * Auth: Lalo Rdz
 */

#include "main.h"

/**
 * main - Write a program that prints _putchar, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c[9] = "_putchar\n";
	int i;
        /**
	* @c, @i
	*
	* Description: Variable c used for the "string" to putchar
	* Variable i used to iterate the string
	*/
	for (i = 0; i <= 8; i++)
		_putchar(c[i]);
	return (0);
}
