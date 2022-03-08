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
	unsigned int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	
	for (i = 0; i < index; i++)
		n = n >> 1;

	return (n & 1);
}
