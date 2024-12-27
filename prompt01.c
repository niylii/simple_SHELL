#include "main.h"

/**
 * prompt - function that shows the prompt and
 *	takes the command then execute it
 */
void prompt(void)
{
	char *cmd_in = NULL;
	int cmd_stat, exec_stat;
	size_t n = 0;
	pid_t pid;

	write(1, "$ ", 2);
	cmd_stat = getline(&cmd_in, &n, stdin);
	while (cmd_stat == -1)
	{
		free(cmd_in);
		perror("no command is inserted");
		cmd_stat = getline(&cmd_in, &n, stdin);
	}
	if (cmd_stat != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			char *args[] = {cmd_in, NULL};

			if (execve(cmd_in, args, NULL) == -1)
				perror("execution faild!");
			exit(0);
		}
		if (pid <= 0)
			perror("process not created");
		if (pid > 0)
			wait(&exec_stat);
	}
}
