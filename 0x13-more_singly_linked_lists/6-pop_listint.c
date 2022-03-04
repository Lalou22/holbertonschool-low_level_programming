/*
 * File: 6-pop_listint.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint - Function that deletes the head node of a listint_t.
 * @head: Pointer to the header that Starts the list.
 *
 * Description: Function that deletes the head node of a listint_t linked
 * list, and returns the head node’s data (n), if the linked list is
 * empty return 0.
 * Return: Head node’s data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *aux;
	int n;

	if (*head == NULL || head == NULL)
		return (0);
	aux = *head;
	*head = aux->next;
	n = aux->n;
	free(aux);
	return (n);
}
