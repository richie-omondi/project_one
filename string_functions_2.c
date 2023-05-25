#include "shell.h"

/**
 * str_cmp - Compares two strings.
 * @string_1: A pointer to the first string to be compared.
 * @string_2: A pointer to the second string to be compared.
 *
 * Return: If string_1 < string_2, the negative difference of
 * the first unmatched characters.
 * If string_1 == string_2, 0.
 * If string_1 > string_2, the positive difference of
 * the first unmatched characters.
 */
int str_cmp(char *string_1, char *string_2)
{
	while (*string_1 && *string_2 && *string_1 == *string_2)
	{
		string_1++;
		string_2++;
	}

	return (*string_1 - *string_2);
}

/**
 * _strncmp - Compares at most the first n bytes of two strings.
 * @str1: A pointer to the first string to be compared.
 * @str2: A pointer to the second string to be compared.
 * @n: number of bytes to compare
 *
 * Return: If str1 < str2, the negative difference of
 * the first unmatched characters.
 *         If str1 == str2, 0.
 *         If str1 > str2, the positive difference of
 *         the first unmatched characters.
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	return (*str1 - *str2);
}

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @str: The string to be searched.
 * @accept: The set of bytes to be searched for.
 *
 * Return: If a set is matched - a pointer to the matched byte.
 * If no set is matched - NULL.
 */
char *_strpbrk(char *str, char *accept)
{
	int i;

	while (*str)
	{
		for (i = 0; *(accept + i); i++)
		{
			if (*str == *(accept + i))
				return (str);
		}

		str++;
	}
	return ('\0');
}

/**
 * _strndup - Returns a pointer to a newly-allocated space in memory
 * containing a copy of the string given as parameter.
 * @s: The string to be copied.
 * @n: The maximum number of bytes to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 * Otherwise - a pointer to the duplicated string.
 */
char *_strndup(char *s, size_t n)
{
	char *dup;
	size_t i, length = 0;

	if (s == NULL)
		return (NULL);

	while (*(s + length))
		length++;
	if (n < length)
		length = n;

	dup = malloc(sizeof(char) * (length + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		*(dup + i) = *(s + i);

	*(dup + length) = '\0';

	return (dup);
}

/**
 * str_chr - Locates a character in a string.
 * @str: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 * If c is not found - NULL.
 */

char *str_chr(char *str, char c)
{
	int i;

	for (i = 0; *(str + i) >= '\0'; i++)
	{
		if (*(str + i) == c)
			return (str + i);
	}

	return ('\0');
}
