/*
 * File: 2-strncpy.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strncpy - Write a function that copies a string..
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Integer that limits concat.
 *
 * Description: Function that copy the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len;

	for (len = 0; src[len] !=  '\0' && len < n; len++)
		dest[len] = src[len];
	for ( ; len < n; len++)
		dest[len] = '\0';
	return (dest);
}
