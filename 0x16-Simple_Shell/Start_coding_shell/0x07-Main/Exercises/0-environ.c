/*
 * File: 0-environ.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork + wait + execve
 *
 * Description: Write a program that executes the command ls -l /tmp in 5 different child processes.
 * Each child should be created by the same process (the father).
 * Wait for a child to exit before creating a new child.
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;
	int i = 0;

	while(environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}
