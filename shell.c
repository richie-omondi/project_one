#include "shell.h"

/**
 * handle_signal - prints a new prompt upon a signal
 * @signal: signal
 *
 * Return: void
 */
void handle_signal(int signal)
{
	char *shell_sign = "\n($) ";

	(void)signal;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, prompt, 20);
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

	struct shell_data shell_info = {NULL};

	struct shell_data *shell = &shell_info;

	add_data_to_shell(shell, argc, argv, env);

	signal(SIGINT, handle_signal);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		shell_sign;

	loop_shell(shell_sign, shell);

	return (0);
}
