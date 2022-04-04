#include "shell.h"
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

	while (s[i])
		i++;
	return (i);
}
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

	while (src[len])
		len++;
	for (i = 0; i <= len; i++)
		dest[i] = src[i];
	return (dest);
}
