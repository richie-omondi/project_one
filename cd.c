#include "shell.h"

/**
 * directory - set the working directory
 * @shell: struct containing data fed to the shell
 * @new_directory: path to be set as new working directory
 *
 * Return: 0 on success,5 on error
 */
int directory(char *new_directory, shell_data *shell)
{
	char *previous_directory = NULL;
	int result = 0;
	char *pwd_value;

	if (shell == NULL || new_directory == NULL)
		return(1);

	if (getcwd(previous_directory, 128) == NULL)
		return (4);
	getcwd(previous_directory, 128);
	if (!str_cmp(previous_directory, new_directory))
	{
		result = chdir(new_directory);
		if (result == -1)
			return (2);
		pwd_value = get_env_value("PWD", shell);
		if (pwd_value != NULL)
			set_env_variable("PWD", pwd_value, shell);
	}
	set_env_variable("OLDPWD", previous_directory, shell);
	return (0);
}

/**
 * _cd - function that changes directory
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int _cd(shell_data *shell)
{
	char *home = get_env_value("HOME", shell);
	char *previous_directory = get_env_value("OLDPWD", shell);
	int result;
	char *_home = NULL;

	if (shell->words[1])
	{
		if (str_cmp(shell->words[1], "-") == 0)
		{
			if (previous_directory)
				result = directory(previous_directory, shell);
			print_string(get_env_value("PWD", shell));
			print_string("\n");
			return (result);
		}
		else
			return (directory(shell->words[1], shell));
	}
	else
	{
		if (!home)
			home = getcwd(_home, 128);
		return (directory(home, shell));
	}
	return (0);
}
