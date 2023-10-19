#include "shell.h"

/**
 * _fileno - finds the file descriptor number of a stream
 *  @stream: the stream
 *  Description: find fd no from the _fileno member of FILE structure
 *  Return: file descriptor number or -1 if the stream is not in fd table
 */

int _fileno(FILE *stream)
{
	if (stream == NULL)
	{
		return (-1);
	}

	return (stream->_fileno);
}
