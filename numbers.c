#include "shell."

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
