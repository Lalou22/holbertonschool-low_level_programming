/*
 * File: 5-free_listint2.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * free_listint2 - Function that frees a listint_t list.
 * @head: Pointer to the header that Starts the list.
 *
 * Description: Function that frees a listint_t list.
 * The function sets the head to NULL.
 * Return: Void.
 */
void free_listint2(listint_t **head)
{
	listint_t *next;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}
