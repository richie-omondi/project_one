#include "shell.h"

/**
 * exit_shell - exit built-in
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int exit_shell(shell_data *shell)
{
	int i;
	int status;

	if (shell->words[1] != NULL)
	{
		for (i = 0; i < str_len(shell->words[1]); i++)
		{
			if (!is_digit(shell->words[1][i]) && shell->words[1][i] != '+')
			{
				status = 7;
				break;
			}
		}
	}
	free_and_close(shell);
	exit(status);
}
