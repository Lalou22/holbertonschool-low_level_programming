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
 * Function created for the Task 1.
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
