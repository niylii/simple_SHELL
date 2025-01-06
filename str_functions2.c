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

char *str_pbrk(char *str,const char *dil)
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
