#include "shell.h"

/**
 * print_prompt - prints a prompt messege.
 * Description: prints a prompt only if the input is from stdin.
 */

void print_prompt(void)
{
	const char *msg = "#cisfun$ ";

	if (isatty(_fileno(stdin)))
	{
		_puts(msg);
		fflush(stdout);

	}
}

