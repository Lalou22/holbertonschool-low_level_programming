/*
 * File: op_func3.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * mul - Function that multiplies the top two elements of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that multiplies the top two elements of the stack.
 * If the stack contains less than two elements, print the error message.
 * Function created for the Task 8.
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't mul, stack too short\n");
		exit(EXIT_FAILURE);
	}
}
