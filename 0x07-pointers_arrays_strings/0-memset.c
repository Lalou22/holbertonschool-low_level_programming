/*
 * File: 0-memset.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _memset - Write a function that fills memory with a constant byte.
 * @s: Char string pointer.
 * @b: Char to be filled.
 * @n: Number of bytes of area.
 *
 * Description: Fills the first n bytes of the memory area pointed.
 * to by s with the constant byte b. Run man memset to learn more.
 * Return: void
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
