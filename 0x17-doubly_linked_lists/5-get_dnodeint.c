/*
 * File: 5-get_dnodeint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * get_dnodeint_at_index - Function that returns the nth node of a list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node, starting from 0.
 *
 * Description: Function that returns the nth node of a dlistint_t linked
 * list. If the node does not exist, return NULL.
 * Return: Returns the integer stored on the node or Null if not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);
	for (i = 0; i < index && head != NULL; i++)
		head = head->next;
	return (head);
}
