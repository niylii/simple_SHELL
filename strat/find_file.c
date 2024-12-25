#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - entry point of the programme
 * @av: the arguments
 * @ac: the number of arguments
 * Return: 0 (success)
 */

int main(int ac, char **av)
{
	unsigned int i = 1;
	struct stat st;

	if (ac < 2)
	{
		printf("usage wrong\n");
		return (0);
	}
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
			printf("%s : FOUND\n", av[i]);
		else
			printf("%s : NOT FOUND\n", av[i]);
		i++;
	}
	return (0);
}
