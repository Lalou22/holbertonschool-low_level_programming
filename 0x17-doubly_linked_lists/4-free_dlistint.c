/*
 * File: 4-free_dlistint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * free_dlistint - Function that frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Description: Function that frees a dlistint_t list.
 * Return: Void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
