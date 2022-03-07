/*
 * File: 10-delete_nodeint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * delete_nodeint_at_index - Function that deletes the node at index of a list.
 * @head: Pointer to the header that Starts the list.
 * @index: Index of the list where the new node should be added.
 *
 * Description: Function that deletes the node at index of a listint_t
 * linked list.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *cursor, *temp;

	if (head == NULL || *head == NULL)
		return (-1);

	cursor = *head;
	if (index == 0)
	{
		*head = cursor->next;
		free(cursor);
		return(1);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (cursor->next == NULL)
			return (-1);
		cursor = cursor->next;
	}
	temp = cursor->next;
	cursor->next = temp->next;
	free(temp);
	return (1);
}
