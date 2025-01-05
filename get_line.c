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

/**
 * get_line - a function that mimics the getline function's behaviour
 * @line: a buffer where the line is stored
 * @size: the size of 
 * @stm: the file stream
 * Return: returns number of characters read (success)
 *		-1 (failure)
 */

ssize_t get_line(char **line, size_t *n, int fd)
{
	static char buff[1024];
	static ssize_t bytes = 0, pose = 0; 
	ssize_t len = 0;
	char *line_;

	*line = line_;
	if (*n == 0 || line_ == NULL)
	{
		*n = 1024;
		line_ = malloc(*n);
		if (line_ == NULL)
			return (-1);
		*line = line_;
	}
	while (1)
	{
		if (pose >= bytes)
		{
			bytes = read(fd, buff, 1024);
			if (bytes == -1)
			{
				if (len == 0)
					return (-1);
				break;
			}
			pose = 0;
		}
		if (len + 1 >= *n)
		{
			*n *= 2;
			line_ = realloc(line_, *n);
			if (!line_)
				return (-1);
			*line = line_;
		}
		line_[len++] = buff[pose++];
		if (line_[len - 1] == '\n')
		{
			line_[len] = '\0';
			return (len);
		}
	}
	line_[len] = '\0';
	return (len);
}
