#include "shell.h"
/**
 * execute - Entry
 *
 * @argv: a comand argument
 */

void execute(char *argv[])
{
	char *command = NULL;
	size_t len = 0;

	while (1)
	{
		print_prompt();

		if (getline(&command, &len, stdin) == -1)
		{
			_printf("\n");
			break;
		}
		command[_strcspn(command, "\n")] = '\0';

		if (*command == '\0')
			continue;

		exit_shell(command);

		if (_strcmp(command, "env") == 0)
		{
			printEnvironment();
		}

		is_command_executable(command, argv);
	}

	free(command);
}
