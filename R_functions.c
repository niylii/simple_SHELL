#include "main.h"

/**
 * e_of - Check for end-of-file (EOF) and handle cleanup.
 * @file: A pointer to a dynamically allocated string (file name or path).
 */
void e_of(char *file)
{
	if (feof(stdin))
	{
		free(file);
		write(STDOUT_FILENO, "", 1);
		exit(EXIT_SUCCESS);
	}
}

