#include "monty.h"

/**
 * find_words - finds the number of words in a str
 * @str: string which is to be searched
 *
 * Return: the number of words in the string
 */
int find_words(char *str)
{
	short onoff = 0;
	int words = 0, i;

	for (i = 0; str[i]; i++)	/* go through the string once */
	{
		if (str[i] == ' ')
			onoff = 0;	/* set to 0 for every ' ' char */
		else if (onoff == 0)
		{
			onoff = 1;	/* set to 1 at start of word stops incrementing */
			words++;	/* increment word for first non ' ' char */
		}
	}
	return (words);
}

/**
 * _strlen - finds the length of the string
 * @s: string whose length is to be found
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * strtow - converts a string to an array of words which is NULL terminated
 * @str: string which is to be converted
 *
 * Return: the array generated
 */
char **strtow(char *str)
{
	int i, start, end, len, words, letters = 0, j = 0;
	char **array, *tmp;

	words = find_words(str);	/* find the words in string */
	len = _strlen(str);	/* find the length of string */
	if (words == 0)  /* malloc for the size of the array i.e no of words */
		return (NULL);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_list(bag.stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= len; i++)
	{
		if ((str[i] == ' ' || str[i] == '\0'))
		{
			if (letters == 0)
				continue;
			end = i;	/* set end to the 1st ' ' after end of word */
			tmp = malloc((letters + 1) * sizeof(char));
			if (tmp == NULL)
			{
				free(tmp);
				return (NULL);
			}
			while (start < end)	/* fill chars from 1st to last char */
				*tmp++ = str[start++];	/* tmp holds all chars */
			*tmp = '\0';	/* set last char of word to null byte */
			/* assign next element to the address of new word */
			array[j] = tmp - letters;
			j++;	/* increment j for next element of array */
			letters = 0;	/* set the letter count to 0 */
		}
		else if (letters++ == 0)
			start = i;	/* set start for fill at 1st non ' ' char */
	}
	array[j] = NULL;
	return (array);
}
