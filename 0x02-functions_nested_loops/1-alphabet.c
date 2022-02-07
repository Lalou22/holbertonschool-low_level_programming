/*
 * File: 1-alphabet.c
 * Auth: Lalo Rdz
 */

#include "main.h"

/**
 * print_alphabet - Write a function that prints the alphabet
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	char letter;
	/**
	* @letter
	*
	* Description: Variable letter.
	*
	*/
	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
}
