/*
 * File: 103-infinite_add.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * infinite_add - Write a function that adds two numbers.
 * @n1: String number 1.
 * @n2: String number 2.
 * @r: Buffer to store the result;
 * @size_r: Buffer size
 *
 * Description: Adds n1 and n2.
 * Return: Pointer to the result or 0 if can not be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, sum_unit, sum_carry;

	for (i = 0; n1[i]; i++)
		;
	for (j = 0; n2[j]; j++)
		;
	if (i > size_r || j > size_r)
		return (0);
	sum_carry = 0;
	for (i -= 1, j -= 1, k = 0; k < size_r; i--, j--, k++)
	{
		sum_unit = sum_carry;
		if (i >= 0)
			sum_unit += n1[i] - '0';
		if (j >= 0)
			sum_unit += n2[j] - '0';
		if (i < 0 && j < 0 && sum_unit == 0)
			break;
		sum_carry = sum_unit / 10;
		r[k] = sum_unit % 10 + '0';
	}
	r[k] = '\0';
	if (i >= 0 || j >= 0 || sum_carry >= 1)
		return (0);
	for (k -= 1, i = 0; i < k; k--, i++)
	{
		j = r[k];
		r[k] = r[i];
		r[i] = j;
	}
	return (r);
}
