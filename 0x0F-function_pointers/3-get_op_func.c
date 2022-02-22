/*
 * File: 3-get_op_func.c
 * Auth: Lalo Rdz
 */
#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - Selects the correct operation to perform.
 * @s: Operation to be performed.
 *
 * Description: Returns a pointer to the function that corresponds to the
 * operator given as a parameter. If s does not match any of the 5 expected
 * operators (+, -, *, /, %), return NULL.
 * Return: Pointer to the function.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
