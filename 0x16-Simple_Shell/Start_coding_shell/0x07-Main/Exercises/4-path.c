/*
 * File: 4-path.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Write a function that gets an environment variable.
 *
 * Description: Write a function that builds a linked list of the PATH
 * directories.
 * Return: Always 0.
 */
int main(void)
{
	list_t *head;

	head = NULL;
	printf("PATH: %s\n", _getenv("PATH"));
	printf("Elements\n");
        add_substring(head, _getenv("PATH"));
	return (0);
}

