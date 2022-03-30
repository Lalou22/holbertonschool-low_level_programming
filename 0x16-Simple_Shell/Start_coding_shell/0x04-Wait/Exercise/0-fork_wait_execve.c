#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid, wpid;
	char *command = "/bin/ls -l /tmp";
	int status = 0;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Child %d:\n", i);
			printf("%d\n", child_pid);
			printf("My id is %d\n", getpid());
		        system(command);
			printf("----------------------------------------\n\n");
			sleep(3);
			exit(0);
		}
	}
	while ((wpid = wait(&status)) > 0);

	printf("Parent");
	printf("My id is %d\n", getpid());
        system(command);
	printf("--------------------\n\n");
	
	return (0);
}
