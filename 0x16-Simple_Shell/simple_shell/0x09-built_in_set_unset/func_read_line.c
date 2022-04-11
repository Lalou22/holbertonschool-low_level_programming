#include "shell.h"

/**
 * read_line - Function to read information from the user.
 * @void: Void parameter.
 *
 * Description: Utilices the standard function getline
 * and checks for error.
 * Return: Char pointer "line".
 */
char *read_line(void)
{
	char *line = NULL;

	line = _getline();
	line = remove_char(line, '\n');
	return (line);
}

/**
 * _getline - Function to read information from the user.
 * @void: Void parameter.
 *
 * Description: Utilices the standard function getline
 * and checks for error. See man getline.
 * Return: Char pointer "line".
 */
char *_getline(void)
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}
}

/**
 * remove_char - Function to creates a new_str removing all the selected char.
 * @line: Original char array that may contain the char to be ignored.
 * @c: Char to be ignored on the line.
 *
 * Description: Loops through the line and ignores the char 'c'.
 * Return: New line.
 */
char *remove_char(char *line, char c)
{
	char *new_line;
	int i, j, len;

	len = _strlen(line);
	new_line = malloc((len + 1) * sizeof(char));
	for (i = 0, j = 0; j < len; i++, j++)
	{
		if (line[i] == c)
			j++;
		new_line[i] = line[j];
	}
	new_line[i] = '\0';
	return (new_line);
}
