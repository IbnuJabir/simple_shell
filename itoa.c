#include "shell.h"
/**
 * _itoa - Converts an integer to a string
 * @n: The integer to convert
 *
 * Return: A pointer to the resulting string
 */
char *_itoa(int n)
{
	char buffer[12];
	int sign = 1;
	int i = 0;
	char *result;
	int j;

	if (n == 0)
	{
		result = _strdup("0");
		if (!result)
			return (NULL);
		return (result);
	}
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		buffer[i++] = '-';
	buffer[i] = '\0';
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		result[j] = buffer[i - j - 1];
	}
	result[i] = '\0';
	return (result);
}

