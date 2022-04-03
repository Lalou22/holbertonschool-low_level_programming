/*
 * File: 0-av.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - Write a program that prints all the arguments, without using ac.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Write a program that prints all the arguments, without using ac.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
