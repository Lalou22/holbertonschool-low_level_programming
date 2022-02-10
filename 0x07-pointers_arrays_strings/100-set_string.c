/*
 * File: 100-set_string.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * set_string - Function that sets the value of a pointer to a char.
 * @s: Pointer to source string.
 * @to: Pointer to destination string.
 *
 * Description: Function that sets the value of a pointer to a char.
 * Return: Void.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
