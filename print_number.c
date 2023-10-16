#include "shell.h"
/**
 * print_number - prints signed and usigned numbers
 * @n: number
 * Return: number of characters in a number
 */
int print_number(int n)
{
	unsigned int count = 0;
	unsigned int temp;

	if (n < 0)
	{
		n = -n;
		temp = n;
		count += _putchar('-');
	}

	temp = n;
	temp /= 10;

	if (temp != 0)
		count += print_number(temp);

	count += _putchar((unsigned int) n % 10 + '0');
	return (count);
}
