#include "main.h"

/**
 * simple_shell10 - function that shows the prompt and
 *	takes the command then execute it
 */

void simple_shell10(void)
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
		cmd_stat = get_line(&cmd, &n, STDIN_FILENO);
		getline_check(cmd_stat, cmd);
		cmd = str_cspn(cmd);
		pro_name = tokenize_pro_name(&cmd, args);
		exit_cmd_check(cmd, args);
		if (env_cmd_check(cmd) == 0)
			continue;
		if (!cmd || cmd[0] == '\0')
			continue;
		cmd_path = cmd_type(pro_name);
		if (cmd_path)
			exec_process(cmd_path, args, &exec_stat);
		else
			write(STDERR_FILENO, "Command not found\n", 18);
	}
	free(cmd);
}
