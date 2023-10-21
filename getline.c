#include "shell.h"

static char buffer[BUFFER_SIZE];
static size_t buffer_pos;
static size_t buffer_size;

/**
 * read_buffer - Read data into the buffer.
 *
 * @stream: The input stream (e.g., stdin).
 * Return: The number of characters read or -1 on error.
 */
static ssize_t read_buffer(FILE *stream)
{
	if (buffer_pos >= buffer_size)
	{
		buffer_size = read(_fileno(stream), buffer, BUFFER_SIZE);
		buffer_pos = 0;
	}

	return (buffer_size);

}

/**
 * append_char - Append a character to the line buffer.
 * @lineptr: Pointer to the line buffer.
 * @n: Pointer to the current buffer size.
 * @c: The character to append.
 * @line_length: Pointer to the current line length.
 * Return: 0 on success, -1 on memory allocation failure.
 */
static int append_char(char **lineptr, size_t *n, char c, size_t *line_length)
{
	if (*line_length + 1 >= *n)
	{
		size_t new_size = (*n == 0) ? 128 : (*n) * 2;
		char *new_line = (char *)realloc(*lineptr, new_size);

		if (!new_line)
			return (-1);

		*lineptr = new_line;
		*n = new_size;

	}
	(*lineptr)[(*line_length)++] = c;
	return (0);

}

/**
 *_getline - Custom getline function.
 * @lineptr: Pointer to the line buffer.
 * @n: Pointer to the current buffer size.
 * @stream: The input stream (e.g., stdin).
 * Return: The number of characters read, or -1 on error or end of file.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t line_length = 0;
	int newline_found = 0;

	buffer_pos = 0;
	buffer_size = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (1)
	{
		if (read_buffer(stream) <= 0)
		{
			if (line_length > 0)
			{	newline_found = 1;

			} else
				return (-1);
		}

		for (; buffer_pos < buffer_size; buffer_pos++)
		{	char c = buffer[buffer_pos];

			if (c == '\n')
			{	newline_found = 1;
				buffer_pos++;
				break;
			}

			if (append_char(lineptr, n, c, &line_length) == -1)
				return (-1);
		}

		if (newline_found)
		{	(*lineptr)[line_length] = '\0';
			return (line_length);
		}
	}
}

