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

/*
 * Macro used to avoid warnings for unused arguments on main
 */
#define UNUSED(x) (void)(x)

/* Functions related to read from line */
char *read_line(void);
char *_getline(void);
char *remove_char(char *line, char c);

/* Auxiliar functions to work with strings */
int _strlen(char *s);
char *_strncpy(char *src, int n);
char *_strdup(char *original);
int compare_chars(char c, char *str);
char *_strcat(char *s1, char *s2);

/* Functions related to PATH and execute */
char **find_path(char **env);
char **path_com(char **_path, char *command);
void execute_path(char **_path);
void func_exec(char *pathname, char **argv, char *const envp[]);
char **split_line(char *line, char *delim, char *c1, char *c2);

/* Extra functions */
char **make_env(char **env);
void print_parse(char **args);

#endif /* _SHELL_H_ */
