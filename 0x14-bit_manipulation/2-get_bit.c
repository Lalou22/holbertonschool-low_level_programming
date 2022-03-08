/*
 * File: 2-get_bit.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * get_bit - Function that returns the value of a bit at a given index.
 * @n: Unsigned long int.
 * @index: Index to get the value from the int n.
 *
 * Description: Function that returns the value of a bit at a given index.
 * Where index is the index, starting from 0 of the bit you want to get.
 * Return: The value of the bit at index index or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i, j, temp;

	for (i = 0, j = 1, temp = n; i < index; i++)
	{
		j = j << 1;
		temp = temp >> 1;
	}

	if (n < j)
		return (-1);

	return (temp & 1);
}
