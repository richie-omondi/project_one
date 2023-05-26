#include "shell.h"

/**
 * _pow - Returns the value of x raised to the power of y.
 * @x: The number to be raised.
 * @y: The power.
 *
 * Return: The value of x raised to the power of y.
 */
int _pow(int x, int y)
{
	int result = x;

	if (y < 0)
		return (-1);

	else if (y == 0)
		return (1);

	result *= _pow(x, y - 1);

	return (result);
}

/**
 * is_digit - checks if a character is digit
 * @i: integer variable
 * Return: 1 if true, 0 if false
 */

int is_digit(int i)
{
	return (i >= 48 && i <= 57);
}

/**
 * num_char - locates and counts number of apperances of a character
 * in a string
 * @str: string
 * @letter: character to be located
 *
 * Return: final number
 */
int num_char(char *str, char *letter)
{
	int i
	int num = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == letter[0])
			num++;
	}
	return (num);
}
