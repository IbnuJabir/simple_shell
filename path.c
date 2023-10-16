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

	if (_strchr(command, ' ') == NULL)
	{
		char *token = strtok(pathCopy, ":");

		while (token != NULL)
		{
			char file_path[256];

			_snprintf(file_path, sizeof(file_path), "%s/%s", token, command);

			if (access(file_path, F_OK) == 0)
			{
				char *ress = _strdup(file_path);

				free(pathCopy);
				return (ress);
			}
			token = strtok(NULL, ":");
		}
		free(pathCopy);
		return (NULL);
	}
	else
	{
		char *cm = pathArg(command);

		return (cm);
	}
}

/**
 * _strdup - Create a duplicate of a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string,
 * or NULL if the allocation fails.
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
		_memcpy(dup, str, len);

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
