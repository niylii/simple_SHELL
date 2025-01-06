#include "main.h"

/**
 * simple_shell021 - function that shows the prompt and
 *	takes the command then execute it
 */

void simple_shell021(void)
{
	char *cmd = NULL, *args[10], *pro_name;
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
		pro_name = tokenize_pro_name(&cmd, args);
		pid = fork();
		if (pid < 0)
			perror("fork failed");
		if (pid == 0)
		{
			if (execve(pro_name, args, environ) == -1)
			{
				perror("execution failed");
				exit(EXIT_FAILURE);
			}
		}
		if (pid > 0)
			waitpid(pid, &exec_stat, 0);
	}
	free(cmd);
}
