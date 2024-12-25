#include <stdio.h>
#include <stdlib.h>
/**
 * @environ: global variable ready to use
 */
extern char **environ;

/**
 * main - entry point of the program
 * @ac: number of arguments
 * @av: the arguments
 * @ev: the enviremnt variables
 * Return: 0 (success)
 * Programme that prints the adress of environ and envp
 */

int main(int ac, char **av, char **ev)
{
	char **ev_global, **ev_local;

	ev_global = environ;
	ev_local = ev;
	while (ev_global || ev_local)
	{
		printf("whith global ev: %s | Adress : %p\n ", *ev_global, ev_global);
		printf("whith local ev: %s | Adress : %p\n ", *ev_local, ev_local);
		ev_global++;
		ev_local++;
	}
	return (0);
}
