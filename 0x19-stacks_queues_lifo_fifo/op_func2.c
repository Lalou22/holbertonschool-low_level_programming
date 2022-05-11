/*
 * File: op_func2.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * swap - Function that prints an int in stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that prints an int in stack.
 * Function created for the Task 3.
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int aux;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	/* Checks if the stack is NULL */
	if (*stack && (*stack)->next)
	{
		aux = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = aux;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * add - Function that adds the top two elements of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that adds the top two elements of the stack.
 * If the stack contains less than two elements, print the error message.
 * Function created for the Task 4.
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	/* Checks if the stack is NULL */
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Function that doesn’t do anything.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that doesn’t do anything.
 * Function created for the Task 5.
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Argument stack is not used, to avoid error "multiples" void */
	(void)(stack);
	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);
}

/**
 * sub - Function that substracts the top two elements of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that substracts the top two elements of the stack.
 * If the stack contains less than two elements, print the error message.
 * Function created for the Task 6.
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	/* Checks if the stack is NULL */
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
