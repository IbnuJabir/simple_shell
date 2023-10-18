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

void is_command_executable(char *command, char **argv)
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
			_fprintf(stderr, "%s: 1: %s: not found", argv[0], command);
		}

		else if (_strchr(str, ' ') != NULL)
		{
			executeCommand(str, argv);

		}
		else
		{
			executeCommandArg(str, argv);
		}
	}
}
