#include "shell.h"
/**
 * print_hex_u - Print a hexadecimal number in lowercase
 * @num: The unsigned integer to be printed as a hexadecimal number
 * Return: The number of characters printed
 */
int print_hex_u(unsigned int num)
{
	int j;
	int i = 0;
	int count = 0;
	char hex_digits[] = "0123456789ABCDEF";
	char hex_representation[32];

	if (num == 0)
		count += _putchar(0 + '0');
	while (num != 0)
	{
		hex_representation[i++] = hex_digits[num % 16];
		num /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		count += _putchar(hex_representation[j]);

	return (count);
}
