#include "shell.h"
/**
 * executeCommand - Entry
 *
 * @command: command
 */

void executeCommand(char *command, char *argv[])
{
	char *ar[MAX_ARGS];
	int i = 0;
	pid_t pid;

	char *token = strtok(command, " \n");

	while (token != NULL)
	{
		ar[i++] = token;
		token = strtok(NULL, " \n");
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
		execve(ar[0], ar, NULL);
		_printf("%s: No such file or directory\n", argv[0]);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
