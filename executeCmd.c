#include "shell.h"
/**
 * executeCommand - Entry
 *
 * @command: command
 *
 * @argv: a comand argument
 */

void executeCommand(char *command, char *argv[])
{
	char *ar[MAX_ARGS];
	int i = 0;
	pid_t pid;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		ar[i++] = token;
		token = strtok(NULL, " ");
	}
	ar[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: Fork unsuccessful");
		return;
	}
	if (pid == 0)
	{
		if (execve(ar[0], ar, environ) == -1)
		{
			perror(argv[0]);
			exit(1);
		}

		exit(0);
	}
	else
	{
		wait(NULL);
	}
}
