/*
 * File: 101-wildcmp.c
 * Auth: Lalo Rdz
 */
#include "main.h"
char *get_wildcard(char *s1, char *s2);
char *test(char *s1, char *s2, char *t1, char *t2);
/**
 * wildcmp - Compares two strings.
 * @s1: String base.
 * @s2: String to be tested
 *
 * Description: Write a function that compares two strings.
 * The special char * can replace any string (including an empty string).
 * s2 can contain the special character *.
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);
	else if (*s2 == '*' && *(s2 + 1) == '*')
		return (wildcmp(s1, s2 + 1));
	else if (*s2 == '*')
	{
		char *p;

		p = get_wildcard(s1, s2 + 1);
		if (p == 0)
			return (0);
		return (wildcmp(p + 1, s2 + 2));
	}
	else if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
/**
 * get_wildcard - Check all the chars that have '*'.
 * @s1: String base.
 * @s2: String to be tested.
 *
 * Description: Checks for wildcard.
 * Return: Pointer to the spot where s1 matches s2.
 */
char *get_wildcard(char *s1, char *s2)
{
	if (*s1 != *s2)
	{
		if (*s1 == '\0')
			return (0);
		return (get_wildcard(s1 + 1, s2));
	}
	return (test(s1 + 1, s2 + 1, s1, s2));
}
/**
 * test - Continue test.
 * @s1: String base.
 * @s2: String to be tested.
 * @t1: First char in comparison (First string).
 * @t2: First char in comparison (Second string).
 *
 * Description: Using recursion checks string.
 * Return: Pointer to the spot where s1 matches s2.
 */
char *test(char *s1, char *s2, char *t1, char *t2)
{
	if (*s2 == '*' || (*s1 == '\0' && *s2 == '\0'))
		return (t1);
	else if (*s1 != *s2)
		return (get_wildcard(s1, t2));
	else
		return (test(s1 + 1, s2 + 1, t1, t2));
}
