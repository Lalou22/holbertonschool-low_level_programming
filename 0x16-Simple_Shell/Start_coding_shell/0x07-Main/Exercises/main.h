#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

int _putchar(char c);
char *_getenv(const char *name);
int starts_with(char *haystack, const char *needle);
char *_getpath(char *dir_);
void print_elem(char *dir_);
list_t *add_node(list_t **head, const char *str);
size_t print_list(const list_t *h);
void add_substring(list_t *head, char *dir_);

#endif /* MAIN_H */
