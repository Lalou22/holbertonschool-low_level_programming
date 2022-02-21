/*
 * File: 1-string_nconcat.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * string_nconcat - Function that concatenates 2 strings.
 * @s1: First string.
 * @s2: Second string.
 * @n: n-bytes to be copied from the string.
 *
 * Description: Write a function that concatenates two strings.
 * The returned pointer shall point to a newly allocated space in memory,
 * which contains s1, followed by the first n bytes of s2, and null terminated.
 * Return: Pointer to the allocated memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, k = 0; /*Unsigned to match the parameter*/
	char *res; /*String to be returned*/

	if (s1 != NULL) /*Gets the length of S1*/
	{
		for ( ; s1[i]; i++)
			;
	}
	if (s2 != NULL) /*Gets the length of S2*/
	{
		for ( ; s2[j]; j++)
			;
	}
	if (j > n) /*Checks if len 2 is bigger than n*/
		j = n;

	res = malloc((i + j + 1) * sizeof(char));
	if (res == NULL) /*Checks if res is null to avoid Null related errors*/
		return (NULL);

	for ( ; k < i; k++) /*Copies S1*/
		res[k] = s1[k];
	for (k = 0; k < j; k++) /*Copies S2*/
		res[k + i] = s2[k];
	res[i + j] = '\0'; /*Adds termination byte*/
	return (res);
}
