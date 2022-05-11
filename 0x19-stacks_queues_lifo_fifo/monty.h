#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer.
 * @prev: Points to the previous element of the stack (or queue).
 * @next: Points to the next element of the stack (or queue).
 *
 * Description: Doubly linked list node structure.
 * For stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function.
 * @opcode: The opcode.
 * @f: Function to handle the opcode.
 *
 * Description: Opcode and its function.
 * For stack, queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stk_var - Stack usage and stack lenght.
 * @stk_use: 0 to use it as a regular stack and 1 to use it as a queue.
 * @stk_len: Lenght of the stack.
 *
 * Description: Global variable used to change from stack to queue.
 */
typedef struct stk_var
{
	int stk_use;
	size_t stk_len;
} stk_var;
/* Global variable struct to hold (int) flag for stack useage and length */
extern stk_var glob_var;

/* File: func_aux.c */
void get_operator(char *_op, stack_t **stk, unsigned int line_num);
int check_digit(char *token);
/* File: opcodes_1.c */
void op_push(stack_t **stk, unsigned int line_num);
stack_t *add_node(stack_t **stk, int num);
void op_pall(stack_t **stk, unsigned int line_num);

#endif /* MONTY_H */
