/*
 * File: 4-free_listint.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * free_listint - Function that frees a listint_t list.
 * @head: Pointer to the header that Starts the list.
 *
 * Description: Function that frees a listint_t list.
 * Return: Void.
 */
void free_listint(listint_t *head)
{
	listint_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
