/*
 * File: 9-print_dlistint_backward.c
 * Auth: Lalo Rdz
 */
#include "lists.h"

/**
 * print_dlistint_backward - Function that prints elements of a list backward.
 * @h: pointer to the head.
 *
 * Description: Function that prints all the elements of a dlistint_t list
 * backward.
 * Return: The number of nodes.
 */
size_t print_dlistint_backward(const dlistint_t *h)
{
	size_t a;

	for (a = 0; h->next != NULL; a++)
		h = h->next;
	for (a = a + 1; a > 0; a--)
	{
		printf("%d\n", h->n);
		h = h->prev;
	}
	return (a);
}
