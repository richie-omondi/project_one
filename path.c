#include "shell.h"

/**
 * check_exe - check if the file exists
 * @path: pointer to a string that has the path
 *
 * Return: 0 on success
 */
int check_exe(char *path)
{
	int code;

	code = access(path, F_OK);

	if (code != 0)
	{
		return (code);
	}

	code = access(path, R_OK);

	if (code != 0)
	{
		return (code);
	}

	code = access(path, X_OK);

	if (code != 0)
	{
		return (code);
	}

	return (0);
}

/**
 * separate_path - gets the individual paths in PATH
 * @shell: struct containing data fed to the shell
 *
 * Return: paths
 */
char **separate_path(shell_data *shell)
{
	char *path;
	char **paths = NULL;
	int num_paths = 0;
	char *token;
	int index;
	int j;

	path = get_env_value("PATH", shell);

	if (path == NULL)
		return (NULL);

	for (token = str_chr(path, ':'); token != NULL;
			token = str_chr(token + 1, ':'))
		num_paths++;

	paths = malloc(sizeof(char *) * num_paths);

	for (index = 0; index < num_paths; index++)
	{
		paths[index] = _strndup(path, str_chr(path, ':') - path);
		path = str_chr(path, ':') + 1;
	}

	if (paths[0][0] == '\0')
	{
		free(paths[0]);
		paths[0] = NULL;
	}
	for (j = num_paths - 1; j >= 0; j--)
	{
		if (paths[j][0] == '\0')
		{
			free(paths[j]);
			paths[j] = NULL;
		}
		else
			break;
	}
	return (paths);
}

/**
 * handle_path - find if a program exists in PATH
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success or an error code
 */

int handle_path(shell_data *shell)
{
	char **paths;
	int i;
	int code = 0;
	char *path;

	if (!shell->command)
		return (5);

	if (shell->command[0] == '/')
		return (check_exe(shell->command));

	path = malloc(str_len("/") + str_len(shell->command) + 1);

	if (!path)
		return (7);
	str_cpy(path, "/");
	str_cat(path, shell->command);

	paths = separate_path(shell);

	if (!paths)
		return (127);

	for (i = 0; paths[i]; i++)
	{
		code = check_exe(paths[i]);
		if (code == 0 || code == 126)
		{
			errno = 0;
			free(path);
			shell->words[0] = str_dup(paths[i]);
			free_ptrs_arr(paths);
			return (code);
		}
	}
	free(path);
	shell->words[0] = NULL;
	free_ptrs_arr(paths);
	return (code);
}
