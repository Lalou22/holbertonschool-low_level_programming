/*
 * File: main.c
 * Auth: Lalo Rdz
 */
#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	initialize_var();
	/* If argument count != 2, then EXIT_FAILURE */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* If file can't be open, then EXIT_FAILURE */
	monty.file = fopen(argv[1], "r");
	if (monty.file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_line();
	free_variables();
	exit(EXIT_SUCCESS);
}
