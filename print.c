#include "shell.h"

/**
 * print_string - prints a string to stdout
 * @s: pointer to a string
 * Return: number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_string(char *s)
{
	return (write(STDOUT_FILENO, s, str_len(s)));
}

/**
 * show_error - prints errors to stderr
 * @code: error code to be printed
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int show_error(int code, shell_data *shell)
{
	char *string;
	int len = 0;
	int i = 0;
	int j;
	int k;
	char *ptr;

	while (*string)
	{
		len++;
		string++;
	}

	if (code == 2 || code == 3)
	{
		ptr = shell->exe;

		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, ": ", 1);
		for (i = 0; i < len; i++)
			write(STDERR_FILENO, string + i, 1);
		write(STDERR_FILENO, ": ", 1);
		ptr = shell->words[0];
		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		if (code == 2)
			write(STDERR_FILENO, ": Wrong number: ", 14);
		else
		write(STDERR_FILENO, ": can't change directory to ", 12);
		ptr = shell->words[1];
		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, "\n", 1);
	}
	else if (code == 127)
	{
		ptr = shell->exe;

		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, ": ", 1);
		for (j = 0; j < len; j++)
			write(STDERR_FILENO, string + j, 1);
		write(STDERR_FILENO, ": ", 1);
		ptr = shell->exe;
		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, ": not found\n", 12);
	}
	else if (code == 126)
	{
		ptr = shell->exe;

		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, ": ", 1);
		for (k = 0; k < len; k++)
			write(STDERR_FILENO, string + i, 1);
		write(STDERR_FILENO, ": ", 1);
		ptr = shell->exe;
		while (*ptr)
		{
			write(STDERR_FILENO, ptr, 1);
			ptr++;
		}
		write(STDERR_FILENO, ": Permission denied\n", 19);
	}
	return (0);
}

