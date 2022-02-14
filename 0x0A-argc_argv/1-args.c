/*
 * File: 1-args.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
/**
 * main - Write a program that prints the number of arguments.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: Prints argc - 1.
 * Return: Zero.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
