/*
 * File: 0-getppid.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <unistd.h>

/**
 * main - Write a program that prints the PID of the parent process.
 *
 * Run your program several times within the same shell.
 * Does echo $$ print the same value? Why?
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t parent_pid;

	my_pid = getpid();
	parent_pid = getppid();
	printf("Pid: %u\n", my_pid);
	printf("Parent Pid: %u\n", parent_pid);
	return (0);
}
