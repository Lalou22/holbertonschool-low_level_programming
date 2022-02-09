/*
 * File: 3-strcmp.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * _strncmp - Write a function that compares two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Description: The standard library provides a similar function: strcmp.
 * Return: Outputs the difference of s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}
