/*
 * File: 8-delete_dnodeint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"

/**
 * delete_dnodeint_at_index - Function deletes the node at index of a list.
 * @headh: Pointer to the head.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *
 * Description: Function that deletes the node at index index of a dlistint_t
 * linked list. Where index is the index of the node that should be deleted.
 * Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *old;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		old = *head;
		*head = old->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(old);
		return (1);
	}

	old = *head;
	for (i = 0; i < index && old; i++)
		old = old->next;
	if (!old)
		return (-1);
	old->prev->next = old->next;

	if (old->next)
		old->next->prev = old->prev;
	free(old);
	return (1);
}
