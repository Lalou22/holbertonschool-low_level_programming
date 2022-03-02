/*
 * File: 0-print_listint.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "lists.h"
/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the header that Starts the list.
 *
 * Description: Prints the elements of the list's head and then starts printing
 * the next elements. Then returns the number of the printed nodes.
 * If str is NULL, print [0] (nil)
 * Return: The number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	unsigned int i = 0;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
