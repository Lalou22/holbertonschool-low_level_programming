/*
 * File: 2-append_text_to_file.c
 * Auth: Lalo Rdz
 */
#include "main.h"

/**
 * append_text_to_file - Function that appends text at the end of a file.
 * @filename: Name of the file to create.
 * @text_content: String to write to the file.
 *
 * Description: Function that appends text at the end of a file.
 * If text_content is NULL, do not add anything to the file.
 * Do not create the file if it does not exist.
 * Return: 1 success otherwise -1 fail.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int _file, output, len;

	if (filename == NULL)
		return (-1);
	_file = open(filename, O_WRONLY | O_APPEND);

	if (_file == -1)
		return (-1);
	if (text_content == NULL)
		return (1);

	len = _strlen(text_content);
	output = write(_file, text_content, len);
	close(_file);
	if (output == -1 || output != len)
		return (-1);
	return (1);
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

	while (s[i] != '\0')
		i++;
	return (i);
}
