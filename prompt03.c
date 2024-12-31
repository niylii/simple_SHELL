#include "main.h"

/**
 * simple_shell03 - function that shows the prompt and
 *	takes the command then execute it
 */

void simple_shell03(void)
{
	char *cmd = NULL, *args[10];
	char *cmd_path, *pro_name;
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
			break;
		}
		cmd = str_cspn(cmd);
		if (!cmd || cmd[0] == '\0')
			continue;
		pro_name = tokenize_pro_name(&cmd, args);
		cmd_path = cmd_type(pro_name);
		if (cmd_path)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fork failed");
				continue;
			}
			if (pid == 0)
			{
				if (execve(cmd_path, args, environ) == -1)
				{
					perror("execution failed");
					free(cmd);
					exit(EXIT_FAILURE);
				}
			}
			if (pid > 0)
				waitpid(pid, &exec_stat, 0);
		}
		else
			write(STDERR_FILENO, "Command not found\n", 18);

	}
	free(cmd);
}
