#include "main.h"

/**
 * str_tok - a function that mimics the strtok function
 *		(nearly)
 * @str: the string
 * @dil: the delimiter
 * Return: the splited string
 */

char *str_tok(char *str, const char *dil)
{
	static char *ptr;
	char *token;

	if (str != NULL)
		ptr = str;
	if (ptr == NULL || *ptr == '\0')
		return (NULL);
	while (*ptr && (str_pbrk(ptr, dil) == ptr))
		ptr++;
	if (*ptr == '\0')
	{
		ptr = NULL;
		return (NULL);
	}
	token = ptr;
	ptr = str_pbrk(ptr, dil);
	if (ptr)
	{
		*ptr = '\0';
		ptr++;
	}
	else
		ptr = NULL;
	return (token);
}


/**
 * str_pbrk - a function that mimics the strpbrk function
 *		(nearly)
 * @str: the string
 * @dil: the bytes
 * Return: the bytes that matches the dil
 *		NULL if it nothing is found
 */

char *str_pbrk(char *str, const char *dil)
{
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; dil[j] != '\0'; j++)
		{
			if (dil[j] == str[i])
				return (str + i);
		}
	}
	return (NULL);
}

/**
 * a_to_i - function that transforms a character to an integer
 * @str: the number as characters
 * Return: the number as integer
 */

int a_to_i(char *str)
{
	int i = 0, nb = 0, sng = 1;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sng = -1;
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sng);
}

/**
 * is_space - function that tells if the argument is space
 * @str: the argument to check
 * Return: 0(success), -1(failure)
 */
int is_space(const char *str)
{
	int len, i;

	if (!str || *str == '\0')
		return (-1);
	len = str_len((char *)str);
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
			str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		return (-1);
	}
	return (0);
}
