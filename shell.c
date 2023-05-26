#include "shell.h"

/**
 * handle_signal - prints a new prompt upon a signal
 * @signal: signal
 *
 * Return: void
 */
void handle_signal(int num)
{
	char *shell_sign = "\n($) ";

	(void)num;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, shell_sign, 20);
}

/**
 * main - Entry point for the program
 * @ac: argument count
 * @argv: array of argument strings
 * @envp: environment variables
 *
 * Return: 0 on success
 */
int main(int ac, char *argv[], char *envp[])
{
	char *shell_sign = "\n($) ";
	char *str;

	shell_data shell_info = { NULL };

	shell_data *shell = &shell_info;

	add_data_to_shell(shell, ac, argv, envp);

	signal(SIGINT, handle_signal);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		str = shell_sign;

	loop_shell(shell_sign, shell);

	return (0);
}
