#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - entry point of the program
 * Return: 0 (success)
 * program that executes the command ls -l /tmp in 5 different child processes.
 */

int main(void)
{
	pid_t pid;
	int ex_stat, process = 1, exe;
	const char *path = "/bin/ls";
	char * const av[] = {"ls", "-l", NULL};

	while (process <= 5)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("hi, i'm chiled n %d: %d\n", process, pid);
			if (execve(path, av, NULL) == -1)
				printf("not working >o<\n");
			exit(0);
		}
		if (pid == -1)
		{
			printf("mama i n: %d faild\n", process);
			exit(88);
		}
		if (pid > 0)
			wait(&ex_stat);
		process++;
	}
	return (0);
}
