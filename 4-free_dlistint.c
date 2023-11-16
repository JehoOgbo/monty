#include "monty.h"

/**
 * free_list - frees a doubly linked list
 *
 * @tail: head node of the list
 * Return: void
 */
void free_list(stack_t *tail)
{
	stack_t *current;

	if (tail == NULL)
	{
		return;
	}

	while (tail->prev)
	{
		current = tail;
		tail = tail->prev;
		free(current);
	}
	free(tail);
}
