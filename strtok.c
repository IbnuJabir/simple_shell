#include "shell.h"

/**
 * token_t_len - Locates the delimiter index marking the end
 *             of the first token_t contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token_t pointed to be str.
 */
int token_t_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}

/**
 * count_token_ts - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int count_token_ts(char *str, char *delim)
{
	int index, token_ts = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			token_ts++;
			index += token_t_len(str + index, delim);
		}
	}

	return (token_ts);
}

/**
 * _strtok - token_tizes a string.
 * @line: The string.
 * @delim: The delimiter character to token_tize the string by.
 *
 * Return: A pointer to an array containing the token_tized words.
 */
char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, token_ts, t, letters, l;

	token_ts = count_token_ts(line, delim);
	if (token_ts == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (token_ts + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < token_ts; t++)
	{
		while (line[index] == *delim)
			index++;

		letters = token_t_len(line + index, delim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
