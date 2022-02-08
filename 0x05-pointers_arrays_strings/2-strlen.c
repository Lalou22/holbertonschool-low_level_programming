/*
 * File: 2-strlen.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strlen - Function that returns the length of a string.
 * @s: Pointer to the char string.
 *
 * Description: The standard library provides a similar function: strlen.
 * Run man strlen to learn more.
 * Return: Length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
