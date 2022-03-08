/*
 * File: 5-flip_bits.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * flip_bits - Function that returns the number of bits you would need to flip.
 * @n: First Unsigned long int.
 * @m: Second Unsigned long int.
 *
 * Description: Function that returns the number of bits you would need to
 * flip to get from one number to another. Not allowed to use % or / operators.
 * Return: The number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i, count = 0;
	unsigned long int diff = n ^ m;

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (diff & 1)
			count++;
		diff = diff >> 1;
	}
	return (count);
}
