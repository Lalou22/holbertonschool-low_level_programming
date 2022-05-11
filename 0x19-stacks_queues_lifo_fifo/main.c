#include "monty.h"

/* Global variable struct to hold (int) flag for stack useage and length */
stk_var glob_var;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stk = NULL;
	FILE *file = NULL;
	char *_line = NULL, *_op = NULL;
	size_t s = 0;
	unsigned int line_num = 1;

	/* Initialization of the global variable */
	glob_var.stk_use = 0;
	glob_var.stk_len = 0;

	/* If argument count != 2, then EXIT_FAILURE */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* If file cant be open, then EXIT_FAILURE */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Iterate until you cant get line */
	while (getline(&_line, &s, file) != -1)
	{
		_op = strtok(_line, "\n\t\r ");
		if (_op != NULL && _op[0] != '#')
			get_operator(_op, &stk, line_num);
		line_num++;
	}
	exit(EXIT_SUCCESS);
}
