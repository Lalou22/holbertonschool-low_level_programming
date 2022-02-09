/*
 * File: 1-memcpy.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _memcpy - Write a function that copies memory area.
 * @dest: Char string pointer destination.
 * @src: Char string pointer source.
 * @n: Number of bytes of area.
 *
 * Description: Function copies n bytes from memory area src.
 * to memory area dest. Run man memcpy to learn more.
 * Return: A pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);
	return (dest);
}
