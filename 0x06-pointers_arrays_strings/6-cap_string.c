/*
 * File: 6-cap_string.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * cap_string - Capitalizes all words of a string.
 * @s: Pointer to string.
 *
 * Description: Separators of words space, tabulation, 
 * new line, ,, ;, ., !, ?, ", (, ), {, and }
 * Return: String with capitzalizes.
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char a[] = " \t\n,;.!?\"(){}";

	while (*(s + i))
	{
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
		{
			if (i == 0)
				*(s + i) += 'A' - 'a';
			else
			{
				for (j = 0; j <= 12; j++)
				{
					if (a[j] == *(s + i - 1))
						*(s + i) += 'A' - 'a';
				}
			}
		}
		i++;
	}
	return (s);
}
