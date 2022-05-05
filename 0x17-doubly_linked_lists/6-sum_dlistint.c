/*
 * File: 6-sum_dlistint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * sum_dlistint - Function that returns the sum of a list.
 * @head: Pointer to the head of the list.
 *
 * Description: Function that returns the sum of all the data (n) of a
 * dlistint_t linked list. If the list is empty, return 0.
 * Return: Returns the sum of all data or 0 if list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	for (sum = 0; head != NULL; head = head->next)
		sum += head->n;
	return (sum);
}
