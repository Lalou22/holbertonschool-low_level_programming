/*
 * File: 1-listint_len.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "lists.h"
/**
 * listint_len - Function that returns the number of elements in a linked list.
 * @h: Pointer to the header that Starts the list.
 *
 * Description: Function that returns the number of elements in a linked
 * list_t list.
 * Return: Number of elements.
 */
size_t listint_len(const listint_t *h)
{
	unsigned int i;
	const listint_t *aux;

	aux = h;
	for (i = 0; aux; i++)
		aux = aux->next;
	return (i);
}
