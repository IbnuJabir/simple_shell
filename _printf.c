#include "shell.h"

/**
 * function_selector - Matches format specifier with the handler function
 * @args: va_list object with the variable arguments
 * @f_specifier: format specifier character after '%' in format string
 *
 * Return: Length of the variable.
 */
int function_selector(va_list args, const char f_specifier)
{
	if (f_specifier == 'c')
		return (handle_char(args));

	if (f_specifier == 's')
		return (handle_string(args));

	if (f_specifier == 'i' || f_specifier == 'd')
		return (handle_number(args));

	/* Unknown specifier, print it as-is */
	_putchar('%');
	_putchar(f_specifier);
	return (2);
}
/**
 * _printf - this is a custom printf function that writes characters on
 * the standard output
 * @format: format specifier string
 * Return: number of characters printed to the stdout
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list vargs;

	va_start(vargs, format);

	/* iterate format string up to the last non-null character */
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			/* move to the next char after % */
			++format;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
				count += _putchar('%');
			else
				/* call function selector */
				count += function_selector(vargs, *format);
		}
	format++;
	}

	va_end(vargs);
	return (count);
}

