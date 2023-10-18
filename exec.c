#include "shell.h"

/**
 * executeCommandArg - ...
 *
 * @commandArg: a command argument
 *
 * @argv: a comand argument
 */

void executeCommandArg(char *commandArg, char *argv[])
{
	int i = 0;
	pid_t pid;
	char *arguments[256];
	char *token = strtok(commandArg, " \t");

	while (token != NULL)
	{
		arguments[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}
	arguments[i] = NULL;

	if (arguments[0] == NULL)
	{
		perror(argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror(argv[0]);
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
	char *original_path = _getenv("PATH");
	char *path = _strdup(original_path);
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
				size_t result_len = _strlen(file_path) + _strlen(arg) + 2;
				char *res = (char *)malloc(result_len);

				_snprintf(res, result_len, "%s %s", file_path, arg);
				free(path);
				return (res);
			}
			else
			{
				free(path);
				return (_strdup(file_path));
			}
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
