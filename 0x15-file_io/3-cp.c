/*
 * File: 3-cp.c
 * Auth: Lalo Rdz
 */
#include "main.h"
void error_id(int stat, ...);

/**
 * main - main function entry point
 * @argc: number of arguments passed
 * @argv: arguments being passed
 * Return: 98 read err, 99 write err, 100 close err, 0 sucess
 *
 */
int main(int argc, char **argv)
{
	int input, output, file_r, file_w, buff_size = 1024;
	char *buffer;
	mode_t file_perm;

	/* Check for errors on arguments. */
	if (argc != 3)
		error_id(97);
	if (argv[1] == NULL)
		error_id(98, argv[1]);
	if (argv[2] == NULL)
		error_id(99, argv[2]);
	/* Check for errors on Input and Output files. */
	input = open(argv[1], O_RDONLY);
	if (input == -1)
		error_id(98, argv[1]);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	if (output == -1)
		error_id(99, argv[2]);
	/* Creates the buffer and checks for errors. */
	buffer = malloc(buff_size * sizeof(char));
	if (buffer == NULL)
		return (1);
	/* Reads the input file and checks for errors. */
	file_r = read(input, buffer, buff_size);
	if (file_r == -1)
		error_id(98, argv[1]);
	/* Loop that writes the file and checks for errors. */
	while (file_r > 0)
	{
		file_w = write(output, buffer, file_r);
		if (file_w == -1)
			error_id(99, argv[2]);
		file_r = read(input, buffer, buff_size);
		if (file_r == -1)
			error_id(98, argv[1]);
	}
	free(buffer);
	if (close(input) == -1)
		error_id(100, input);
	if (close(output) == -1)
		error_id(100, output);
	return(0);
}

/**
 * error_id - Function that checks the error code.
 * @stat: Int that represent the error code.
 * @...: Variadic arguments for specific error codes.
 *
 * Description: Error id selector.
 * Return: Void.
 */
void error_id(int stat, ...)
{
	va_list list;

	va_start(list, stat);
	if (stat == 97)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	else if (stat == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file ");
		dprintf(STDERR_FILENO, "%s\n", va_arg(list, char *));
		exit(98);
	}
	else if (stat == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to ");
		dprintf(STDERR_FILENO, "%s\n", va_arg(list, char *));
		exit(99);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd ");
		dprintf(STDERR_FILENO, "%d\n", va_arg(list, int));
		exit(100);
	}
	va_end(list);
}
