#include "main.h"

/**
 * e_of - Check for end-of-file (EOF) and handle cleanup.
 * @file: A pointer to a dynamically
 *	allocated string (file name or path).
 */
void e_of(char *file)
{
	if (feof(stdin))
	{
		free(file);
		write(STDOUT_FILENO, "\0", 1);
		exit(EXIT_SUCCESS);
	}
	free(file);
}

/**
 * tokenize_pro_name - function that breaking down a command
 *		line input into cmd and args
 * @str: double pointer to the command line
 * @args: the path
 * Return: the broke down cmd line
 */
char *tokenize_pro_name(char **str, char **args)
{
	char *token, *buff;
	int i = 0;

	token = str_tok(*str, " ");
	while (token)
	{
		args[i++] = token;
		token = str_tok(NULL, " ");
	}
	args[i] = NULL;
	return (args[0]);
}

/**
 * exec_process - function that handle the execution process
 * @cmd_path: the command path
 * @args: arguments with the command
 * @cmd: original command
 * @exec_stat: the execcution status
 * @pid: the process id
 */

void exec_process(char *cmd_path, char **args, int exec_stat,
		char *cmd, pid_t pid)
{
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
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

/**
 * exit_cmd_check - is a function that checks if the command is
 *		the "exit" command
 * @cmd : the command to check
 */
void exit_cmd_check(char *cmd)
{
	int ex_it;

	if (cmd == NULL)
		return;
	ex_it = str_cpm(cmd, "exit");
	if (ex_it == 0)
	{
		free(cmd);
		exit(0);
	}
}
