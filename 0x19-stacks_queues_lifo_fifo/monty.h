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
 * struct monty_s - Stack usage and stack lenght.
 * @file: Monty file to be read (Usually terminated on '.m' ").
 * @line: String var used to store a line readed from file.
 * @line_num: Current line number read of the file.
 * @stack: Stack structure built when using our Monty program.
 * @stk_use: Flag used to change between Stack (0) and Queue (1).
 *
 * Description: Global variable used to change from stack to queue.
 */
typedef struct monty_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_num;
	int stk_use;
} monty_t;
/* Global variable struct to hold (int) flag for stack useage and length */
extern monty_t monty;
monty_t monty;

/* Functions used to read from line and get operator. File: func_read.c */
void initialize_var(void);
void read_line(void);
void get_operator(stack_t **stk, char *operator);
void free_variables(void);

/* Functions related to pull, pall, pint and pop. File: op_func1.c */
void push_stk(char *arg);
int check_int(char *arg);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* Functions related to swap, add and nop. File: op_func2.c */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
