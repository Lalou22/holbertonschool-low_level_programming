/*
 * File: 0-binary_to_uint.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * binary_to_uint - Function that converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Description: Function that converts a binary number to an unsigned int.
 * Convert the number or return zero if there is a char not 0 or 1.
 * Return: The converted number or zero.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0, num = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		num <<= 1;
		if (b[i] == '1')
			num += 1;
	}
	return (num);
}
