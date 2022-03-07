/*
 * File: 9-insert_nodeint.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * insert_nodeint_at_index - Function that inserts a new node at a position.
 * @head: Pointer to the header that Starts the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer for the new node.
 *
 * Description: Function that inserts a new node at a given position.
 * If it is not possible to add the new node at index idx, do not add
 * the new node and return NULL.
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *current, *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(listint_t));
	if (temp == NULL)
		return (NULL);
	temp->n = n; /* Creates the temporal node with parameter n */

	current = *head;
	if (idx == 0)
	{
		temp->next = *head;
		*head = temp;
		return (*head);
	}
	while (current)
	{
		if (i == idx - 1)
		{
			temp->next = current->next;
			current->next = temp;
		}
		i++;
		current = current->next;
	}
	if (idx > i)
		return (NULL);
	return (temp);
}
