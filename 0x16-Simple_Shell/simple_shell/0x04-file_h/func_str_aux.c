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
 * _strncpy - Write a function that copies a string..
 * @src: Pointer to source string.
 * @n: Integer that limits concat.
 *
 * Description: Function that copy the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *src, int n)
{
	int len;
	char *aux = malloc(sizeof(char) * n);

	for (len = 0; src[len] !=  '\0' && len < n; len++)
		aux[len] = src[len];
	aux[len] = '\0';
	return (aux);
}

/**
 * _strdup - Function that creates a mem alloc space for a string copy.
 * @original: Char array to be duplicated.
 *
 * Description: Function that duplicates a string.
 * Return: Copy of the original string or NULL if failed.
 */
char *_strdup(char *original)
{
	char *copy;
	int i, len;

	if (!original)
		return (NULL);
	len = _strlen(original);
	copy = malloc((len + 1) * sizeof(char));
	for (i = 0; i <= len; i++)
		copy[i] = original[i];
	return (copy);
}

/**
 * compare_chars - Function that loops str to compare with c.
 * @c: Char to be compared.
 * @str: String with different chars.
 *
 * Description: Function that loops str, and compares c.
 * Return: 1 if equals and 0 otherwise.
 */
int compare_chars(char c, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strcat - Function that concatenates two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Description: Function that appends the s2 to  s1.
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *s1, char *s2)
{
	int i, l1, l2;
	char *str;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	for (i = 0; i < l1; i++)
		str[i] = s1[i];
	for (i = 0; i < l2; i++)
		str[l1 + i] = s2[i];
	str[l1 + l2] = '\0';
	return (str);
}
