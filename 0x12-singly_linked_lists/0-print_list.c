/*
 * File: 0-print_list.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include "lists.h"
/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the header that Starts the list.
 *
 * Description: Prints the elements of the list's head and then starts printing
 * the next elements. Then returns the number of the printed nodes.
 * If str is NULL, print [0] (nil)
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	unsigned int i;
	const list_t *aux;

	aux = h; /* Gets the list's First element "Head". */
	for (i = 0; aux; i++)
	{
		if (aux->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", aux->len, aux->str);
		aux = aux->next; /* Gets the next element of the list. */
	}
	return (i);
}
