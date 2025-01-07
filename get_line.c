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
 * read_into - Reads data from the file descriptor into the buffer.
 * @fd: File descriptor to read from.
 * @buff: Static buffer to store read data.
 * @bytes: Pointer to the number of bytes read.
 * @pose: Pointer to the current position in the buffer.
 * Return: Number of bytes read, or -1 on failure.
 */

static ssize_t read_into(int fd, char *buff, ssize_t *bytes, ssize_t *pose)
{
		*bytes = read(fd, buff, 1024);
		if (*bytes == -1)
			return (-1);
		*pose = 0;
		return (*bytes);
}

/**
 * get_line - a function that mimics the getline function
 * @line: a buffer where the line is stored
 * @n: the size
 * @fd: the file stream
 * Return: returns number of read chars(success), -1 (f)
 */
ssize_t get_line(char **line, size_t *n, int fd)
{
	static char buff[1024];
	static ssize_t bytes = 0, pose = 0;
	ssize_t len = 0;
	char *line_ = NULL;

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
			if (read_into(fd, buff, &bytes, &pose) == -1)
				return ((len == 0) ? -1 : len);
		}
		if (len + 1 >= *n)
		{
			*n *= 2;
			line_ = realloc(*line, *n);
			if (!line_)
			{
				free(*line);
				return (-1);
			}
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
