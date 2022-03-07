/*
 * File: 7-get_nodeint.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the header that Starts the list.
 * @index: Nth node to be returned.
 *
 * Description: Function that returns the nth node of a listint_t linked list.
 * Where index is the index of the node, starting at 0 if the node does not
 * exist, return NULL
 * Return: Returns the nth node of a listint_t linked list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	for (i = 0; i < index; i++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
