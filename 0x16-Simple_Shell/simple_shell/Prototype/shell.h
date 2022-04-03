#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct shell_com - Struct created to store the Av and Env, among other vars.
 * @av: Char **Array with the Command line arguments.
 * @env: Char **Array wiht the created environment.
 */
typedef struct shell_com
{
	char **av;
	char **env;
} shell_com;

/* Functions created to tokenize the input */
char *tokenizer(char *string, char delimiter, int len);
/* Functions used to work with char arrays */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif /* _SHELL_H_ */
