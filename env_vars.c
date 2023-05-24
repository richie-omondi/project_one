#include "shell.h"

/**
 * handle_variables - shows the path for an environment variable
 * @shell: struct containing data fed to the shell
 *
 * Return: void
 */
void handle_variables(shell_data *shell)
{
	int i;
	int j;
	char *buffer = shell->input;
	char *path = malloc(BUFFER_SIZE);

	if (buffer == NULL)
		return;
	for (i = 0; *(buffer + i); i++)
	{
		if (*(buffer + i) == '#')
			(*buffer)-- = '\0';
		else if (*(buffer + i) == '$' && *(buffer + i + 1) == '?')
		{
			*(buffer + i) = '\0';
			for (j = 0; j < 10; j++)
				*(path + j) = '\0';
			*(path + 0) = '$';
			*(path + 1) = '?';
			for (j = 2; j < 10; j++)
				*(path + j) = (char)('0' + (errno / _pow(10, j - 2)));
			*(path + 10) = '\0';
			str_cat(buffer, path);
			str_cat(buffer, shell->input + i + 2);
		}
		else if (*(buffer + i) == '$' && *(buffer + i + 1) == '$')
		{
			*(buffer + i) = '\0';
			for (j = 0; j < 10; j++)
				*(path + j) = '\0';
			*(path + 0) = '$';
			*(path + 1) = '$';
			for (j = 2; j < 10; j++)
				*(path + j) = (char)('0' + (getpid() / _pow(10, j - 2)));
			*(path + 10) = '\0';
			str_cat(buffer, path);
			str_cat(buffer, shell->input + i + 2);
		}
		else if (*(buffer + i) == '$' && *(buffer + i + 1) == ' ' || *(buffer + i + 1) == '\0')
			continue;
		else if (*(buffer + i) == '$')
		{
			for (j = 1; *(buffer + i + j) && *(buffer + i + j) != ' '; j++)
				*(path + j - 1) = *(buffer + i + j);
			char *temp_string = get_env_value(path, shell);

			*(buffer + i) = '\0';
			if (temp_string != NULL)
				str_cat(buffer, temp_string);
			else
				str_cat(buffer, "");
			str_cat(buffer, path);
		}
	}
	if (str_cmp(shell->input, buffer) != 0)
	{
		free(shell->input);
		shell->input = buffer;
	}
	free(path);
}
