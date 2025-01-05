#include "main.h"

/**
 * simple_shell011 - function that shows the prompt and
 *	takes the command then execute it (v0.1.1)
 */

void simple_shell011(void)
{
	char *cmd = NULL;
	int exec_stat;
	size_t n = 0;
	ssize_t cmd_stat;
	pid_t pid;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		cmd_stat = get_line(&cmd, &n, STDIN_FILENO);
		if (cmd_stat == -1)
		{
			e_of(cmd);
			perror("getline failed");
			continue;
		}
		cmd = str_cspn(cmd);
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			free(cmd);
			continue;
		}
		if (pid == 0)
		{
			char *arg[] = {cmd, NULL};
			if (execve(cmd, arg, environ) == -1)
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
