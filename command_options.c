#include "shell.h"

/**
 * exit_shell - exits the shell
 * @command: input command
 * Description: exit with status 0 else set status(pending)
 */

void exit_shell(char *command)
{

	if (_strchr(command, ' ') == NULL)
	{
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}
	}
}



/**
 * is_command_executable - check if command is executable
 * @command: command
 * @argv: pointer to command line strings
 * Description: if found executes else prints error associated with the command
 */

void is_command_executable(char *command, char *argv[])
{
	char firstChar = command[0];

	if (firstChar == '/' || (firstChar == '.' && command[1] == '/'))
	{
		if (_strchr(command, ' ') != NULL)
		{
			executeCommand(command, argv);
		}
		else
		{
			executeCommandArg(command, argv);
		}

	}
	else
	{
	char *str = path(command);

	if (str == NULL)
	{
		static int error_counter = 0;
		error_counter++;

		if (!isatty(_fileno(stdin)))
		{
			const char *message = ": not found";
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, _itoa(error_counter), _strlen(_itoa(error_counter)));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, command, _strlen(command));
			write(STDERR_FILENO, message, _strlen(message));
		}
		else
		{
			_printf("%s: No such file or directory\n", argv[0]);
		}
	}
	else if (_strchr(str, ' ') != NULL)
	{
		executeCommand(str, argv);
	}
	else
	{
		executeCommandArg(str, argv);
	}
	free(str);
}
	
}
