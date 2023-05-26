#include "shell.h"

/**
 * free_ptrs_arr - frees each pointer in an array of pointers and the array
 * @arr: array of pointers
 *
 * Return: void
 */
void free_ptrs_arr(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; *(arr + i); i++)
		free(*(arr + i));
	free(arr);
}

/**
 * free_specific_shell_data - frees the respective fields from
 * the shell_data struct
 * @shell: shell_data struct containing data fed to the shell
 *
 * Return: void
 */
void free_specific_shell_data(shell_data *shell)
{
	int index;
	if (shell->words != NULL)
	{

		for (index = 0; shell->words[index] != NULL; index++)
			free(shell->words[index]);
		for (index = 0; shell->words[index] != NULL; index++)
			free(shell->words[index]);
		free(shell->words);
	}
	if (shell->input != NULL)
		free(shell->input);
	if (shell->command != NULL)
		free(shell->command);
	shell->words = NULL;
	shell->input = NULL;
	shell->command = NULL;
}

/**
 * free_and_close - frees all data fed to the shell
 * @shell: struct containing data fed to the shell
 *
 * Return: void
 */
void free_and_close(shell_data *shell)
{
	if (shell->fd != 0)
		close(shell->fd);
	free_specific_shell_data(shell);
	free_ptrs_arr(shell->env);
	free_ptrs_arr(shell->aliases);
}

