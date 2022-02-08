/*
 * File: 0-isupper.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * _isupper - Checks if char is Uppercase
 * @c: Char to be checked
 * Description: Function that checks for uppercase character.
 * Return: 1 if upper 0 otherwise
 */
int _isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	else
		return (0);
}
