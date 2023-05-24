#include "shell.h"

/**
 * add_data_to_shell - adds data to the shell
 * @shell: pointer to the struct
 * @ac: number of arguments
 * @argv: array of strings as arguments
 * @env: environment variables
 *
 * Return: void
 */
void add_data_to_shell(shell_data *shell, int ac, char *av[], char **env)
{
	shell->exe = av[0];
	shell->input = NULL;
	shell->command = NULL;
	shell->counter = 0;

	int index = 0;

	if (ac == 1)
		shell->fd = STDIN_FILENO;
	else
	{
		shell->fd = open(av[1], O_RDONLY);
		if (shell->fd == -1)
		{
			perror(shell->exe);
			exit(127);
		}
	}
	shell->words = NULL;
	shell->env = _calloc(100, sizeof(char *));
	if (shell->env == NULL)
	{
		perror(shell->env);
		exit(127);
	}
	for (index = 0; env[index]; index++)
		shell->env[index] = str_dup(env[index]);
	shell->env[index] = NULL;
	shell->aliases = _calloc(50, sizeof(char *));
	if (shell->aliases == NULL)
	{
		perror(shell->aliases);
		exit(127);
	}
	for (index = 0; index < 50; index++)
		shell->aliases[index] = NULL;
	free_and_close(shell);
}
