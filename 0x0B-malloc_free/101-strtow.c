/*
 * File: 101-strtow.c
 * Auth: Lalo Rdz
 */
#include <stdlib.h>
int count_words(char *str);
int count_chars(char *str);
/**
 * strtow - Function that splits a string into words.
 * @str: String to be splited.
 *
 * Description: Function that splits a string into words.
 * Each element of this array should contain a single word, null-terminated.
 * The last element of the returned array should be NULL
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **array_words;
	int i = 0;
	int words, chars, j, k;

	if (str[0] == '\0' || str == NULL)
		return (NULL);

	words = count_words(str); /*Get the word count*/
	if (words == 0)
		return (NULL);

	array_words = malloc((words + 1) * sizeof(char *));
	if (array_words == NULL)
		return (NULL);

	for (j = 0; j < words; j++)
	{
		while (str[i] == ' ') /*Loop used to ignore blanks*/
			i++;

		chars = count_chars(str + i); /*Get the char count*/
		array_words[j] = malloc((chars + 1) * sizeof(char));
		if (array_words[j] == NULL)
		{
			while (j >= 0) /*Free memory if one word is NULL*/
			{
				free(array_words[j]);
				j--;
			}
			free(array_words);
			return (NULL);
		}

		for (k = 0; k < chars; k++) /*Copies chars into the array*/
			array_words[j][k] = str[i++];

		array_words[j][k] = '\0'; /*Sets termination*/
	}
	array_words[j] = NULL; /*Sets last word to be NULL*/
	return (array_words);
}
/**
 * count_words - Function that counts the number of words.
 * @str: String to be splited.
 *
 * Description: Counts for every string that starts with a different
 * char than blank ' '.
 * Return: Number of words.
 */
int count_words(char *str)
{
	int count, i = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != ' ')
		{
			count++;
			i += count_chars(str + i);
		}
	}
	return (count);
}
/**
 * count_chars - Function that counts the chars in each word.
 * @str: String to be splited.
 *
 * Description: Counts for every char different than blank ' '.
 * Return: Number of chars.
 */
int count_chars(char *str)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		len++;
		i++;
	}
	return (len);
}
