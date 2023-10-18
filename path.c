#include "shell.h"

/**
 * path - Entry
 *
 * @command: command line
 *
 * Return: the path of a command
 *
 **/

char *path(char *command)
{
	char *path = _getenv("PATH");
	char *pathCopy = _strdup(path);
	char *ress = NULL;

	if (_strchr(command, ' ') == NULL)
	{
		char *token = strtok(pathCopy, ":");

		while (token != NULL)
		{
			char file_path[256];

			_snprintf(file_path, sizeof(file_path), "%s/%s", token, command);

			if (access(file_path, F_OK) == 0)
			{
				ress = _strdup(file_path);

				free(pathCopy);
				return (ress);
			}
			token = strtok(NULL, ":");
		}
		free(pathCopy);
		if (ress)
			free(ress);

		return (NULL);
	}
	else
	{
		char *cm = pathArg(command);

		free(pathCopy);
		return (cm);
	}
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string or NULL on failure.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str) + 1;
	dup = malloc(len);

	if (dup != NULL)
	{
		_strcpy(dup, str);
	}
	return (dup);
}

/**
 * _strlen - Calculate the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
/**
 * _memcpy - Copy memory area
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory area.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *cdest = (char *)dest;
	const char *csrc = (const char *)src;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}
/**
* _strcpy - Copy a string to a destination buffer
* @dest: The destination buffer
* @src: The source string to be copied
*
* Return: A pointer to the destination buffer (dest).
*/
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while ((*dest++ = *src++) != '\0')
	{
		/* Copy characters from src to dest until the null terminator is reached */
	}

	return (original_dest);
}
