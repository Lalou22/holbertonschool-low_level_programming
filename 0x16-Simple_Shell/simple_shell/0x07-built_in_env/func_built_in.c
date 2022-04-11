#include "shell.h"

/**
 * check_for_builtins - Function that "checks" for a built-in implemenatation.
 * @built_in: String with the name of the built-in to be checked.
 * @env: Array of strings of the environment.
 *
 * Description: Function that gets a built-in and checks for existance.
 * If found executes the built-in and returns an integer bigger than 0.
 * Return: 0 if not found the built-in.
 */
int check_for_builtins(char *built_in, char **env)
{
	int found = 0;

	if (_strcmp(built_in, "exit") == 0)
	{
		found = 1;
		new_exit();
	}
	if (_strcmp(built_in, "env") == 0)
	{
		found = 2;
		print_parse(env);
	}
	if (_strcmp(built_in, "clear") == 0)
	{
		found = 4;
	        clear_screen();
	}
	return (found);
}

/**
 * new_exit - Function to exit the shell.
 *
 * Description: Exits the shell.
 * Return: Void.
 */
void new_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * clear_screen - Function that clears the shell screen.
 *
 * Description: Uses the system call to clear the shell screen.
 * The system function must be changed to avoid the system call.
 * Return: Void.
 */
void clear_screen(void)
{
        system("clear");
}
