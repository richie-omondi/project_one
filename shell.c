#include "shell.h"

/**
 * handle_signal - prints a new prompt upon a signal
 * @signal: signal
 *
 * Return: void
 */
void handle_signal(int signal)
{
	char *prompt = "\n($) ";

	(void)signal;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, prompt, 20);
}

/**
 * main - Entry point for the program
 * @ac: argument count
 * @argv: array of argument strings
 * @envp: environment variables
 *
 * Return: 0 on success
 */
int main(int ac, char *argv[], char *envp[])
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_COMMAND_LENGTH];

	if (ac == 1)
	{
		implement_prompt(av, env);
	}
	while (1)
	{
		printf("shell> ");
		readCommand(command);
		parseCommand(command, arguments);
	}
}
