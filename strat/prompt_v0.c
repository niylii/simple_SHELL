#include <stdio.h>
#include <stdlib.h>

/**
 * program that prints "$ ", wait for the user to enter a command, prints it on the next line. 
 */
int main()
{
	char *buff = NULL; /*where to store the line/command */
	size_t l = 0; /*size of buff*/
	ssize_t nread;

	printf("$");
	nread = getline(&buff, &l, stdin);
	if (nread != -1)
		printf("%s", buff);
	else
	{
		free (buff);
		printf("something went wrong with getline");
		return (1);
	}
	free(buff);
	return (0);
}
