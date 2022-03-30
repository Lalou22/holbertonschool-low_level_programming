/*
 * File: 0-environ.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - printenv with environ
 *
 * Description: Write a program that prints the environment using the global
 * variable environ.
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}
