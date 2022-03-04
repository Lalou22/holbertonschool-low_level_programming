/*
 * File: 8-sum_listint.c
 * Auth: Lalo Rdz
 */
#include "lists.h"
/**
 * sum_listint - Sum of all the data (n) of a listint_t linked list.
 * @head: Pointer to the header that Starts the list.
 * @index: 
 *
 * Description: Function that returns the sum of all the data (n) of a
 * listint_t linked list. If the list is empty, return 0. 
 * Return: The sum of all the data in the list.
 */
int sum_listint(listint_t *head)
{
        int sum = 0;

        while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
