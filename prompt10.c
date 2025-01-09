#include "main.h"

/**
 * simple_shell10 - function that shows the prompt and
 *	takes the command then execute it
 */

void simple_shell10(void)
{
	char *cmd = NULL, *args[1024];
	char *cmd_path, *pro_name;
	int exec_stat;
	size_t n = 0;
	ssize_t cmd_stat;
	pid_t pid;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		if (cmd)
			free(cmd);
		cmd = NULL;
		cmd_stat = get_line(&cmd, &n, STDIN_FILENO);
		getline_check(cmd_stat, cmd);
		cmd = str_cspn(cmd);
		pro_name = tokenize_pro_name(&cmd, args);
		exit_cmd_check(cmd, args);
		if (!cmd || cmd[0] == '\0')
			continue;
		if (is_space(cmd) == 0)
		{
			write(STDERR_FILENO, "Invalid command: only whitespaces\n", 34);
			continue;
		}
		if (str_cpm(pro_name, "setenv") == 0)
		{
			if (args[1] && args[2] && setenv_check(pro_name, args[1], args[2]) == -1)
				write(STDERR_FILENO, "Failed to set environment variable\n", 36);
			continue;
		}
		else if (str_cpm(pro_name, "unsetenv") == 0)
		{
			if (args[1] && unsetenv_check(pro_name, args[1]) == -1)
				write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
			continue;
		}
		if (env_cmd_check(cmd) == 0)
			continue;
		cmd_path = cmd_type(pro_name);
		if (cmd_path)
			exec_process(cmd_path, args, &exec_stat);
		else
			write(STDERR_FILENO, "Command not found\n", 18);
	}
	free(cmd);
}
