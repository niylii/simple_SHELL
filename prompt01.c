#include "main.h"
/**
 * @environ - 
 */

extern char **environ;
/**
 * prompt - function that shows the prompt and
 *	takes the command then execute it
 */

void simple_shell(void)
{
	char *cmd = NULL;
	int exec_stat;
	size_t n = 0;
	ssize_t cmd_stat;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		cmd_stat = getline(&cmd, &n, stdin);		
		if (cmd_stat == -1)
		{
			e_of(cmd);
			perror("no command is inserted");
		}
		cmd = str_cspn(cmd);
		pid = fork();
		if (pid == 0)
		{
			char *args[] = {cmd, NULL};
			if (execve(cmd, args, environ) == -1)
				perror("execution faild!");
			exit(1);
		}
		if (pid <= 0)
			perror("process not created");
		if (pid > 0)
			wait(&exec_stat);
		}
		free(cmd);
}
