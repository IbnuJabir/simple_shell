#include "shell.h"

/**
 * _strncmp - Compare two strings up to a specified length
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: An integer less than, equal to, or greater than zero if the first n
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strchr - Locate the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: A pointer to the first occurrence of the character c in the string s.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (NULL);
}
/**
 * _strcspn - Custom implementation of strcspn function.
 * @str: The string to search in.
 * @reject: The characters to reject.
 *
 * Return: The length of the initial segment of @str
 *         that does not contain any character from @reject.
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *s1, *s2;

	for (s1 = str; *s1; ++s1)
	{
		for (s2 = reject; *s2; ++s2)
		{
			if (*s1 == *s2)
			return ((size_t)(s1 - str));
		}
	}
	return ((size_t)(s1 - str));
}
