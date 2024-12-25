#include <stdio.h>
#include <stdlib.h>
/**
 * @environ: global variable ready to use
 */
extern char **environ;

/**
 * main - entry point of the program
 * Return: 0 (success)
 * Programme that prints the adress of environ
 */

int main(void)
{
	char **env;

	for (env = environ; *env; env++)
		printf("Variable : %s | Adress : %p\n ", *env, env);
	return (0);
}
