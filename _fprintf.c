#include "shell.h"
/**
 * _fprintf - Custom function for formatted output to a stream.
 * @stream: The output stream.
 * @format: The format string.
 * @...: Optional arguments to format and write.
 *
 * Returns: Number of characters written on success, a negative value on failure.
 */
int _fprintf(FILE *stream, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = _vfprintf(stream, format, args);
	va_end(args);

	return (result);
}
/**
 * _vfprintf - Custom function for formatted output to a stream with a va_list argument.
 * @stream: The output stream.
 * @format: The format string.
 * @argptr: The va_list argument.
 *
 * Returns: Number of characters written on success, a negative value on failure.
 */
int _vfprintf(FILE *stream, const char *format, va_list argptr)
{
	int count = 0;
	const char *p = format;

	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
				case 'd':
				{
					int value = va_arg(argptr, int);
					count += fprintf(stream, "%d", value);
					break;
				}
				case 's':
				{
					char *value = va_arg(argptr, char *);
					count += fprintf(stream, "%s", value);
					break;
				}
				default:
					count += fprintf(stream, "%%%c", *p);
					break;
			}
		}
		else
		{
			fputc(*p, stream);
			count++;
		}

		p++;
	}

	return (count);
}
