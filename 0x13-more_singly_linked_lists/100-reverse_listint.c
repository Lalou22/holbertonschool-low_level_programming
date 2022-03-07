/*
 * File: 100-reverse_listint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * reverse_listint - Function that reverses a listint_t linked list.
 * @head: Pointer to the header that Starts the list.
 *
 * Description: Function that reverses a listint_t linked list.
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous, *next;

	if (head == NULL || *head == NULL)
		return (NULL); /* If the list is null return null */
	if ((*head)->next == NULL)
		return (*head); /* If the list is one element do nothing */

	previous = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
		/*
		 * printf("\n-------------Impresion de prueba-------------\n");
		 * print_listint(next);
		 * printf("\n");
		 * print_listint((*head)->next);
		 * printf("\n");
		 * print_listint(previous);
		 * printf("\n");
		 */
	}
	*head = previous;
	return (*head);
}
