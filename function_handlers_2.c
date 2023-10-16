#include "shell.h"

/**
 * handle_custom_str - handles 'S'
 * @args: va_list object
 * Return: number of characters printed to the stdout
 */
int handle_custom_str(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";
	return (print_custom_string(s));
}
