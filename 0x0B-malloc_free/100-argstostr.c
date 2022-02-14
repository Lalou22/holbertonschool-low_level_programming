/*
 * File: 100-argstostr.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
/**
 * argstostr - Function that concatenates all the arguments.
 * @ac: Argument counts.
 * @av: Argument values.
 *
 * Description: Write a function that concatenates all the arguments
 * of your program. Returns NULL if ac == 0 or av == NULL.
 * Each argument should be followed by a \n in the new string.
 * Return: a pointer to a new string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, total_char = 0;
	char *concat_s;

	if (ac <= 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			total_char++;
		total_char++; /* Space for the breakline */
	}
	total_char++; /* Space for the ending char */
	concat_s = malloc(total_char * sizeof(char));
	if (concat_s == NULL)
		return (NULL);
	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			concat_s[k] = av[i][j];
			k++;
		}
		concat_s[k] = '\n';
		k++;
	}
	concat_s[k] = '\0';
	return (concat_s);
}
