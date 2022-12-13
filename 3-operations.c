#include "header.h"
#include "global.h"

/**
 * add - add the top two elements of the stack
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the sum is stored in the second top element and the top
 *		element is removed making the stack shorter.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	b = new->prev->n;

	new->prev->n = a + b;
	*stack = new->prev;
	free(new);
}

/**
 * nop - this opcode doesn't do anything
 * @stack: pointer to the last element of the stack
 * @line_number: line number in the byte code
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	return;
}
