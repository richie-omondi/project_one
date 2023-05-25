#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/******* Structs **********/

/**
 * struct data - struct for data fed to the shell
 * @exe: executable file
 * @input: pointer to the input
 * @command: pointer to a command typed by the user
 * @counter: counts the number of executed commands
 * @fd: file descriptor
 * @words: tokenized input
 * @env: environ
 * @aliases: array of aliases.
 */
typedef struct data
{
	char *exe;
	char *input;
	char *command;
	char **words;
	char **env;
	char **aliases;
	int counter;
	int fd;
} shell_data;

/**
 * struct builtin_functions - struct containing components of a
 * built-in function
 * @f_name: built-in function name
 * @(*f)(shell_data *shell): function pointer
 */
typedef struct builtin_functions
{
	char *f_name;
	int (*f)(shell_data *shell);
} builtins_list;

/**
 * struct set_env_args - struct containing set_env_variable arguments
 * @shell: struct containing data fed to the shell
 * @env_variable: environment variable
 * @env_value: environment value
 */
struct set_env_args
{
	shell_data *shell;
	char *env_variable;
	char *env_value;
}

/****** Prototypes ********/
void add_data_to_shell(shell_data *shell, int argc, char *argv[], char **env);
int handle_logical_ops(char **commands, int i);
int get_line(shell_data  *shell);

/***** Execute functions *******/
int execute_commands(shell_data *shell);

/******** String functions *******/
char *str_dup(char *string);
int str_len(char *string);
char *_strncpy(char *destination, char *source, int n);
char *str_cpy(char *destination, char *source);
char *str_cat(char *destination, char *source);
int str_cmp(char *string_1, char *string_2);
int _strncmp(char *str1, char *str2, size_t n);
char *_strpbrk(char *str, char *accept);
char *_strndup(char *s, size_t n);
char *str_chr(char *str, char *c);

/***** Memory functions *******/
char *mem_cpy(char *destination, char *source, unsigned int n);
void *_calloc(unsigned int nmem, unsigned int size);

/****** Free functions ******/
void free_ptrs_arr(char **arr);
void free_specific_shell_data(shell_data *shell);
void free_and_close(shell_data *shell);

/****** Math/Number functions ********/
int _pow(int x, int y);
int is_digit(int i);

/******* Print functions ********/
int print_string(char *s);
void print_current_environment(shell_data *shell);

/****** Environment functions *********/
char *get_env_value(char *env_variable, shell_data *shell);
int set_env_variable(char *env_variable, char *env_value, shell_data *shell);
int unset_env_variable(shell_data *shell);
int _env(shell_data *shell);

/******* Alias functions *****/
char *alias(shell_data *shell, char *full_name);
void show_full_name_alias(shell_data *shell);
int show_alias(char *alias, shell_data *shell);
int add_alias(char *alias, shell_data *shell);
int alias_final(shell_data *shell);

/******* Tokenization functions *******/
int len_word(char *input, char *splitter);
char *str_tok(char *string, const char *splitter);
void get_words(shell_data *shell);

/****** Exit functions *******/
int exit_shell(shell_data *shell);

/**** Change Directory functions *******/
int directory(char *new_directory, shell_data *shell);
int _cd(shell_data *shell);

/***** Help functions *******/
int _help(shell_data *shell);

/**** Hanlde Built-in function ******/
int builtin_set_env_wrapper(void *args);
int handle_builtins(shell_data *shell);

/***** Path functions *******/
int check_exe(char *path);
char **separate_path(shell_data *shell);
int handle_path(shell_data *shell);

#endif
