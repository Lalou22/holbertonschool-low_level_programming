/*
 * File: 1-list_len.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "lists.h"
/**
 * list_len - Function that returns the number of elements in a linked list.
 * @h: Pointer to the header that Starts the list.
 *
 * Description: Function that returns the number of elements in a linked
 * list_t list.
 * Return: Number of elements.
 */
size_t list_len(const list_t *h)
{
	unsigned int i;
	const list_t *aux;

	aux = h;
	for (i = 0; aux; i++)
		aux = aux->next;
	return (i);
}
