/*
 * File: 0-path.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Stat + opendir example
 * @ac: Number of arguments passed to the program.
 * @av: Array of strings. Each is one of the arguments that was passed.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	struct dirent *de;
	DIR *dr;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf(" FOUND\n");
			dr = opendir(av[i]);
			while ((de = readdir(dr)) != NULL)
				printf("%s\n", de->d_name);
			closedir(dr);
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
