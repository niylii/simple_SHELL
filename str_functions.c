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
	if (str[i] == '\n')
		str[i] = '\0';
	return (st);
}

/**
 * str_ncpm - function that compares two strings
 * @s1: pointer to the 1st string (environment variable)
 * @s2: pointer to the 2nd string (the one fron envi)
 * Return: 0 if there is a match -1 otherwise
 */

int str_ncpm(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] != '=')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '=')
		return (0);
	return (-1);
}

/**
 * str_find - function that looks for 'character'
 *		 then returns the string after it
 * @str: the string to look in
 * @dil: is a character
 * Return: the string after the 'character'
 */

char *str_find(char *str, char dil)
{
	int i = 0;

	while (str[i] && str[i] != dil)
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (&str[i + 1]);
}
