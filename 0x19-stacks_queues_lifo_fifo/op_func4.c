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
