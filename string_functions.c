#include "shell.h"

/**
 * str_dup - Returns a pointer to a newly-allocated space in memory
 * containing a copy of the string given as parameter.
 * @string: The string to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 * Otherwise - a pointer to the duplicated string.
 */
char *str_dup(char *string)
{
	int i = 0;
	int length = 0;
	char *dup = NULL;

	if (string == NULL)
		return (NULL);

	for (i = 0; *(string + i); i++)
		length++;

	dup = malloc(sizeof(char) * (length + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; *(string + i); i++)
		*(dup + i) = *(string + i);

	*(dup + length) = '\0';

	return (dup);
}

/**
 * str_len - checks the length of a string
 * @string: pointer to string to check
 *
 * Return: int length of the string
 */

int str_len(char *string)
{
	int len = 0;

	while (*(string + len))
		len++;
	return (len);
}

/**
 * _strncpy - Copies at most an inputted number
 * of bytes from string src into dest.
 * @destination: The buffer storing the string copy.
 * @source: The source string.
 * @n: The maximum number of bytes to copied from src.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *destination, char *source, int n)
{
	int i = 0;
	int length_of_source = 0;

	while (source[i++])
		length_of_source++;

	for (i = 0; source[i] && i < n; i++)
		destination[i] = source[i];

	for (i = length_of_source; i < n; i++)
		destination[i] = '\0';

	return (destination);
}

/**
 * *str_cpy -  copies the string pointed to by src
 * @destination: char type string
 * @source: char type string
 * Description: Copy the string pointed to by pointer `src` to
 * the buffer pointed to by `dest`
 * Return: Pointer to `dest`
 */

char *str_cpy(char *destination, char *source)
{
	int index = -1;

	do {
		index++;
		*(destination + index) = *(source + index);
	} while (*(source + index) != '\0');

	return (destination);
}

/**
 * *str_cat - concatenates @src to @dest
 * @source: the source string to append to @dest
 * @destination: the destiation string to be concatenated upon
 * Return: pointer to the resulting string
 */

char *str_cat(char *destination, char *source)
{
	int i = 0;
	int destination_length = str_len(destination);

	while (source[i] != '\0')
	{
		destination[destination_length + 1] = source[i];
		i++;
	}
	destination[destination_length + i] = '\0';
	return (destination);
}
