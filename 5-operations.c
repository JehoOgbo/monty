#include "monty.h"

/**
 * mod - computes the rest of division of second top element by top element
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the sum is stored in the second top element and the top
 * element is removed making the stack shorter.
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	if (a == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	b = new->prev->n;

	new->prev->n = b % a;
	*stack = new->prev;
	free(new);
}

/**
 * pchar - prints the character at the top of the stack followed by a new line
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: prints the number as an ascii character. If not in ascii table
 * exit failure
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int a;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	if (a < 0 || a > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", a);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int a;
	stack_t *print = *stack;

	(void) line_number;
	while (print)
	{
		a = print->n;
		if (a < 1 || a > 127)
			break;
		putchar(a);
		print = print->prev;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the last elemtent of stack
 * @line_number: line number in the byte code
 *
 * Description: makes last element first one. others adjust accordingly
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack, *sec_to_last;

	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL)
		return;
	(void) line_number;
	sec_to_last = last->prev;
	sec_to_last->next = NULL;
	last->prev = NULL;
	last->next = bag.head;
	(bag.head)->prev = last;

	*stack = sec_to_last;
	bag.head = last;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: make the bottom of the stack the top, others adjust
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack, *second;

	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL)
		return;
	(void) line_number;
	second = (bag.head)->next;
	second->prev = NULL;
	(bag.head)->next = NULL;
	(bag.head)->prev = last;
	last->next = (bag.head);

	*stack = (bag.head);
	(bag.head) = second;
}
