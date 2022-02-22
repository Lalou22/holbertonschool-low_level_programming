/*
 * File: 0-print_name.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * print_name - Function that prints a name using a function pointer.
 * @name: Pointer to the name to be printed.
 * @f: Pointer to dog's owner.
 *
 * Description: Checks for NULL, and after passing the check, applys the
 * function "f" to the "name".
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
