/**
 * print_string - prints a string to stdout
 * @s: pointer to a string
 * Return: number of bytes written
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_string(char *s)
{
	return (write(STDOUT_FILENO, str, str_len(s)));
}

int print_error(int errorcode, data_of_program *data) {
  char n_as_string[10];
  int len = 0;

  while (*n_as_string) {
    len++;
    n_as_string++;
  }

  if (errorcode == 2 || errorcode == 3) {
    char *ptr = data->program_name;
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, ": ", 1);
    for (int i = 0; i < len; i++) {
      write(STDERR_FILENO, n_as_string + i, 1);
    }
    write(STDERR_FILENO, ": ", 1);
    ptr = data->tokens[0];
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    if (errorcode == 2) {
      write(STDERR_FILENO, ": Illegal number: ", 14);
    } else {
      write(STDERR_FILENO, ": can't cd to ", 12);
    }
    ptr = data->tokens[1];
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, "\n", 1);
  } else if (errorcode == 127) {
    char *ptr = data->program_name;
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, ": ", 1);
    for (int i = 0; i < len; i++) {
      write(STDERR_FILENO, n_as_string + i, 1);
    }
    write(STDERR_FILENO, ": ", 1);
    ptr = data->command_name;
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, ": not found\n", 12);
  } else if (errorcode == 126) {
    char *ptr = data->program_name;
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, ": ", 1);
    for (int i = 0; i < len; i++) {
      write(STDERR_FILENO, n_as_string + i, 1);
    }
    write(STDERR_FILENO, ": ", 1);
    ptr = data->command_name;
    while (*ptr) {
      write(STDERR_FILENO, ptr, 1);
      ptr++;
    }
    write(STDERR_FILENO, ": Permission denied\n", 19);
  }
  return 0;
}

