/*
 * File: 3-add_nodeint_end.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to the header that Starts the list.
 * @n: Int to be added.
 *
 * Description: Function that adds a new node at the ending of a listint_t
 * list.
 * Return: The address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node, *tmp;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next; /*Iterates through the list */
	tmp->next = node;
	return (node);
}
