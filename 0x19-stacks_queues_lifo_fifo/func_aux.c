#include "monty.h"

/**
 * get_operator - Check operator against valid opcodes.
 * @_op: Operator to be check.
 * @stk: Double pointer to the beginnig of the stack.
 * @line_num: Script line number.
 *
 * Return: Void.
 */
void get_operator(char *_op, stack_t **stk, unsigned int line_num)
{
	size_t i;
	instruction_t monty_ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	for (i = 0; monty_ops[i].opcode != NULL; i++)
	{
		if (strcmp(monty_ops[i].opcode, _op) == 0)
		{
			monty_ops[i].f(stk, line_num);
			return;
		}
	}

	dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_num, _op);
	exit(EXIT_FAILURE);
}

/**
 * check_digit - Checks if string is a number.
 * @token: String to be check.
 *
 * Return: 0 if number, 1 if not.
 */
int check_digit(char *token)
{
	unsigned int i;
	
	for (i = 0; token[i]; i++)
	{
		if (i == 0 && token[i] == '-')
			continue;
		if (isdigit(token[i]) == 0)
			return (1);
	}
	return (0);
}
