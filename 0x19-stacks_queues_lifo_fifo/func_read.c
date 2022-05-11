/*
 * File: func_read.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * initialize_var - Initialize the global variable.
 *
 * Return: void.
 */
void initialize_var(void)
{
	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_num = 1;
	monty.stk_use = 0;
}

/**
 * read_line - Reads line by line the file and executes monty commands.
 *
 * Return: void.
 */
void read_line(void)
{
	size_t s = 0;
	ssize_t r;
	char *operator, *token;

	/* Variables 's' and 'r' are used for the getline function */
	while ((r = getline(&monty.line, &s, monty.file) != -1))
	{
		/* Operator must be stored as the first str in line */
		operator = strtok(monty.line, " ");
		/* Checks for comments and line jumps */
		if (*operator == '#' || *operator == '\n')
		{
			/* If found ignore them and continue */
			monty.line_num++;
			continue;
		}
		/* Checks for push operator */
		else if (strcmp(operator, "push") == 0)
		{
			token = strtok(NULL, "\n ");
			push_stk(token);
		}
		else
		{
			get_operator(&monty.stack, operator);
		}
		monty.line_num++;
	}
}

/**
 * get_operator - Function that iterates through instruction list pointer.
 * @stk: Stack.
 * @operator: Char array with the operator to be searched.
 *
 * Description: EXIT_FAILURE on failure when operator is not found.
 * Return: void.
 */
void get_operator(stack_t **stk, char *operator)
{
	int i;
	char *monty_op;
	instruction_t functions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};

	monty_op = strtok(operator, "\n");
	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(monty_op, functions[i].opcode) == 0)
		{
			functions[i].f(stk, monty.line_num);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: ", monty.line_num);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", operator);
	exit(EXIT_FAILURE);
}

/**
 * free_variables - Function that frees the variables and close the file used.
 *
 * Return: void.
 */
void free_variables(void)
{
	stack_t *next;

	fclose(monty.file);
	free(monty.line);
	while (monty.stack != NULL)
	{
		next = (monty.stack)->next;
		free(monty.stack);
		monty.stack = next;
	}
}
