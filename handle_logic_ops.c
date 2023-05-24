#include "shell.h"

/**
 * handle_logical_ops - handles the shell logical operators
 * @commands: array of commands passed as strings
 * @i: index
 *
 * Return: index
 */
int handle_logical_ops(char **commands, int i)
{
	for (int j = 0; commands[i] != NULL; j++)
	{
		if (commands[i][j] == '&' && commands[i][j + 1] == '&')
		{
			mem_cpy(&commands[i][j], &commands[i][j + 2],
					str_len(&commands[i][j + 2]) + 1);
			commands[i][str_len(&commands[i][j]) - 2] = '\0';
			i++;
		}
		if (commands[i][j] == '|' && commands[i][j + 1] == '|')
		{
			mem_cpy(&commands[i][j], &commands[i][j + 2],
					str_len(&commands[i][j + 2]) + 1);
			commands[i][str_len(&commands[i][j]) - 2] = '\0';
			i++;
		}
	}
	return (i);
}
