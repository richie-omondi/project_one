#include "shell.h"

/**
 * alias - handles aliases
 * @shell: struct containing data fed to the shell
 * @full_name: full name of the alias
 *
 * Return: value of the alias
 */
char *alias(shell_data *shell, char *full_name)
{
	int len;
	int index;

	if (full_name == NULL || shell->aliases == NULL)
		return (NULL);

	len = str_len(full_name);

	for (index = 0; shell->aliases[index]; index++)
	{
		if (_strncmp(full_name, shell->aliases[index], len) == 0 &&
				shell->aliases[index][len] == '=')
		{
			char *str = malloc(str_len(shell->aliases[index]) - len + 1);

			if (str == NULL)
				return (NULL);
			mem_cpy(str, shell->aliases[index] + len + 1,
					str_len(shell->aliases[index]) - len);
			str[str_len(shell->aliases[index]) - len - 1] = '\0';
			return (str);
		}
	}
	free(str);
	return (NULL);
}

/**
 * show_full_name_alias - shows the full name of the alias
 * @shell: struct containing data fed to the shell
 *
 * Return: void
 */
void show_full_name_alias(shell_data *shell)
{
	int index;
	int j;
	bool is_full_name = false;
	char *buffer = shell->input;
	char *full_name = NULL;

	if (buffer == NULL)
		return;

	for (index = 0; *(buffer + index); index++)
	{
		if (*(buffer + index) == '$')
		{
			full_name = malloc(BUFFER_SIZE);
			if (full_name == NULL)
				return;
			for (j = 1; *(buffer + index + j) && *(buffer + index + j) != ' ' &&
					*(buffer + index + j) != ')' &&
					*(buffer + index + j) != '\n' && *(buffer + index + j) != '\t' &&
					*(buffer + index + j) != '\r' && *(buffer + index + j) != '\0'; j++)
				*(full_name + j - 1) = *(buffer + index + j);
			*(full_name + j - 1) = '\0';

			char *temporary_string = alias(shell, full_name);

			if (temporary_string != NULL)
			{
				for (int k = index; k < index + j; k++)
					*(buffer + k) = '\0'
			}
			str_cat(buffer, temp_string);
			is_full_name = true;
		}
	}
	if (is_full_name)
		free(full_name);
}

/**
 * show_alias - prints aliases
 * @shell: struct containing data fed to the shell
 * @alias: pointer to a string
 *
 * Return: 0 on success
 */
int show_alias(char *alias, shell_data *shell)
{
	if (shell->aliases == NULL)
		return (0);

	for (char **alias_entry = shell->aliases; *alias_entry != NULL; alias_entry++)
	{
		char *name = *alias_entry;
		char *value = *alias_entry + str_len(*alias_entry) + 1;

		if (alias == NULL || str_cmp(*alias_entry, alias) == 0)
		{
			write(1, *alias_entry, str_len(*alias_entry));
			write(1, " = ", 3);
			write(1, *alias_entry + str_len(*alias_entry) + 1,
					str_len(*alias_entry) + 1);
			write(1, "\n", 1);
		}
	}
	return (0);
}

/**
 * add_alias - add and change aliases
 * @alias: alias to be add or changed
 * @shell: struct containing the data fed to the shell
 *
 * Return: 0 on success
 */
int add_alias(char *alias, shell_data *shell)
{
	int index;
	int j;
	char *buffer = NULL;
	char *value = NULL;

	if (alias == NULL || shell->aliases == NULL)
		return (1);
	for (index = 0; *(alias + index); index++)
	{
		if (*(alias + index) == '=')
		{
			value = alias + index + 1;
			break;
		}
		*(buffer + index) = *(alias + index);
	}
	for (j = 0; shell->aliases[j]; j++)
	{
		if (str_cmp(buffer, shell->aliases[j]) == 0)
		{
			free(shell->aliases[j]);
			break;
		}
	}
	if (value)
	{
		shell->aliases[j] = malloc(str_len(buffer) + str_len(value) + 2);
		_strncpy(shell->aliases[j], buffer, str_len(buffer));
		shell->aliases[j][str_len(buffer)] = '=';
		_strncpy(shell->aliases[j] + str_len(buffer) + 1, value, str_len(value));
	}
	else
		shell->aliases[j] = malloc(str_len(alias) + 1);
		_strncpy(shell->aliases[j], alias, str_len(alias));

	free(shell->aliases[j];
	return (0);
}

/**
 * alias_final - combines all other alias functions in this file into one
 * providing full alias functionality
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int alias_final(shell_data *shell)
{
	int index = 0;
	char *result;

	if (shell->words[1] == NULL)
		return (show_alias(NULL, shell));
	result = str_chr(shell->words[index], shell);

	if (result != NULL)
		add_alias(shell->words[index], shell);
	else
		show_alias(show->words[index], shell);

	return (0);
}
