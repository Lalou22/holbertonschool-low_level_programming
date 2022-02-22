/*
 * File: 100-realloc.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes of the allocated space for ptr.
 * @new_size: Size, in byte of the new memory block.
 *
 * Description: Reallocates a memory block using malloc and free.
 * a) If new and old size are the same, do not do anything.
 * b) If new > old the "added" memory should not be initialized.
 * Run man realloc to learn more.
 * Return: NULL or new allocated pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        char *copy = ptr;
	char *new_ptr;
	unsigned int i, max_size = new_size;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size); /*The call is malloc(new_size)*/
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == old_size)
		return (ptr); /* The call do not do anything, return ptr*/
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr); /*The call is equivalent to free(ptr)*/
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		max_size = old_size;
	for (i = 0; i < max_size; i++)
		new_ptr[i] = copy[i];
	free(ptr);
	return (new_ptr);
}
