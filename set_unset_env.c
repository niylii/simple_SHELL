#include "main.h"

/**
 * setenv_check - a function that check if the cmd is setenv
 * @cmd: the command to check
 * @name: the name of the variable
 * @val: the value
 * Return: 0 (success), -1 (failure)
 */

int setenv_check(char *cmd, char *name, char *val)
{
	if (str_cpm("setenv", cmd) == 0)
		return (set_env((const char *)name, (const char *)val));
	return (-1);
}

/**
 * unsetenv_check - a function that check if the cmd is unsetenv
 * @cmd: the command to check
 * @name: the name of the variable
 * Return: 0 (success), -1 (failure)
 */

int unsetenv_check(char *cmd, char *name)
{
	if (str_cpm("unsetenv", cmd) == 0)
		return (unset_env((const char *)name));
	return (-1);
}

/**
 * set_env - function that mimics the setenv function
 * @name: the name of the variable
 * @val: the value to set to the variable
 * Return: 0 (success), -1 (failure)
 */

int set_env(const char *name, const char *val)
{
	char *new_var;
	size_t  i = 0;

	if (name == NULL || val == NULL)
	{
		perror("the name or the value is empty (or both)");
		return (-1);
	}
	new_var = malloc(str_len((char *)name) + str_len((char *)val) + 2);
	if (!new_var)
	{
		perror("New variable misallocated");
		return (-1);
	}
	sprintf(new_var, "%s=%s", name, val);
	if (env_exists(name) == 0)
	{
		while (environ[i])
		{
			if (str_ncpm((char *)name, environ[i]) == 0)
			{
				free(environ[i]);
				environ[i] = new_var;
				return (0);
			}
			i++;
		}
	}
	i = 0;
	while (environ[i])
		i++;
	environ[i] = new_var;
	environ[i + 1] = NULL;
	return (0);
}

/**
 * unset_env - function that mimics the unsetenv function
 * @name: the name of the variable
 * Return: 0 (success), -1 (failure)
 */

int unset_env(const char *name)
{
	long int i = 0, j = 0;

	if (!name || *name == '\0')
		return (-1);
	while (environ[i])
	{
		if (str_ncpm((char *)name, environ[i]) == 0)
		{
			free(environ[i]);
			for (j = i; environ[i]; j++)
				environ[j] = environ[j + 1];
			return (0);
		}
		i++;
	}
	return (-1);
}
