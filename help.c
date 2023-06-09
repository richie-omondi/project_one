#include "shell.h"

/**
 * _help - fuctions that prints messages to explain the built-ins
 * @shell: struct containing data fed to the shell
 *
 * Return: 0 on success
 */
int _help(shell_data *shell)
{
	char *string;

	if (shell->words[1] == NULL)
		string = "Hell In A Shell\nThese are the functions that have been built-in "\
			"so far.\nType 'help function' to find out more about the function.\n\n"\
			"alias   \talias [NAME[='VALUE'] ...]\n  cd    \t"\
			"cd  [DIRECTORY]\n  exit    \t"\
			"exit [STATUS]\n  env     \tenv\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  "\
			"[BUILTIN_NAME]\n\nDisplay information about builtin commands.\n\n"\
			"alias   \talias [NAME[='VALUE'] ...]\n  "\
			"cd    \tcd  [DIRECTORY]\n "\
			"exit    \texit [STATUS]\n "\
			"env     \tenv\n  "\
			"setenv  \tsetenv [VARIABLE] [VALUE]\n  "\
			"unsetenv\tunsetenv [VARIABLE]\n";
	else if (str_cmp(shell->words[1], "exit") == 0)
		string = "exit:\n\nexit [status]\n\nExit the shell.\n\n"\
			  "Arguments:\n\nstatus "\
			"- The exit status.\n\n";
	else if (str_cmp(shell->words[1], "env") == 0)
		string = "env:\n\nenv\n\nList all environment variables.\n\n";
	else if (str_cmp(shell->words[1], "setenv") == 0)
		string = "setenv:\n\nsetenv [variable value]\n\n"\
			 "Set the environment variable "\
			"variable` to the value `value`.\n\nArguments:\n\nvariable - "\
			"The name of the environment variable.\nvalue - "\
			"The value of the environment variable.\n\n";
	else if (str_cmp(shell->words[1], "unsetenv") == 0)
		string = "unsetenv:\n\nunsetenv [variable]\n\n"\
			  "Remove the environment variable "\
			"`variable`.\n\nArguments:\n\nvariable - "\
			"The name of the environment variable.\n\n";
	else if (str_cmp(shell->words[1], "cd") == 0)
		string = "cd:\n\ncd [dir]\n\nChange the current working directory."\
			  "\n\nArguments:\n\ndir - "\
			"The new working directory.\n\nIf no argument is given, "\
			"the command is interpreted as cd $HOME. If the argument '-' is given, "\
			"the command is interpreted as cd $OLDPWD.\n\n";
	else
	{
		errno = EINVAL;
		perror(shell->command);
		exit(errno);
	}

	print_string(string);
	return (0);
}
