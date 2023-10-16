#include "shell.h"

/**
 * executeCommandArg - ...
 *
 * @commandArg: a command argument
 *
 */

void executeCommandArg(char *commandArg, char *argv[])
{
	int i = 0;
	pid_t pid;
	char *arguments[256];
	char *token = strtok(commandArg, " ");

	while (token != NULL)
	{
		arguments[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arguments[i] = NULL;

	if (arguments[0] == NULL)
	{
		_printf("No command specified\n");
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(arguments[0], arguments, NULL);
		_printf("%s: No such file or directory\n", argv[0]);
		exit(1);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
		exit(1);
	}
}
/**
 * pathArg - Entry
 *
 * @commandArg: a command argument
 *
 * Return: the path of argument
 */

char *pathArg(char *commandArg)
{
	char *path = _getenv("PATH");
	char *command = strtok(commandArg, " ");
	char *arg = strtok(NULL, "\n");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char file_path[256];

		_snprintf(file_path, sizeof(file_path), "%s/%s", token, command);

		if (access(file_path, F_OK) == 0)
		{
			if (arg)
			{
				size_t result_len = strlen(file_path) + strlen(arg) + 2;
				char *res = (char *)malloc(result_len);

				_snprintf(res, result_len, "%s %s", file_path, arg);
				free(commandArg);
				return (res);
			}
			else
			{
				free(commandArg);
				return (_strdup(file_path));
			}
		}
		token = strtok(NULL, ":");
	}
	free(commandArg);
	return (NULL);
}
