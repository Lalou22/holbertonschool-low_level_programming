/*
 * File: 101-atof.c
 * Auth: Lalo Rdz
 */
#include "main.h"
int get_index_first(char *nptr);
double get_num(char *nptr, int ix);
double get_decimals(char *nptr, int ix);
/**
 * _atof - Write a function that converts a string to a double.
 * @nptr: Pointer to the string.
 *
 * Description: Write a function that converts a string to a double.
 * Return: Number in the string as a Double or 0.0 (if not number.
 */
double _atof(char *nptr)
{
	int index_num;

	index_num = get_index_first(nptr);
	if (index_num != -1)
		return (get_num(nptr, index_num));
	else
		return (0.0);
}
/**
 * get_index_first - Function that search for a number.
 * @nptr: Pointer to the string.
 *
 * Description: Write a function that finds the index of the first number.
 * Return: Index of the first number on the string or -1 if not number.
 */
int get_index_first(char *nptr)
{
	int i = 0;
	int res = 0;
	char c;

	while (nptr[i])
	{
		c = nptr[i];
		if (c == ' ' || c == '+' || c == '-' || c == '.')
		{
			i++;
		}
		else if (c >= '0' && c <= '9')
		{
			res = i;
			break;
		}
		else
		{
			res = -1;
			break;
		}
	}
	return (res);
}
/**
 * get_num - Function that transform the string into a double.
 * @nptr: Pointer to the string.
 * @ix: Index of the first number on the chain.
 *
 * Description: Write a function that transform the string into a double.
 * Return: A number on the string on a double format.
 */
double get_num(char *nptr, int ix)
{
	int sign = 1;
	double res = 0.0;

	if (nptr[ix - 1] == '-')
		sign = -1;

	if (nptr[ix - 1] == '.')
	{
		res = get_decimals(nptr, ix);
	}
	else
	{
		double mult;
		int i, j, k;

		i = 0;
		while (nptr[i + ix] >= '0' && nptr[i + ix] <= '9')
			i++;

		for (j = 0; j < i; j++)
		{
			mult = 1.0;
			for (k = 0; k < i - j - 1; k++)
				mult = mult * 10;
			res += (nptr[j + ix] - '0') * mult;
		}
		if (nptr[ix + i] == '.')
			res += get_decimals(nptr, ix + i + 1);
	}
	return (res * sign);
}
/**
 * get_decimals - Transform the string after a dec-point into a double.
 * @nptr: Pointer to the string.
 * @ix: Index of the decimal point on the string.
 *
 * Description: Finds the decimal part of the double.
 * Return: A number on the string on a double format.
 */
double get_decimals(char *nptr, int ix)
{
	double mult, res;
	int i, j, k;

	i = 0;
	while (nptr[i + ix] >= '0' && nptr[i + ix] <= '9')
		i++;

	for (j = 0; j < i; j++)
	{
		mult = 10.0;
		for (k = 0; k < j; k++)
			mult = mult * 10;
		res += (nptr[j + ix] - '0') / mult;
	}
	return (res);
}
