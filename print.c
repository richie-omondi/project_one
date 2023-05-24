/**
 * print_string - prints a string to stdout
 * @s: pointer to a string
 * Return: number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_string(char *s)
{
	return (write(STDOUT_FILENO, str, str_len(s)));
}
