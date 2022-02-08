/*
 * File: 1-swap.c
 * Auth: Lalo Rdz
 */
#include "main.h"
/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to the First int
 * @b: Pointer to the Second int
 * Description: Write a function that swaps the values of two integers.
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
