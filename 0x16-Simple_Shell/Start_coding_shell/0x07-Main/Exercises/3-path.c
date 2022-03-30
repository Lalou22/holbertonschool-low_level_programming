/*
 * File: 3-path.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Write a function that gets an environment variable.
 *
 * Description: Write a function that gets an environment variable.
 * Without using getenv.
 * Return: Always 0.
 */
int main(void)
{
	printf("PATH: %s\n", _getenv("PATH"));
	printf("Elements\n");
	print_elem(_getenv("PATH"));
	printf("\n");
	return (0);
}

