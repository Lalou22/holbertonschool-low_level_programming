/*
 * File: 3-islower.c
 * Auth: Lalo Rdz
 */

#include "main.h"

/**
 * int _islower(int c) - Write a function that checks for lowercase character
 *
 * Return: Always 0 (Success)
 */
int _islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	else
		return (0);
}
