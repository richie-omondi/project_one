#include "shell.h"

/**
 * get_env_value - Gets the value of the environment variable
 * @env_variable: environment variable
 * @shell: struct containing data fed to the shell
 *
 * Return: value of the variable or NULL
 */
char *get_env_value(char *env_variable, shell_data *shell)
{
	int i;
	int variable_length;

	shell->env = environ;
	char **env = shell->env;

	if (env_variable == NULL || env == NULL)
		return (NULL);

	variable_length = str_len(env_variable);

	for (i = 0; env[i] != NULL; i++)
	{
		if (str_cmp(env_variable, env[i]) == 0)
		{
			while (env[i][variable_length] == ' ')
				variable_length++;
			return (env[i] + variable_length);
		}
	}
	return (NULL);
}

/**
 * set_env_variable - write a new environment variable and value or modify one
 * @shell: struct containing data fed to the shell
 * @env_variable: environment variable
 * @env_value: value of the variable
 *
 * Return: 0 on success or if there are no parameters
 * 7 if you have more than the required number of arguments
 */
int set_env_variable(char *env_variable, char *env_value, shell_data *shell)
{
	int i;
	int variable_length = 0
	bool is_new_variable = false;

	shell->env = environ;
	char **env = shell->env;
	char *new_variable;

	if (env_variable == NULL || env_value == NULL || env == NULL)
		return (0);
	if (shell->words[3] != NULL)
	{
		errno = E2BIG;
		perror(shell->command);
		return (7);
	}
	variable_length = str_len(env_variable);

	for (i = 0; env[i] != NULL; i++)
	{
		if (str_cmp(env_variable, env[i]) == 0)
		{
			while (env[i][variable_length] == ' ')
				variable_length++;
			is_new_varible = true;
			free(env[i]);
			break;
		}
	}
	new_variable = malloc(str_len(env_variable) + str_len(env_value) + 2);
	str_cpy(new_variable, env_variable);
	str_cat(new_variable, "=");
	str_cat(new_variable, env_value);

	if (is_new_variable)
		env[i] = new_variable;
	free(new_variable);
	return (0);
}

/**
 * unset_env_variable - remove the environment variable
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success or no variable
 * 7 if the number of arguments exceed what is required
 */
int unset_env_variable(shell_data *shell)
{
	int i;
	int variable_length = 0;

	shell->env = environ;
	char **env = shell->env;
	char *env_variable = shell->words[1];
	char *env_value = shell->words[2];

	if (env_variable == NULL)
		return (0);
	if (env_value != NULL)
	{
		errno = E2BIG;
		perror(shell->command);
		return (7);
	}
	variable_length = str_len(env_variable);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strcmp(env_variable, env[i]) == 0)
		{
			while (env[i][variable_length] == ' ')
				variable_length++;
			free(env[i]);
			for (int j = i; env[i]; j++)
				env[j - 1] = env[j];
			env[j - 1] = NULL;
			return (5);
		}
	}
	return (0);
}

/**
 * print_current_environment - prints the current environment
 * @shell: struct containing data fed to the shell
 *
 * Return: void
 */
void print_current_environment(shell_data *shell)
{
	int i;

	while (shell->env[i] != NULL)
	{
		print_string(shell->env[i]);
		print_string("\n");
	}
}

/**
 * _env - prints information about the current shell environment
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on sucess, 1 on malloc errors
 */
int _env(shell_data *shell)
{
	int i;
	char *copy_of_variable = NULL;
	char *save_copy_variable;

	if (shell->words[1] == NULL)
		print_current_environment(shell);
	else
	{
		for (i = 0; shell->words[1][i]; i++)
			if (shell->words[1][i] == '=')
			{
				copy_of_variable = malloc(str_len(shell->words[1]) + 1);
				copy_of_variable[i] = '\0';
				if (copy_of_variable == NULL)
				{
					perror("copy of variable malloc");
					return (1);
				}
				_strncpy(copy_of_variable, shell->words[1][i], i);
				get_env_value(copy_of_variable, shell);
				save_copy_variable = str_dup(copy_of_variable);
				if (save_copy_variable == NULL)
				{
					perror("save copy variable malloc");
					return (1);
				}
				if (save_copy_variable != NULL)
					set_env_variable(copy_of_variable, shell->words[1] + i + 1, shell);
				print_current_environment(shell);
				if (get_env_value(copy_of_variable, shell) == NULL)
				{
					print_string(shell->words[1]);
					print_string("\n");
				}
				else
				{
					set_env_variable(copy_of_variable, save_copy_variable, shell);
				}
				return (0);
			}
			copy_of_variable[i] = shell->words[1][i];
		}
		perror(shell->command);
		errno = 127;
	}
	free(copy_of_variable);
	free(save_copy_variable);
	return (0);
}
