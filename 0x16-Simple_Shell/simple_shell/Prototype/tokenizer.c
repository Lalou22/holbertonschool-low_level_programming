#include "shell.h"
/**
 * tokenize - Tokenizes a buffer with a delimiter
 * @string: Buffer to tokenize
 * @delimiter: Delimiter to tokenize along
 * @len: Size of the string.
 *
 * Return: pointer to an array of tokens
 */
char *tokenizer(char *string, char delimiter, int len)
{
	char *aux = (char *) malloc(len);
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (string[i] == delimiter)
			break;
		aux[i] = string[i];
	}
	aux[i] = '\0';
	return (aux);
}
