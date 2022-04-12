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
int _strcmp(char *s1, char *s2);
int _putchar(char c);

/* Functions related to PATH and execute */
char **find_path(char **env);
char **path_com(char **_path, char *command);
char **execute_path(char *_shell, char **_path, char **env);
void func_exec(char *pathname, char **argv, char *const envp[]);
char **split_line(char *line, char *delim, char *c1, char *c2);

/* Functions related to built-in commands */
char** check_bi(char *bi, char *arg_0, char *arg_1, char **env, int *f);
void new_exit(char *arg_0);
char **set_env(char *var, char *val, char **env);
char **unset_env(char *var, char **env);
char **change_dir(char *arg, char **env);

/* Extra functions */
char **make_env(char **env);
void print_parse(char **args);
char *get_env_var(char *var_name, char **env, int *index, int *len_);

#endif /* _SHELL_H_ */
