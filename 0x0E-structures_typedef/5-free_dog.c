/*
 * File: 5-free_dog.c
 * Auth: Lalo Rdz
 */
#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - Function that frees dogs.
 * @d: Pointer to the Structure dog.
 *
 * Return: Void.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
