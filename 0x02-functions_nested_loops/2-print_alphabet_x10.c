/*
 * File: 2-print_alphabet_x10.c
 * Auth: Lalo Rdz
 */

#include "main.h"

/**
 * void print_alphabet_x10(void) - Write a function that prints the alphabet
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void)
{
	int i;
	char letter;
	/**
	* @i, @letter
	*
	* Description: Variable i for iterate and letter.
	*
	*/
	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
