/*
 * File: 9-strcpy.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strcpy - Function that copies the string pointed.
 * @dest: Pointer to the destination array.
 * @src: Pointer to the source array.
 *
 * Description: Copies the string pointed to by src.
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
		len++;
	for (i = 0; i <= len; i++)
		dest[i] = src[i];
	return (dest);
}
