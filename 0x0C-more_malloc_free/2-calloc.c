/*
 * File: 2-calloc.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: Number of elemets to be allocated (in the array).
 * @size: Size (in bytes) of variable type to be allocated.
 *
 * Description: The _calloc function allocates memory for an array of nmemb
 * elements of size bytes each and returns a pointer to the allocated memory.
 * Run man calloc to learn more.
 * Return: Void pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *res;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		res[i] = 0;
	return (res);
}
