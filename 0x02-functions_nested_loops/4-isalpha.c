#include "main.h"
/**
 * _isalpha - Check if a char is letter
 * @c: The character to be checked
 *
 * Return: 1 if the check is positive. 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
