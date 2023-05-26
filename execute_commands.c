#include "shell.h"

/**
 * execute_commands - executes commands passed to it
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int execute_commands(shell_data *shell)
{
	int code = 0;
	int shell_status;
	pid_t child_pid;

	code = handle_builtins(shell);

	if (code  != -1)
		return (code);

	code = handle_path(shell);

	if (code)
		return (code);
	else
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror(shell->command);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			code = execve(shell->words[0], shell->words, shell->env);
			if (code == -1)
			{
				perror(shell->command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&shell_status);
			if (WIFEXITED(shell_status))
				errno = WEXITSTATUS(shell_status);
			else if (WIFSIGNALED(shell_status))
				errno = 128 + WTERMSIG(shell_status);
		}
	}
		return (0);
}
