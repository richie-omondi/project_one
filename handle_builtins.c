#include "shell.h"

/**
 * handle_builtins - implement the built-in functions
 * @shell: struct containing data fed to the shell
 *
 * Return: On success, value of the function
 * -1 on failure
 */
int handle_builtins(shell_data *shell)
{
	size_t index;

	builtins_list functions[] = {
		{ "exit", &exit_shell },
		{ "help", &_help },
		{ "cd", &_cd },
		{ "alias", &alias_final },
		{ "env", &_env },
		{ "unsetenv", &unset_env_variable },
		{ NULL, NULL}
	};
	const size_t num_functions = sizeof(functions) / sizeof(functions[0]);

	for (index = 0; index < num_functions; ++index)
	{
		if (str_cmp(functions[index].f_name, shell->command) == 0)
				return (functions[index].f(shell));
	}
	return (-1);
}
