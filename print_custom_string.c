#include "shell.h"
/**
 * print_custom_string - replaces non-printable characters with
 * with equivalent ascii value in hex
 * @str: string
 * Return: length of printed string
 */
int print_custom_string(char *str)
{
	int i, count = 0;
	unsigned int ascii = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			count += _putchar(str[i]);
		}
		else
		{
			count += _putchar('\\');
			count += _putchar('x');
			ascii = str[i];

			if (ascii < 16)
				count += _putchar('0');
			count += print_hex_u(ascii);
		}
	}
	return (count);
}

