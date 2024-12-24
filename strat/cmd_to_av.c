#include <stdio.h>
#include <string.h>

/**
 *  function that splits a string and returns an array of each word of the string.
 */

char *split_it(char *str)
{
	const char *tok = {" ,\"/?"};
	char *strr;

	strr = strtok(str, tok);
	return (strr);
}
