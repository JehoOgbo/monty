#include "monty.h"

/**
 * free_array - frees an array of array
 * @array: array to be freed
 *
 * Return: void
 */
void free_array(char **array)
{
	int i = 0;


	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
