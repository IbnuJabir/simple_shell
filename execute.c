#include "shell.h"
/**
 * execute - Entry
 *
 */

void execute(char *argv[])
{
	char *command = NULL;
	size_t len = 0;
	char firstChar;

	while (1)
	{
		const char *msg = "#cisfun ";

		_puts(msg);
		fflush(stdout);
		if (getline(&command, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}
		command[_strcspn(command, "\n")] = '\0';
		firstChar = command[0];
		if (_strcmp(command, "exit") == 0)
			exit(0);
		else if (_strcmp(command, "env") == 0)
			printEnvironment();
		else if (firstChar == '/')
		{
			if (_strchr(command, ' ') != NULL)
				executeCommand(command, argv);
			else
				executeCommandArg(command, argv);
		}
		else
		{
			char *str = path(command);

			if (_strchr(str, ' ') != NULL)
				executeCommand(str, argv);
			else
				executeCommandArg(str, argv);
		}
	}
	free(command);
}
