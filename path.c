int check_file(char *full_path)
{
  int ret;

  /* Check if the file exists. */
  ret = access(full_path, F_OK);
  if (ret != 0) {
    return ret;
  }

  /* Check if the file is a directory. */
  ret = access(full_path, R_OK);
  if (ret != 0) {
    return ret;
  }

  /* Check if the file has execute permissions. */
  ret = access(full_path, X_OK);
  if (ret != 0) {
    return ret;
  }

  /* The file exists, is not a directory, and has execute permissions. */
  return 0;
}

