/*
 * File: 100-is_palindrome.c
 * Auth: Lalo Rdz
 */
#include "main.h"
int get_len(char *s);
int check_palindrome(int left, int right, char *s);
/**
 * is_palindrome - Check if a string is a palindrome.
 * @s: String to be tested.
 *
 * Description: Test if s is a palindrome.
 * Return: 1 if the string is a palindrome, otherwise return 0.
 */
int is_palindrome(char *s)
{
	int len;
	if (*s == '\0')
		return (1);
	len = get_len(s) - 1;
	return (check_palindrome(0, len, s));
}
/**
 * get_len - Get the length of a string using recursion.
 * @s: String with unknown .
 *
 * Description: If Char is not the end of string keep counting.
 * Return: Length of a string.
 */
int get_len(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + get_len(s + 1));
}
/**
 * check_palindrome - Check two letters from a string and continue test.
 * @left: Left char from a string.
 * @right: Right char from a string.
 * @s: String with the letters, to be checked as a palindrome.
 *
 * Description: Using recursion moves through left and right chars of a string.
 * Return: Returns zero if not a palindrome, 1 otherwise.
 */
int check_palindrome(int left, int right, char *s)
{
	if (left >= right)
		return (1);
	else if (s[left] != s[right])
		return (0);
	else
		return (check_palindrome(left + 1, right - 1, s));
}
