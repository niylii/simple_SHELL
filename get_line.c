#include "main.h"

/**
 * getline_check - a function that handles the failure of getline
 *		function.
 * @stat: the return value fron the getline function
 * @cmd: the command
 */

void getline_check(ssize_t stat, char *cmd)
{
	if (stat == -1)
	{
		e_of(cmd);
		perror("getline failed");
	}
}
