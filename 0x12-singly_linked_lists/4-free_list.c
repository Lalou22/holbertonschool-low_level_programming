/*
 * File: 4-free_list.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * free_list - Function that frees a list_t list.
 * @head: Pointer to the header that Starts the list.
 *
 * Description: Function that frees a list_t list.
 * Return: Void.
 */
void free_list(list_t *head)
{
	list_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
