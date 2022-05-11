/*
 * File: opcodes_1.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * op_push - Function that pushes an element to the stack (Task 0).
 * @stk: Double pointer to the beginnig of the stack.
 * @line_num: Script line number.
 *
 * Description: Function that pushes an element to the stack "stk".
 * If not an integer or if there is no argument, print the error message.
 * You won’t have to deal with overflows. Use the atoi function.
 * Return: Void.
 */
void op_push(stack_t **stk, unsigned int line_num)
{
	int num;
	char *str;

	str = strtok(NULL, "\n\t\r ");
	/* Checks if <int> is not an integer or if there is no argument given */
	if (str == NULL || check_digit(str))
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	num = atoi(str);
	/* Checks if the node can be added to the stk */
	if (!add_node(stk, num))
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glob_var.stk_len++;
}

/**
 * add_node - Function that adds a new node to the stack.
 * @stk: Double pointer to the beginnig of the stack.
 * @num: Value to be added to the new node of the stack.
 *
 * Description: Function that adds a new node to the stack.
 * This function was originally created for Task 0, but can be recycled.
 * Return: If the node is added then pointer to new node, NULL otherwise.
 */
stack_t *add_node(stack_t **stk, int num)
{
	stack_t *new_node;

	/* Checks if stk is not NULL */
	if (stk == NULL)
		return (NULL);
	/* Checks if the memory can be allocated for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	/* If the new node can be allocated, then new_node->n = num */
	new_node->n = num;
	if (*stk == NULL)
	{
		/* Prev and Next points to new for circular linked list */
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stk)->prev->next = new_node;
		new_node->prev = (*stk)->prev;
		(*stk)->prev = new_node;
		new_node->next = *stk;
	}
	if (glob_var.stk_use == 0 || glob_var.stk_len == 0)
		*stk = new_node;
	return (new_node);
}

/**
 * op_pall - Function that prints the stack (Task 0).
 * @stk: Double pointer to the beginnig of the stack.
 * @line_num: Script line number.
 *
 * Description: Function that prints all the values on the stack, starting
 * from the top of the stack. If the stack is empty, don’t print anything.
 * Return: Void.
 */
void op_pall(stack_t **stk, unsigned int line_num)
{
	stack_t *head;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_num);
	/* Assigns the head of the stk to the new variable "head" */
	head = *stk;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		/* Moves to the next element on the stack */
		head = head->next;
		/* If you return to the original head, then finish the loop*/
		if (head == *stk)
			return;
	}
}
