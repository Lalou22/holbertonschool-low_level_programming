/*
 * File: 4-clear_bit.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * clear_bit - Function that sets the value of a bit to 0 at a given index.
 * @n: Unsigned long int.
 * @index: Index to get the value from the int n.
 *
 * Description: Function that sets the value of a bit to 0 at a given index.
 * Where index is the index, starting from 0 of the bit you want to set.
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int set;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	set = ~(1 << index);
	*n = *n & set;
	return (1);
}
