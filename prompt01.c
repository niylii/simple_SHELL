#include "main.h"

/**
 * simple_shell - function that shows the prompt and
 *	takes the command then execute it (v0.1)
 */

void simple_shell(void)
{
	char *cmd = NULL;
	char *argsp[];
	int exec_stat;
	size_t n = 0;
	ssize_t cmd_stat;
	pid_t pid;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		cmd_stat = getline(&cmd, &n, stdin);
		if (cmd_stat == -1)
		{
			e_of(cmd);
			perror("getline failed");
		}
		cmd = str_cspn(cmd);
		pid = fork();
		if (pid < 0)
			perror("fork failed");
		if (pid == 0)
		{
			args[] = {cmd, NULL};
			if (execve(cmd, args, environ) == -1)
			{
				perror("execution faild!");
				exit(EXIT_FAILURE);
			}
		}
		if (pid > 0)
			waitpid(pid, &exec_stat, 0);
	}
	free(cmd);
}
