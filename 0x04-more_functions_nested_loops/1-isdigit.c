/*
 * File: 1-isdigit.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * _isdigit - Checks if char is digit
 * @c: Char to be checked
 * Description: function that checks for a digit (0 through 9).
 * Return: 1 if upper 0 otherwise
 */
int _isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}
