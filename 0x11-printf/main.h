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
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_bin(va_list i);
int print_unsigned_int(va_list i);
int print_oct(va_list i);
int print_x(va_list i);
int print_X(va_list i);
int print_S(va_list S);
int print_p(va_list p);
int print_r(va_list r);
int print_two_hex(char c);
int print_int_recursion(unsigned int n, int base, int selector);

#endif /* MAIN_H */
