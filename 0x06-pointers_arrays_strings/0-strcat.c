/*
 * File: 0-strcat.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strcat - Write a function that concatenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Description: Function that appends the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int len_1 = 0;
	int len_2 = 0;

	while (dest[len_1] !=  '\0')
		len_1++;
	while (src[len_2] !=  '\0')
	{
		dest[len_1 + len_2] = src[len_2];
		len_2++;
	}
	return (dest);
}
