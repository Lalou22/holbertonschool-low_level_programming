/*
 * File: 0-path.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <dirent.h>

/**
 * main - Write a program that looks for files in the current PATH.
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Description: Write a program that looks for files in the current PATH.
 * Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	struct dirent *de;  /* Pointer for directory entry. */
	DIR *dr = opendir("."); /* opendir() returns a pointer of DIR type. */

	if (dr == NULL)  /* opendir returns NULL if couldn't open directory */
	{
		printf("Could not open current directory");
		return (1);
	}

	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);

	closedir(dr);
	return (0);
}
