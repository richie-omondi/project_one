#include "shell.h"

/**
 * builtin_set_env_wrapper - function that handles the variable arguments
 * of set_env_variable
 * @args: void pointer to arguments
 *
 * Return: nothing
 */
int builtin_set_env_wrapper(void *args)
{
	struct set_env_args *s = args;

	return (set_env_variable(s->shell, s->env_variable, s->env_value));
}

/**
 * handle_builtins - implement the built-in functions
 * @shell: struct containing data fed to the shell
 *
 * Return: On success, value of the function
 * -1 on failure
 */
int handle_builtins(shell_data *shell)
{
	const struct builtins_list functions[] = {
		{ "exit", &exit_shell },
		{ "help", &_help },
		{ "cd", &_cd },
		{ "alias", &alias_final },
		{ "env", &_env },
		{ "setenv", &set_env_variable },
		{ "unsetenv", &unset_env_variable },
	};
	const size_t num_functions = sizeof(functions) / sizeof(functions[0]);

	for (size_t index = 0; i < num_functions; ++index)
	{
		if (str_cmp(functions[index].f_name, shell->command) == 0)
		{
			if (functions[i].f == &set_env_variable)
			{
				struct set_env_args args = { shell, shell->args[1], shell->args[2] };

				return (functions[index].f(&args));
			}
			else
				return (functions[index].f(shell));
		}
	}
	return (-1);
}