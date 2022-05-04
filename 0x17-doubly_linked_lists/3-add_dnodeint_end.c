/*
 * File: 3-add_dnodeint_end.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * add_dnodeint_end - Add node at the end of the list.
 * @head: Pointer to the head of the list.
 * @n: Int data.
 *
 * Description: Function that adds a new node at the end of a dlistint_t list.
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *tmp;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	for (; tmp->next != NULL; )
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (new);
}
