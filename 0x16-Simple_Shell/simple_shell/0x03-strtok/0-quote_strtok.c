#include <stdio.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)

char **split_line(char *line, char *delim, char *c1, char *c2);
char *read_line(void);
char *remove_char(char *line, char c);
int _strlen(char *s);
char *_strncpy(char *src, int n);
char *_strcat(char *s1, char *s2);
int compare_chars(char c, char *str);
void print_parse(char **args);

int main(int ac, char **av, char **env)
{
	char *line;
	char **_commands;

	UNUSED(ac);
	UNUSED(av);
	UNUSED(env);

	printf("$ ");
	line = read_line();
	_commands = split_line(line, " ", "\"", "\"");
	print_parse(_commands);
	return (0);
}

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
	line = remove_char(line, '\n');
	return (line);
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

/**
 * _strlen - Function that returns the length of a string.
 * @s: Pointer to the char string.
 *
 * Description: The standard library provides a similar function: strlen.
 * Run man strlen to learn more.
 * Return: Length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strncpy - Write a function that copies a string..
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Integer that limits concat.
 *
 * Description: Function that copy the src string to the dest string.
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *src, int n)
{
	int len;
	char *aux = malloc(sizeof(char) * n);

	for (len = 0; src[len] !=  '\0' && len < n; len++)
		aux[len] = src[len];
	aux[len] = '\0';
	return (aux);
}

/**
 * _strcat - Function that concatenates two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Description: Function that appends the s2 to  s1.
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *s1, char *s2)
{
	int i, l1, l2;
	char *str;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	for (i = 0; i < l1; i++)
		str[i] = s1[i];
	for (i = 0; i < l2; i++)
		str[l1 + i] = s2[i];
	str[l1 + l2] = '\0';
	return (str);
}

/**
 * compare_chars - Function that loops str to compare with c.
 * @c: Char to be compared.
 * @str: String with different chars.
 *
 * Description: Function that loops str, and compares c.
 * Return: 1 if equals and 0 otherwise.
 */
int compare_chars(char c, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * print_parse - Function that prints a 2D-pointer array.
 * @args: 2D-pointer array to be printed.
 *
 * Description: Function used for testing.
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

char **split_line(char *line, char *delim, char *c1, char *c2)
{
    int i = 0, j = 0, k = 0, bufsize = 64, position = 0; 
    int diff, f_del = 0, f_op = 0, f_cl = 0;
    char *aux = "";
    char *token;
    char **tokens = malloc(bufsize * sizeof(char *));
    
    while (line[i])
    {
        f_op = compare_chars(line[i], c1);
        /* If found an char on the 'opening' string */
        if (f_op == 1)
        {
            for(k = i + 1; line[k] && f_cl != 1; k++)
                f_cl = compare_chars(line[k], c2);
            if (f_cl == 1)
            {
                diff = k - i;
                aux = _strncpy(line + i, diff);
                f_op = 0;
                f_cl = 0;
                i = k;
                j = k;
            }
        }
        f_del = compare_chars(line[i], delim);
        /* If found an char on the 'delim' string */
        if ((f_del == 1 && f_cl == 0) || line[i + 1] == '\0')
        {
            diff = i - j;
            if(line[i + 1] == '\0')
                diff++;
            token = _strncpy(line + j, diff);
            token = _strcat(aux, token);
            aux = "";
            /* printf("Token %i: %s\n", position, token); */
            tokens[position] = token;
            position++;
            j = i + 1;
        }
        i++;
    }
    tokens[position] = NULL;
	return (tokens);
}
