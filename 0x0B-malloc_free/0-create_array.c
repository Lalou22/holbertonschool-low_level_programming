/*
 * File: 0-create_array.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * create_array - Creates an array of chars, and initializes it.
 * @size: Size of the array.
 * @c: Char to inialitize the array.
 *
 * Description: Write a function that creates an array of chars,
 * and initializes it with a specific char.
 * Return: Pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array_c;

	if (size == 0)
		return (NULL);
	array_c = malloc(size * sizeof(char));
	if (array_c == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		array_c[i] = c;
	return (array_c);
}
