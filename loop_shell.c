#include "shell.h"

/**
 * loop_shell - function tha implements the looping of the shell
 * @shell_sign: displays the shell
 * @shell: struct containing data fed to the shell
 */
void loop_shell(char *shell_sign, shell_data *shell)
{
	int result = 0, len = 0;

	while (1)
	{
		print_string(shell_sign);
		code = get_line(shell);

		if (result == EOF)
		{
			free_and_close(shell);
			exit(errno);
		}
		if (len >= 1)
		{
			show_full_name_alias(shell);
			handle_variables(shell);
			get_words(shell);
			if (shell->words[0])
				result = execute_commands(shell);
				if (result != 0)
          _print_error(error_code, data);
      }
      free_recurrent_data(data);
    }
  }
}

