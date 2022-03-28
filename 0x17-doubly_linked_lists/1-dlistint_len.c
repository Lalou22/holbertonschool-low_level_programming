/*
 * File: 0-print_list.c
 * Auth: Lalo Rdz
 */
#include "lists.h"

/**
 * dlistint_len - Function that find the length of the linked list.
 * @h: pointer to the head of the list.
 *
 * Return: Lenght of the double linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t a;

	for (a = 0; h; a++)
		h = h->next;

	return (a);
}
