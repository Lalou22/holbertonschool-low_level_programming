/*
 * File: 3-add_node_end.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the header that Starts the list.
 * @str: String to be added (malloc'ed string).
 *
 * Description: Function that adds a new node at the ending of a list_t
 * list. And str needs to be duplicated.
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int i = 0;
	list_t *node, *tmp;

	if (str == NULL)
		return (NULL);

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	for ( ; str[i]; i++)
		;

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	
	node->len = i;
	node->next = NULL;
	
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next; /*Iterates through the list */
	tmp->next = node;
	return (node);
}
