#include "monty.h"

/**
 * get_ops - gets the operation for the given op code
 * @s: the string which has the command
 * @l: line number in bytecode file
 *
 * Return: a pointer to the function corresponding to given command
 */
void (*get_ops(char *s, int l))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {"queue", queue},
		{"stack", stackd}, {NULL, NULL}
	};
	int i = 0, len;
	char **array;

	len = strlen(s);
	s[len - 1] = '\0';
	array = strtow(s);
	if (array == NULL)
		return (NULL);
	if (array[0][0] == '#')
	{
		free_array(array);
		return (NULL);
	}
	if (array[1])
	{
		if (is_numeric(array[1]) == 0)
			bag.holder = atoi(array[1]);
		else
			bag.holder = -78848;
	}
	else
		bag.holder = -78848;
	while (ops[i].opcode)
	{
		if (strcmp(array[0], ops[i].opcode) == 0)
		{
			free_array(array);
			return (ops[i].f);
		}
		i++;
	}
	bag.holder = -78848;
	dprintf(2, "L%d: unknown instruction %s\n", l, array[0]);
	free_list(bag.stack);
	free_array(array);
	exit(EXIT_FAILURE);
}
