#include "main.h"
/**
 * _getenv - Function that gets an environment variable.
 * @name: String with the environment variable.
 *
 * Description: Function that gets an environment variable.
 * Without using getenv.
 * Return: Environment variable, or NULL.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		if (starts_with(environ[i], name) != 0)
			return (_getpath(environ[i]));
		i++;
	}
	return (NULL);
}

/**
 * starts_with - Function that locates if the string starts with needle.
 * @haystack: Pointer to destination string.
 * @needle: Pointer to second string to be found.
 *
 * Description: Finds if the haystack starts with needle.
 * Return: 0 if not found or 1 otherwise.
 */
int starts_with(char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack++ != *needle++)
			return (0);
	}
	return (1);
}

/**
 * _getpath - Function that locates the = and returns remainding text.
 * @dir_: Pointer to directory file.
 *
 * Description: Write a function that locates the = and returns all the next
 * text, after the symbol.
 * Return: Located substring, or NULL.
 */
char *_getpath(char *dir_)
{
	while (*dir_)
	{
		if (*dir_++ == '=')
			return (dir_++);
	}
	return (NULL);
}

/**
 * print_elem - Function that prints all the elements from PATH.
 * @dir_: Pointer to directory file.
 *
 * Description: Function that prints all the elements from PATH.
 * Return: Void
 */
void print_elem(char *dir_)
{
	int i = 0;

	while (dir_[i])
	{
		if (dir_[i] != ':')
			_putchar(dir_[i]);
		else
			_putchar('\n');
		i++;
	}
}

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Pointer to the header that Starts the list.
 * @str: String to be added (malloc'ed string).
 *
 * Description: Function that adds a new node at the beginning of a list_t
 * list. And str needs to be duplicated.
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;

	if (str == NULL)
		return (NULL);

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->next = *head;
	*head = node;
	return (node);
}

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the header that Starts the list.
 *
 * Description: Prints the elements of the list's head and then starts printing
 * the next elements. Then returns the number of the printed nodes.
 * If str is NULL, print [0] (nil)
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	unsigned int i;
	const list_t *aux;

	aux = h; /* Gets the list's First element "Head". */
	for (i = 0; aux; i++)
	{
		if (aux->str == NULL)
			printf("(nil)\n");
		else
			printf("%s\n", aux->str);
		aux = aux->next; /* Gets the next element of the list. */
	}
	return (i);
}


void add_substring(list_t *head, char *dir_)
{
	int i = 0, j = 0;
	int len = 0;
	char *dest;
	

	while (dir_[i])
	{
		if (dir_[i] == ':' || dir_[i + 1] == '\0')
	        {
			if (dir_[i + 1] == '\0')
				i++;
		        dest = malloc(sizeof(char) * 100);
			len = i - j;
			add_node(&head, strncpy(dest, dir_ + j, len));
			j = i + 1;
		        free(dest);
			if (dir_[i] == '\0')
				i--;
		}
		i++;
	}
        print_list(head);
}
