#include "shell.h"

/**
 * len_word - calculates the length of a word in a string
 * @input: string to be calculated.
 * @splitter: delimiter
 *
 * Return: length of the word
 */
int len_word(char *input, char *splitter)
{
	int length = 0;
	int i;

	for (i = 0; input[i] != '\0' && input[i] != *splitter; i++)
		length++;
	return (length);
}

/**
 * str_tok - tokenizes strings
 * @string: string to be split
 * @splitter: delimiter
 *
 * Return: start of the token
 */
char *str_tok(char *string, const char *splitter)
{
	static char *current_position;

	if (string != NULL)
		current_position = string;
	if (current_position == NULL)
		return (NULL);
	char *start = current_position;
	char *ptr = _strpbrk(current_position, splitter);

	if (ptr != NULL)
	{
		*ptr = '\0';
		current_position = ptr + 1;
	}
	else
		current_position = NULL;
	return (start);

}

/**
 * get_words - separates the string according to a space or tab
 * @shell: pointer to a struct containing data fed to the shell
 *
 * Return: tokenized strings
 */
void get_words(shell_data *shell)
{
	int index = 0;
	int len = 0;
	int words = 2;
	char *splitter = " \t";

	for (index = 0; *(shell->input + index); index++)
		len++;
	if (len)
	{
		if (*(shell->input + len - 1) == '\n')
			*(shell->input + len - 1) = '\0';
	}

	for (index = 0; index < len; index++)
	{
		if (*(shell->input + index) != splitter)
		{
			words++;
			index += len_word(shell->input, splitter);
		}
		return (words)
	}

	shell->words = malloc(words * sizeof(char *));
	if (shell->words == NULL)
	{
		perror(shell->exe);
		exit(errno);
	}
	for (index = 0; index < len; index++)
	{
		if (str_chr(*(shell->input + index, splitter)) != NULL)
		{
			shell->words[words++] = _strndup(shell->input + index,
					str_chr(shell->input + index, splitter) - shell->input - index);
			index = str_chr(shell->input + index, splitter) - shell->input;
		}
	}
	shell->command = shell->words[0];
	free_ptrs_arr(shell->words);
}
