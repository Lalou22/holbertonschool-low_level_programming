/*
 * File: 7-insert_dnodeint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"

/**
 * insert_dnodeint_at_index - Function inserts a new node at a given position.
 * @h: Pointer to the head.
 * @idx: Index of list where the new node should be added. Index starts at 0.
 * @n: Integer to be inserted.
 *
 * Description: Function that inserts a new node at a given position.
 * Index of the list where the new node should be added. Index starts at 0.
 * If not possible to add at index, do not add the new node and return NULL.
 * Return: The number of nodes.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *old;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	old = *h;

	for (i = 0; i < idx && old; i++)
		old = old->next;
	if (i == idx && !old)
		return(add_dnodeint_end(h, n));

	else if (old)
	{
		new = malloc(sizeof(dlistint_t));

		if (!new)
			return (NULL);
		new->n = n;
		old->prev->next = new;
		new->prev = old->prev;
		old->prev = new;
		new->next = old;

		return (new);
	}
	return (NULL);	
}
