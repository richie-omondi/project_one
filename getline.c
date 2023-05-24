#include "shell.h"

/**
 * get_line - reads lines one at a time from the input
 * @shell: data from the shell
 *
 * Return: length of the input
 */

int get_line(shell_data *shell)
{
	char buffer[BUFFER_SIZE] = {'\0'};
	static char **commands = NULL;
	static char **operators = NULL;
	ssize_t bytes;
	int i = 0;

	if (!commands)
	{
		bytes = read(shell->fd, &buffer, BUFFER_SIZE - 1);
		if (bytes == 0)
			return (-1);
		commands = malloc(sizeof(char *) * (bytes + 1));
		if (!commands)
			return (-1);
		operators = malloc(sizeof(char *) * (bytes + 1));
		if (!operators)
			return (-1);
		for (i = 0; i < bytes; i++)
		{
			if (buffer[i] == '\n' || buffer[i] == ';')
				break;
		}
		commands = malloc(i + 1);
		if (!commands)
			return (-1);
		_strncpy(commands, buffer, i);
		commands[i][i] = '\0';
		i++;
		while (i < bytes)
		{
			if (buffer[i] == '&' || buffer[i] == '|')
				operators[i - 1] = buffer[i];
			else
			{
				commands[i] = malloc(bytes - i + 1);
				if (!commands)
					return (-1);
				_strncpy(commands, buffer + i, bytes - i);
				commands[i][bytes - i] = '\0';
				break;
			}
			i++;
		}
	}
	shell->input = commands[0];
	for (i = 0; commands[i]; i++)
	{
		commands[i] = commands[i + 1];
		operators[i] = operators[i + 1];
	}
	free(commands);
	free(operators);
	close(bytes);
	
	return (str_len(shell->input));
}
