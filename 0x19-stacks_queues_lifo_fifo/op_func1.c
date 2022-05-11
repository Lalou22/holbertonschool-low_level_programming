/*
 * File: op_func1.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * push_stk - Function that adds a node to the stack.
 * @arg: Char array that may or not contain a number.
 *
 * Description: Checks if the arg is a number, then creates a stack_t
 * variable called new to be inserted on the monty.stack.
 * Function created for the Task 0.
 * Return: void.
 */
void push_stk(char *arg)
{
	int num;
	stack_t *new;

	/* Checks if the argument have a number, if not exit failure */
	if (check_int(arg) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	/* Checks if the the stack_t can be created, if not exit failure */
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_variables();
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}

/**
 * check_int - Function that checks if the argument passed is a number.
 * @arg: Char array that may or not contain a number.
 *
 * Description: Checks if the argument passed is a number.
 * Function created for the Task 0 (Can be recycled).
 * Return: 1 if arg is a number, 0 otherwise.
 */
int check_int(char *arg)
{
	int i = 0;

	/* Returns 0 if the arg is NULL */
	if (!arg)
		return (0);
	/* Returns 0 if there is no negative sign of number */
	if (!isdigit(arg[0]) && arg[0] != '-')
		return (0);
	/* Checks if all the other elements are digits */
	for (i = 1; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
			return (0);
	}
	return (1);
}

/**
 * pall - Function that adds a node to the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Prints all the integers of the Stack.
 * Function created for the Task 0.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);
	if (!*stack)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Function that prints an int in stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that prints an int in stack.
 * Function created for the Task 1.
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	/* Checks if the stack is NULL */
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * pop - Function that removes the top element of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that prints an int in stack. If the stack is empty,
 * print the error message followed by a new line, and exit with the status
 * EXIT_FAILURE. Function created for the Task 2.
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	/* Checks if the stack is NULL */
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
}
