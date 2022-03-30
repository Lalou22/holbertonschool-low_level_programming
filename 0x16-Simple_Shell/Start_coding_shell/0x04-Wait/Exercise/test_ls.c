/*
 * File: test_ls.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - Write a program that executes the command ls -l /tmp.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Write a program that executes the command ls -l /tmp.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	printf("ls command...\n");
	execve(argv[0], argv, NULL);
	return (0);
}
