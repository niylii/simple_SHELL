#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * path_ - function that takes a path and then prints each directory per line
 */
void path_(void)
{
	char *path, *current, *next;

	path = getenv("PATH");
	if (path != NULL)
	{
		current = path;
		while (*current)
		{
			next = current;
			while (*next && *next != ':')
				putchar(*next++);
			putchar('\n');
			current = (*next) ? next + 1 : next;
		}
	}
	else
	printf("PATH env not found.\n");
}
