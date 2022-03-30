/*
 * File: 1-sub.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - Stat + opendir example
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 * @env: Array of strings for the enviornment.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i = 0;

	printf("Sub program started with args: ");
	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\nSub program environment:\n");
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);	
}
