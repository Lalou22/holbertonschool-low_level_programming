/*
 * File: 0-malloc_checked.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * malloc_checked - Function that allocates memory using malloc.
 * @b: Bytes to allocated.
 *
 * Description: if malloc fails, the malloc_checked function should
 * cause normal process termination with a status value of 98.
 * Return: Pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *mem_alloc = malloc(b);

	if (mem_alloc == NULL)
		exit(98); /*for more information check man exit(3) */

	return (mem_alloc);
}
