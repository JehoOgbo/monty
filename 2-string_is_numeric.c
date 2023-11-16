#include "monty.h"

/**
 * is_numeric - checks if a string is made up only digits
 * @s: string to be checked
 *
 * Return: 0 if string is numeric and 1 otherwise
 */
int is_numeric(char *s)
{
	int len, i = 1;

	len = strlen(s);
	if ((s[0] > '9' || s[0] < '0') && s[0] != '-')
		return (1);
	while (i < len)
	{
		if (s[i] > '9' || s[i] < '0')
			return (1);
		i++;
	}
	return (0);
}
