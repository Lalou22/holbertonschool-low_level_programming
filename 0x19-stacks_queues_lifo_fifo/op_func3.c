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

/**
 * mod - Function that mods the top two elements of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that mods the top two elements of the stack.
 * If the stack contains less than two elements, print the error message.
 * Function created for the Task 9.
 * Return: void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "division by zero\n");
		exit(EXIT_FAILURE);
	}
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n %= (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}

/**
 * pchar - Function that prints the char at the top of the stack.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that prints the char at the top of the stack.
 * If the value is not in the ascii table print the error message.
 * Function created for the Task 11.
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
		free_variables();
		dprintf(STDERR_FILENO, "can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
