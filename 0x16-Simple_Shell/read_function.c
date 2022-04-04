#include "shell.h"
/**
 * read_line - Function that uses getline to read information from the user.
 * @void: Void parameter.
 *
 * Description: Utilices the standard function getline and checks for error.
 * Return: Char pointer "line".
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("readline");
			exit(1);
		}
	}
	return (line);
}
/**
 * split_line - Function that uses strtok to tokenize the string.
 * @line: String to be tokenized.
 *
 * Description: Utilices the standard function tokenize and checks for error.
 * Return: Char 2D-pointer "tokens".
 */
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char *delim = " \n";
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		printf("Error: Unable to allocate memory.");
		exit(1);
	}
	token = strtok(line, delim);
	while (token)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
 * print_parse - Function to test the tokens by printing on screen.
 * @args: String to be printed.
 *
 * Description: Function to test the tokens by printing on screen.
 * Return: Void.
 */
void print_parse(char **args)
{
	int i = 0, j;

	while (args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			printf("%c", args[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
