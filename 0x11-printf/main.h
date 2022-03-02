#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print - Structure defined for printing different formats
 * @t: Type to print.
 * @f: Function used to print.
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int (*check_format(const char *format))(va_list);

#endif /* MAIN_H */
