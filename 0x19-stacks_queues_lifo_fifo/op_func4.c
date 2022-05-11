/*
 * File: op_func4.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * rotr - Function that rotates the stack to the bottom.
 * @stack: Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: Function that rotates the stack to the top. The last element of
 * the stack becomes the top element of the stack. rotr never fails.
 * Function created for the Task 14.
 * Return: void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1, *temp_2;

	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);

	if (!*stack || !(*stack)->next)
		return;

	temp_1 = *stack;

	while (temp_1->next->next)
	{
		temp_1 = temp_1->next;
	}
	temp_2 = temp_1->next;
	temp_1->next = NULL;
	(*stack)->prev = temp_2;
	temp_2->next = *stack;
	temp_2->prev = NULL;
	*stack = temp_2;
}

/**
 * _stack - Function that sets the format of the data to a stack (LIFO).
 * @stack: (Unused) Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: The opcode stack sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * Function created for the Task 15.
 * Return: void.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	/* Argument stack is not used, to avoid error "multiples" void */
	(void)(stack);
	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);
	monty.stk_use = 0;
}

/**
 * _queue - Function that sets the format of the data to a queue (FIFO).
 * @stack: (Unused) Stack saved on the variable monty.
 * @line_number: (Unused) Line number of the file of the instruction.
 *
 * Description: The opcode stack sets the format of the data to a queue (FIFO).
 * Function created for the Task 15.
 * Return: void.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	/* Argument stack is not used, to avoid error "multiples" void */
	(void)(stack);
	/* Argument line_num is not used, to avoid error "multiples" void */
	(void)(line_number);
	monty.stk_use = 1;
}

/**
 * push_queue - Function that adds a node to the end of the stack.
 * @arg: Char array that may or not contain a number.
 *
 * Description: Checks if the arg is a number, then creates a stack_t
 * variable called new to be inserted on the end of the monty.stack.
 * Function created for the Task 15.
 * Return: void.
 */
void push_queue(char *arg)
{
	int num;
	stack_t *new, *tmp;

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
	tmp = monty.stack;
	new->n = num;
	new->next = NULL;
	if (!tmp)
	{
		new->prev = NULL;
		monty.stack = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
