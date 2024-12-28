#include "main.h"

void e_of(char *file)
{
	if (feof(stdin))
	{
		free(file);
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}
