/*
 * File: 100-get_endianness.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * get_endianness - Function that checks the endianness.
 * @void: No parameter.
 *
 * Description: Function that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int x;
	char *y;

	x = 1;
	y = (char *)&x;
	return (*y);
}
