#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int n_len = _strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, n_len) == 0 && environ[i][n_len] == '=')
		{
			return (environ[i] + n_len + 1);
		}
	}

	return (NULL);
}

/**
 * _vsnprintf - Custom implementation of vsnprintf function.
 * @str: Pointer to the destination buffer.
 * @size: Size of the destination buffer.
 * @format: Format string.
 * @args: Variable arguments list.
 *
 * Return: The number of characters written to the buffer.
 */
int _vsnprintf(char *str, size_t size, const char *format, va_list args)
{
	int written = 0;
	int capacity = size - 1;

	while (*format && written < capacity)
	{
		if (*format == '%')
		{
			++format;

			switch (*format)
			{
				case 's':
				{
					char *arg = va_arg(args, char *);

					while (*arg && written < capacity)
					{
						*str++ = *arg++;
						++written;
					}
					break;
				}
				default:
					*str++ = *format;
					++written;
					break;
			}
		}
		else
		{
			*str++ = *format;
			++written;
		}
		++format;
	}
	*str = '\0';
	return (written);
}

/**
 * _snprintf - Formats a string and writes it to a buffer.
 * @buffer: The buffer to write the formatted string.
 * @size: The size of the buffer.
 * @format: The format string.
 *
 * Return: The number of characters written, excluding the null terminator.
 */
int _snprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = _vsnprintf(buffer, size, format, args);
	va_end(args);

	return (result);
}

/**
 * printEnvironment - Prints the current environment variables
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_printf("%s\n", *env);
		env++;
	}
}

/**
 * _strcmp - Compare two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
