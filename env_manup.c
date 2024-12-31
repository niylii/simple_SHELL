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
	static char cmd_path[1024];

	path = getenv("PATH");
	if (str_find(pro, '/'))
		return ((access(pro, X_OK) == 0) ? pro : NULL);
	if (!path)
	{
		write(STDERR_FILENO, "PATH not found\n", 15);
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
	return (NULL);
}
