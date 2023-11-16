#include "monty.h"

/**
 * main - calls other functions
 * @argv: arguments
 * @argc: argument count
 *
 * Return: 0 or exit failure
 */
int main(int argc, char **argv)
{
	FILE *fpointer;
	void (*func)(stack_t **, unsigned int);
	char *buffer = NULL;
	size_t n, line_number = 1;
	/*stack_t *stack = NULL;*/
	/**head = NULL;*/

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fpointer = fopen(argv[1],  "r");

	if (fpointer == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &n, fpointer) != -1)
	{
		func = get_ops(buffer, line_number);
		if (func != NULL)
			func(&(bag.stack), line_number);
		line_number++;
	}
	free(buffer);
	fclose(fpointer);
	free_list(bag.stack);
	return (0);
}
