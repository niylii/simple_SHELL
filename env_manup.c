#include "main.h"

/**
 * get_env - simple version of getenv systemcall
 * @name: pointer to the name of variable
 * Return: the value of the environment variable name
 *	NULL if it does not exist
 */

char *get_env(const char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (str_ncpm((char *)name, environ[i]) == 0)
			return (str_find(environ[i], '='));
		i++;
	}
	return (NULL);
}


/**
 * env_exists - function that checks if the argument exists
 * @name: pointer to the name of variable
 * Return: 0 if it exists -1 otherwise
 */

int env_exists(const char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (str_ncpm((char *)name, environ[i]) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * cmd_type - is a fucntion that handle the command based on it's type
 *		(built in or external program)
 * @pro: is the program name
 * Return: the command / path
 */
char *cmd_type(char *pro)
{
	char *path;
	char *current;
	static char *cmd_path;

	cmd_path = malloc(1024);
	if (!cmd_path)
		return (NULL);
	path = strdup(get_env("PATH"));
	if (str_find(pro, '/'))
		return ((access(pro, X_OK) == 0) ? strdup(pro) : NULL);
	if (!path)
	{
		write(STDERR_FILENO, "PATH is empty\n", 14);
		return (NULL);
	}
	current = strtok(path, ":");
	while (current)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", current, pro);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		current = strtok(NULL, ":");
	}
	free(path);
	free(cmd_path);
	return (NULL);
}

int env_cmd_check(char *cmd)
{
	char **env = environ;
	size_t len;

	if (str_cpm("env", cmd) == 0)
	{
		while (*env)
		{
			len = str_len(*env);
			write(STDOUT_FILENO, *env, len);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return (0);
	}
	return (-1);
}
