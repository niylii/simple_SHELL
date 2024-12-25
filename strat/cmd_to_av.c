#include <stdio.h>
#include <string.h>

/**
 * split_it - function that splits a string
 * @str: the string to split
 * Return: the spleted string
 */

char *split_it(char *str)
{
	const char *tok = {" ,\"/?"};
	char *strr;

	strr = strtok(str, tok);
	return (strr);
}
