#ifndef _VARIADIC_FUNCTIONS_H_
#define _VARIADIC_FUNCTIONS_H_

#include <stdio.h>
#include <stdarg.h> /*Macros: va_start, va_arg and va_end*/
/*https://en.wikipedia.org/wiki/Stdarg.h*/

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

typedef struct print_functions
{
	char *c;
	void (*f)(va_list);
} print_functions;

#endif /* _VARIADIC_FUNCTIONS_H_ */
