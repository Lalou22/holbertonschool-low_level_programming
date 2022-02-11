/*
 * File: 100-atoi.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _atoi - Function that convert a string to an integer.
 * @s: String to be converted into integer.
 *
 * Description: Function that convert a string to an integer.
 * Return: Integer.
 */
int _atoi(char *s)
{
	int i, j, n, m;

	i = n = 0;
	m = 1;
	while ((*(s + i) < '0' || *(s + i) > '9') && (*(s + i) != '\0'))
	{
		if (*(s + i) == '-')
			m *= -1;
		i++;
	}
	j = i;
	while ((*(s + j) >= '0') && (*(s + j) <= '9'))
	{
		n = n * 10 + m * (*(s + j) - '0');
		j++;
	}
	return (n);
}
