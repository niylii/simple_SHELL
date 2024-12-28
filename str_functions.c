#include "main.h"

/**
 * str_len - Function to compute the length of a string.
 * @str: A pointer to the string whose length is to be calculated.
 * Return: The length of the string
 */
int str_len(char *str)
{
	long int len = 0;

	while (str)
		len++;
	return (len);
}

/**
 * str_cspn - Function to find the first newline character
 *            and terminate the string at that point.
 * @str: A pointer to the string to be modified.
 * Return: A pointer to the modified string.
 */
char *str_cspn(char *str)
{
	int i = 0;
	char *st;

	st = str;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (st);
}
