/*
 * File: 2-add_nodeint.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: Pointer to the header that Starts the list.
 * @n: Int to be added.
 *
 * Description: Function that adds a new node at the beginning of a listint_t
 * list.
 * Return: The address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = *head;
	*head = node;
	return (node);
}
