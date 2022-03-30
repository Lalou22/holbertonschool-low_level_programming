/*
 * File: 2-getenv.c
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
	printf("-----Using standard getenv-----\n");
	printf("PATH: %s\n", getenv("PATH"));
	printf("HOME: %s\n", getenv("HOME"));
	printf("ROOT: %s\n", getenv("ROOT"));
	printf("\n");
	printf("-----Using _getenv-----\n");
	printf("PATH: %s\n", _getenv("PATH"));
	printf("HOME: %s\n", _getenv("HOME"));
	printf("ROOT: %s\n", _getenv("ROOT"));
	printf("\n");
	return (0);
}

