/*
 * File: 2-str_concat.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * str_concat - Write a function that concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Description: Write a function that concatenates two strings.
 * The returned pointer should point to a newly allocated space in memory
 * which contains the contents of s1, followed by the contents of s2,
 * and null terminated
 * Return: NULL on failure, otherwise return the concatenated string.
 */
char *str_concat(char *s1, char *s2)
{
	int l1, l2, size_c, i;
	char *conct;

	if (s1 == NULL)
	{
		l1 = 0;
	}
	else
	{
		for (l1 = 0; s1[l1]; l1++)
			;
	}
	if (s2 == NULL)
	{
		l2 = 0;
	}
	else
	{
		for (l2 = 0; s2[l2]; l2++)
			;
	}
	size_c = l1 + l2 + 1;
	conct = malloc(size_c * sizeof(char));
	if (conct == NULL)
		return (NULL);
	for (i = 0; i < l1; i++)
		conct[i] = s1[i];
	for (i = 0; i < l2; i++)
		conct[l1 + i] = s2[i];
	conct[l1 + l2] = '\0';
	return (conct);
}
