/*
 * File: 1-env_environ.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - printenv with environ
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 * @env: A NULL terminated array of strings.
 *
 * Description: Write a program that prints the environment using the global
 * variable environ and the env of the main function.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	extern char **environ;

	printf("Addres of environ = %p\n", environ[0]);
	printf("Addres of main env = %p\n", env[0]);
	return (0);
}
