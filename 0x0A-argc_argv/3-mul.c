/*
 * File: 3-mul.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Write a program that multiplies two numbers.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: Your program should print the result of the multiplication.
 * Assume that the two numbers and result can be stored in integer.
 * If the program does not receive two arguments, print Error.
 * Return: Zero.
 */
int main(int argc, char *argv[])
{
	int res;

	if (argc == 3)
	{
		res = atoi(argv[1]) *  atoi(argv[2]);
		printf("%d\n", res);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
