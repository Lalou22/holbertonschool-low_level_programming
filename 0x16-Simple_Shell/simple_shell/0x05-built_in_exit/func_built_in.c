#include "shell.h"

void check_for_builtins(char *built_in)
{
	if (_strcmp(built_in, "exit") == 0)
	    new_exit();
}
	
void new_exit(void)
{
        exit(EXIT_SUCCESS);
}
