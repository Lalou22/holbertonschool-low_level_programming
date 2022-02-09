/*
 * File: 1-strncat.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strncat - Write a function that concatenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Integer that limits concat.
 *
 * Description: Function that appends the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int len_1 = 0;
	int len_2 = 0;

	while (dest[len_1] !=  '\0')
		len_1++;
	while (src[len_2] !=  '\0' && len_2 < n)
	{
		dest[len_1 + len_2] = src[len_2];
		len_2++;
	}
	return (dest);
}
