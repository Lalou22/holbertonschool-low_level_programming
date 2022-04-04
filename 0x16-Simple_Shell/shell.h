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

/* Functions created to Parse and Tokenize the User's Input */
char *read_line(void);
char **split_line(char *line);
void print_parse(char **args); /* Function used to test the parsing and tokenizing */

/* Functions used to work with char arrays */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif /* _SHELL_H_ */
